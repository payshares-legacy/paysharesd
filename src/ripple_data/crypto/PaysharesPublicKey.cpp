#include "PaysharesPublicKey.h"
#include <sodium.h>
#include "../ripple/sslutil/api/HashUtilities.h"

namespace ripple
{

	PaysharesPublicKey::PaysharesPublicKey()
	{
		mIsValid = false;
	}

	PaysharesPublicKey::PaysharesPublicKey(const Blob& publicKey, RippleAddress::VersionEncoding type)
	{
		SetData(type, publicKey);
	}

	PaysharesPublicKey::PaysharesPublicKey(const std::string& base58Key, RippleAddress::VersionEncoding type)
	{
		setKey(base58Key, type);
	}

	bool PaysharesPublicKey::setKey(const std::string& base58Key, RippleAddress::VersionEncoding type)
	{
		mIsValid = SetString(base58Key, RippleAddress::VER_NODE_PUBLIC, Base58::getRippleAlphabet());
		return(mIsValid);
	}

	// JED: seems like we shouldn't need this
	void PaysharesPublicKey::clear()
	{
		nVersion = RippleAddress::VER_NONE;
		vchData.clear();
		mIsValid = false;
	}

	uint160 PaysharesPublicKey::getAccountID() const
	{
		return Hash160(vchData);
	}

	// create accountID from this seed and base58 encode it
	std::string PaysharesPublicKey::base58AccountID() const
	{
		uint160 account = getAccountID();

		Blob vch(1, RippleAddress::VER_ACCOUNT_ID);

		vch.insert(vch.end(), account.begin(), account.end());

		return Base58::encodeWithCheck(vch);

	}

	std::string PaysharesPublicKey::base58Key() const
	{
		return(ToString());
	}


	bool PaysharesPublicKey::verifySignature(uint256 const& hash, const std::string& strSig) const
	{
		Blob vchSig(strSig.begin(), strSig.end());
		return(verifySignature(hash, vchSig));
	}

    bool PaysharesPublicKey::verifySignature(uint256 const& hash, Blob const& vchSig) const
    {
        if (vchData.size() != crypto_sign_PUBLICKEYBYTES
            || vchSig.size() != crypto_sign_BYTES)
            throw std::runtime_error("bad inputs to verifySignature");

    bool verified = crypto_sign_verify_detached(vchSig.data(),
                 hash.data(), hash.bytes, vchData.data()) == 0;
    bool canonical = RippleAddress::signatureIsCanonical (vchSig);
    return verified && canonical;
    }
}
