#paysharesd - Payshares P2P server
[![Build Status](https://travis-ci.org/payshares/paysharesd.svg?branch=master)](https://travis-ci.org/Payshares/paysharesd)

This is the repository for Payshares's `paysharesd`, reference P2P server.

###Build instructions:
* https://github.com/payshares/paysharesd/blob/master/doc/building-paysharesd.md

### Vagrant (your very own testnet)

1.  Install vagrant (http://www.vagrantup.com/)
2.  run `vagrant up`
3.  There is no step 3.

You now have a running testnet accessible on ports 9001 (websocket) and 9002 (rpc).  It will not connect to other instances and will have it's own ledger set.

NOTE: running `vagrant provision` will reset your ledger, starting you over from scratch

### Repository Contents

#### ./bin
Scripts and data files for Payshares integrators.

#### ./build
Intermediate and final build outputs.

#### ./Builds
Platform or IDE-specific project files.

#### ./doc
Documentation and example configuration files.

#### ./src
Source code directory. Some of the directories contained here are
external repositories inlined via git-subtree, see the corresponding
README for more details.

#### ./test
Javascript / Mocha tests.

#### Running tests
mocha test/*-test.js


## License
Payshares is open source and permissively licensed under the ISC license. See the
LICENSE file for more details.

### For more information:
* https://www.payshares.org
* https://www.payshares.org/developers/
