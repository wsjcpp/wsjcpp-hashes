#include "unit_test_md5.h"
#include <vector>
#include <wsjcpp_hashes.h>

REGISTRY_UNIT_TEST(UnitTestMd5)


UnitTestMd5::UnitTestMd5()
    : WsjcppUnitTestBase("UnitTestMd5") {
    //
}

void UnitTestMd5::init() {
    // nothing
}

bool UnitTestMd5::run() {
    bool bTestSuccess = true;
    struct Md5Test {
        Md5Test(std::string sOrig, std::string sExpectedMd5) : sOrig(sOrig), sExpectedMd5(sExpectedMd5) {}
        std::string sOrig;
        std::string sExpectedMd5;
    };

    std::vector<Md5Test *> tests;
    tests.push_back(new Md5Test("test", "098F6BCD4621D373CADE4E832627B4F6"));
    tests.push_back(new Md5Test("admin", "21232F297A57A5A743894A0E4A801FC3"));

    unsigned int nSuccess = 0;
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::string sOrig = tests[i]->sOrig;
        std::string sExpectedMd5 = tests[i]->sExpectedMd5;
        std::string sGotMd5 = WsjcppHashes::md5_calc_hex(sOrig);
        sExpectedMd5 = WsjcppCore::toLower(sExpectedMd5);
        sGotMd5 = WsjcppCore::toLower(sGotMd5);
        compareS(bTestSuccess, "text '" + sOrig + "'", sGotMd5, sExpectedMd5);
    }
    return bTestSuccess;
}

