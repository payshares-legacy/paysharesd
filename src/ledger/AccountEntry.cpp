#include <boost/format.hpp>
#include "AccountEntry.h"
#include "LedgerMaster.h"
#include "ripple_app/data/DatabaseCon.h"
#include "ripple_app/main/Application.h"
#include "ripple_basics/log/Log.h"
#include "ripple_app/ledger/Ledger.h"

namespace payshares
{

    void AccountEntry::appendSQLInit(vector<const char*> &init)
    {
        init.push_back("CREATE TABLE IF NOT EXISTS Accounts (   \
            accountID       CHARACTER(35) PRIMARY KEY,          \
            balance         BIGINT UNSIGNED,                    \
            sequence        INT UNSIGNED,                       \
            ownerCount      INT UNSIGNED,                       \
            transferRate    INT UNSIGNED,                       \
            inflationDest   CHARACTER(35),                      \
            publicKey       CHARACTER(56),                      \
            requireDest     BOOL,                               \
            requireAuth     BOOL                                \
        ); ");

        init.push_back("CREATE INDEX IF NOT EXISTS inflationDest ON Accounts ( InflationDest );");

        init.push_back("CREATE INDEX IF NOT EXISTS Balance on Accounts ( balance );");
    }

    AccountEntry::AccountEntry(SLE::pointer sle)
    {
        mAccountID = sle->getFieldAccount160(sfAccount);
        mBalance = sle->getFieldAmount(sfBalance).getNValue();
        mSequence = sle->getFieldU32(sfSequence);
        mOwnerCount = sle->getFieldU32(sfOwnerCount);
        if (sle->isFieldPresent(sfTransferRate))
            mTransferRate = sle->getFieldU32(sfTransferRate);
        else mTransferRate = 0;

        if (sle->isFieldPresent(sfInflationDest))
            mInflationDest = sle->getFieldAccount160(sfInflationDest);

        uint32 flags = sle->getFlags();

        mRequireDest = flags & lsfRequireDestTag;
        mRequireAuth = flags & lsfRequireAuth;

    }

    void AccountEntry::calculateIndex()
    {
        Serializer  s(22);

        s.add16(spaceAccount); //  2
        s.add160(mAccountID);  // 20

        mIndex = s.getSHA512Half();
    }

    void  AccountEntry::insertIntoDB()
    {
        string sql = str(boost::format("INSERT OR REPLACE INTO Accounts ("
            "accountID,balance,sequence,ownerCount,transferRate,"
            "inflationDest,publicKey,requireDest,requireAuth) values ('%s',%d,%d,%d,%d,'%s','%s',%d,%d);")
            % mAccountID.base58Encode(RippleAddress::VER_ACCOUNT_ID)
            % mBalance
            % mSequence
            % mOwnerCount
            % mTransferRate
            % mInflationDest.base58Encode(RippleAddress::VER_ACCOUNT_ID)
            % mPubKey.base58Key()
            % mRequireDest
            % mRequireAuth);

        Database* db = getApp().getWorkingLedgerDB()->getDB();

        if (!db->executeSQL(sql, false))
        {
            WriteLog(lsWARNING, ripple::Ledger) << "SQL failed: " << sql;
        }
    }
    void AccountEntry::updateInDB()
    {
        string sql = str(boost::format("UPDATE Accounts set "
            "balance=%d, sequence=%d,ownerCount=%d,transferRate=%d,"
            "inflationDest='%s',publicKey='%s',requireDest=%d,requireAuth=%d where accountID='%s';")
            % mBalance
            % mSequence
            % mOwnerCount
            % mTransferRate
            % mInflationDest.base58Encode(RippleAddress::VER_ACCOUNT_ID)
            % mPubKey.base58Key()
            % mRequireDest
            % mRequireAuth
            % mAccountID.base58Encode(RippleAddress::VER_ACCOUNT_ID));

        Database* db = getApp().getWorkingLedgerDB()->getDB();

        if (!db->executeSQL(sql, false))
        {
            WriteLog(lsWARNING, ripple::Ledger) << "SQL failed: " << sql;
        }
    }
    void AccountEntry::deleteFromDB()
    {
        string sql = str(boost::format("DELETE from Accounts where accountID='%s';")
            % mAccountID.base58Encode(RippleAddress::VER_ACCOUNT_ID));

        Database* db = getApp().getWorkingLedgerDB()->getDB();

        if (!db->executeSQL(sql, false))
        {
            WriteLog(lsWARNING, ripple::Ledger) << "SQL failed: " << sql;
        }
    }

    void AccountEntry::dropAll(LedgerDatabase &db)
    {
        if (!db.getDBCon()->getDB()->executeSQL("DROP TABLE IF EXISTS Accounts;"))
        {
            throw std::runtime_error("Could not drop Account data");
        }
    }
}

