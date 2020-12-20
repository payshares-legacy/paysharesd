![Payshares](/assets/payshares.jpg)

Payshares is an open source protocol for exchange, payments, and remittance forged by Kedia.  Its base components include an open distributed ledger system and native currency payshare units known as XPS.  The Payshares Platform enhances the cryptocurrency industry with near instant extremely low cost transactions with great risk reduction for all participants.

The Payshares Ledger holds all account information, transactions, and offers available on the network.  Participants on the network are able to reach consensus in average of one to five seconds.  Consensus allows for the network to operate in a distributed fashion.

Everyone is able to participate and contribute computational power to the network on standard hardware.  Standard Servers reduce storage requirements by maintaining a recent snapshot of the ledger.  Trusted Nodes such as those in operation by Kedia will maintain the full ledger.

paysharesd - Payshares P2P server
=================================

[![Build Status](https://travis-ci.org/Payshares/paysharesd.svg?branch=master)](https://travis-ci.org/Payshares/paysharesd)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/09542ea53aae4c3ba0559cd0dc2a8186)](https://www.codacy.com/gh/payshares-legacy/paysharesd/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=payshares-legacy/paysharesd&amp;utm_campaign=Badge_Grade)

This is the repository for Payshares's `paysharesd`, reference P2P server.

Build instructions:
-------------------

* https://github.com/payshares/paysharesd/blob/master/doc/building-paysharesd.md


Repository Contents
-------------------

./bin
-----
Scripts and data files for Payshares integrators.

./build
-------
Intermediate and final build outputs.

./Builds
--------
Platform or IDE-specific project files.

./doc
-----
Documentation and example configuration files.

./src
-----
Source code directory. Some of the directories contained here are
external repositories inlined via git-subtree, see the corresponding
README for more details.

./test
------
Javascript / Mocha tests.

Running tests
-------------
mocha test/*-test.js


License
-------
Payshares is open source and permissively licensed under the ISC license. See the
LICENSE file for more details.

For more information:
---------------------
* https://payshares.org
* https://twitter.com/payshares
* https://business.facebook.com/payshares
* https://reddit.com/r/payshares
* https://t.me/payshares
* https://t.me/paysharestalk

Payshares Genesis Ledger:
-------------------------

~~~
{
   "result" : {
      "ledger" : {
         "accepted" : true,
         "account_hash" : "CD61677B53191E1FDCA8861E68B11688B86260A5DE55429942FB79EE3D066BCF",
         "close_time" : 559688910,
         "close_time_human" : "2017-Sep-25 21:08:30",
         "close_time_resolution" : 30,
         "closed" : true,
         "fee_pool" : "0",
         "hash" : "F5524981DB75D730771449FAEF7ED46F621193638F96B2DDAFF456B7925EE46A",
         "inflate_seq" : "1",
         "ledger_hash" : "F5524981DB75D730771449FAEF7ED46F621193638F96B2DDAFF456B7925EE46A",
         "ledger_index" : "1",
         "parent_hash" : "0000000000000000000000000000000000000000000000000000000000000000",
         "seqNum" : "1",
         "totalCoins" : "100000000000000000",
         "total_coins" : "100000000000000000",
         "transaction_hash" : "0000000000000000000000000000000000000000000000000000000000000000"
      },
      "status" : "success"
   }
}
~~~
