#include "unit_test_md5.h"
#include <vector>
#include <wsjcpp_hashes.h>

REGISTRY_UNIT_TEST(UnitTestMd5)


UnitTestMd5::UnitTestMd5()
    : UnitTestBase("UnitTestMd5") {
    //
}

void UnitTestMd5::init() {
    // nothing
}

bool UnitTestMd5::run() {

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
        std::string sMd5 = WSJCppHashes::md5_calc_hex(sOrig);
        WSJCppCore::to_lower(sExpectedMd5);
        WSJCppCore::to_lower(sMd5);
        if (sExpectedMd5 == sMd5) {
            nSuccess++;
        } else {
            WSJCppLog::err(TAG, "Expected '" + sExpectedMd5 + "', but got '" + sMd5 + "' for '" + sOrig + "'");
        }
    }
    return nSuccess == tests.size();
}

