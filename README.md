# wsjcpp-hashes

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-hashes.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-hashes) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-hashes.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-hashes/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-hashes.svg)](https://github.com/wsjcpp/wsjcpp-hashes/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-hashes.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-hashes/network/members) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/wsjcpp-hashes.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-hashes/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/wsjcpp-hashes.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-hashes/context:cpp) [![deepcode](https://www.deepcode.ai/api/gh/badge?key=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJwbGF0Zm9ybTEiOiJnaCIsIm93bmVyMSI6IndzamNwcCIsInJlcG8xIjoid3NqY3BwLWhhc2hlcyIsImF1dGhvcklkIjoxNTY0MSwiaWF0IjoxNjMwMTU1NjMxfQ.PZSjl4jX2h5xQVF9Phtd02BJNG4A_IrvGy2zxUNtlFE)](https://www.deepcode.ai/app/gh/wsjcpp/wsjcpp-hashes/_/dashboard?utm_content=gh%2Fwsjcpp%2Fwsjcpp-hashes)


## Intagrate to your project

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-hashes:master
```

or include this files:

* src.wsjcpp/wsjcpp_core/wsjcpp_core.h
* src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp
* src/md5.cpp
* src/md5.h
* src/smallsha1.cpp
* src/smallsha1.h
* src/wsjcpp_hashes.h
* src/wsjcpp_hashes.cpp


## Usage

```
#include <wsjcpp_hashes.h>

void main() {
    std::string sSource = "some123";
    std::string sSha1 = WsjcppHashes::sha1_calc_hex(sSource);
    std::string sMd5 = WsjcppHashes::md5_calc_hex(sSource);
    std::cout << "sha1('" << sSource << "') = " << sSha1 << std::endl;
    std::cout << "md5('" << sSource << "') = " << sMd5 << std::endl;
}
```

example output:
```
sha1('some123') = 1225f79dee075a65ca92df080106ab40d15e5ba1
md5('some123') = 302d62e9451df39a97f73dec7f9272ef
```
