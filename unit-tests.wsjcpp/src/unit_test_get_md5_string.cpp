
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>
#include <wsjcpp_hashes.h>

// ---------------------------------------------------------------------
// UnitTestGetMd5String

class UnitTestGetMd5String : public WsjcppUnitTestBase {
    public:
        UnitTestGetMd5String();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestGetMd5String)

UnitTestGetMd5String::UnitTestGetMd5String()
    : WsjcppUnitTestBase("UnitTestGetMd5String") {
}

// ---------------------------------------------------------------------

bool UnitTestGetMd5String::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestGetMd5String::executeTest() {
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
        std::string sGotMd5 = WsjcppHashes::getMd5ByString(sOrig);
        sExpectedMd5 = WsjcppCore::toLower(sExpectedMd5);
        sGotMd5 = WsjcppCore::toLower(sGotMd5);
        compare("text '" + sOrig + "'", sGotMd5, sExpectedMd5);
    }
}

// ---------------------------------------------------------------------

bool UnitTestGetMd5String::doAfterTest() {
    // do somethig after test
    return true;
}


