#include <string.h>
#include <iostream>
#include <algorithm>
#include "wsjcpp_hashes.h"

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);

    std::string sSource = "some123";
    std::string sSha1 = WsjcppHashes::sha1_calc_hex(sSource);
    std::string sMd5 = WsjcppHashes::md5_calc_hex(sSource);
    std::cout << "sha1('" << sSource << "') = " << sSha1 << std::endl;
    std::cout << "md5('" << sSource << "') = " << sMd5 << std::endl;

    return 0;
}