#include "unit_test_sha1.h"
#include <vector>
#include <wsjcpp_hashes.h>

REGISTRY_UNIT_TEST(UnitTestSha1)


UnitTestSha1::UnitTestSha1()
    : WsjcppUnitTestBase("UnitTestSha1") {
    //
}

void UnitTestSha1::init() {
    // nothing
}

bool UnitTestSha1::run() {
    bool bTestSuccess = true;

    struct Sha1Test {
        Sha1Test(std::string sOrig, std::string sExpectedSha1) : sOrig(sOrig), sExpectedSha1(sExpectedSha1) {}
        std::string sOrig;
        std::string sExpectedSha1;
    };

    std::vector<Sha1Test *> tests;
    tests.push_back(new Sha1Test("test", "a94a8fe5ccb19ba61c4c0873d391e987982fbbd3"));
    tests.push_back(new Sha1Test("admin", "d033e22ae348aeb5660fc2140aec35850c4da997"));

    unsigned int nSuccess = 0;
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::string sOriginal = tests[i]->sOrig;
        std::string sExpectedSha1 = tests[i]->sExpectedSha1;
        std::string sGotSha1 = WsjcppHashes::sha1_calc_hex(sOriginal);
        sExpectedSha1 = WsjcppCore::toLower(sExpectedSha1);
        sGotSha1 = WsjcppCore::toLower(sGotSha1);
        compareS(bTestSuccess, "text '" + sOriginal + "'", sGotSha1, sExpectedSha1);
    }
    return bTestSuccess;
}

