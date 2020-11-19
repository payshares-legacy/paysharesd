![Payshares](/assets/payshares.jpg)

Payshares is an open source protocol for exchange, payments, and remittance forged by Kedia.  Its base components include an open distributed ledger system and native currency payshare units known as XPS.  The Payshares Platform enhances the cryptocurrency industry with near instant extremely low cost transactions with great risk reduction for all participants.

The Payshares Ledger holds all account information, transactions, and offers available on the network.  Participants on the network are able to reach consensus in average of one to five seconds.  Consensus allows for the network to operate in a distributed fashion.

Everyone is able to participate and contribute computational power to the network on standard hardware.  Standard Servers reduce storage requirements by maintaining a recent snapshot of the ledger.  Trusted Nodes such as those in operation by Kedia will maintain the full ledger.

Every feature currently available in its competitors is also currently available for Payshares.  Unique to Payshares is the expansion capabilities of its distributed exchange, opening up asset management opportunities previously only achievable by centralized financial systems.

paysharesd - Payshares P2P server
=================================

[![Build Status](https://travis-ci.org/Payshares/paysharesd.svg?branch=master)](https://travis-ci.org/Payshares/paysharesd)

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
