
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>
#include <wsjcpp_hashes.h>

// ---------------------------------------------------------------------
// UnitTestGetSha1String

class UnitTestGetSha1String : public WsjcppUnitTestBase {
    public:
        UnitTestGetSha1String();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestGetSha1String)

UnitTestGetSha1String::UnitTestGetSha1String()
    : WsjcppUnitTestBase("UnitTestGetSha1String") {
}

// ---------------------------------------------------------------------

bool UnitTestGetSha1String::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestGetSha1String::executeTest() {
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
        std::string sGotSha1 = WsjcppHashes::getSha1ByString(sOriginal);
        sExpectedSha1 = WsjcppCore::toLower(sExpectedSha1);
        sGotSha1 = WsjcppCore::toLower(sGotSha1);
        compare("text '" + sOriginal + "'", sGotSha1, sExpectedSha1);
    }
}

// ---------------------------------------------------------------------

bool UnitTestGetSha1String::doAfterTest() {
    // do somethig after test
    return true;
}


