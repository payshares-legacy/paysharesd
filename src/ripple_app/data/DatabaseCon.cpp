//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

namespace ripple {


void DatabaseCon::connectHelper(const std::string& strName)
{
    // VFALCO TODO remove this dependency on the config by making it the caller's
    //         responsibility to pass in the path. Add a member function to Application
    //         or Config to compute this path.
    //
    boost::filesystem::path pPath   = (getConfig ().RUN_STANDALONE &&
                                          ((getConfig ().START_UP != Config::LOAD) &&
                                           (getConfig ().START_UP != Config::REPLAY) &&
                                           (getConfig ().START_UP != Config::FRESH)))
                                      ? ""                                // Use temporary files.
                                      : (getConfig ().DATA_DIR / strName);       // Use regular db files.

    mDatabase = new SqliteDatabase (pPath.string ().c_str ());
    mDatabase->connect ();
}

DatabaseCon::DatabaseCon (const std::string& strName, const char* initStrings[], int initCount)
{
    connectHelper(strName);
    for (int i = 0; i < initCount; ++i) {
        bool res = mDatabase->executeSQL (initStrings[i], false);
        assert(res);
    }
}

DatabaseCon::DatabaseCon (const std::string& strName, const std::vector<const char *> &init)
{
    connectHelper(strName);

    for(const char * const &statement: init) {
        bool res = mDatabase->executeSQL (statement, false);
        assert(res);
    }
}

DatabaseCon::~DatabaseCon ()
{
    mDatabase->disconnect ();
    delete mDatabase;
}

} // ripple
