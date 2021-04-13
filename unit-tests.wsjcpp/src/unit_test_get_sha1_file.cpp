
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>
#include <wsjcpp_hashes.h>

// ---------------------------------------------------------------------
// UnitTestGetSha1File

class UnitTestGetSha1File : public WsjcppUnitTestBase {
    public:
        UnitTestGetSha1File();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestGetSha1File)

UnitTestGetSha1File::UnitTestGetSha1File()
    : WsjcppUnitTestBase("UnitTestGetSha1File") {
}

// ---------------------------------------------------------------------

bool UnitTestGetSha1File::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestGetSha1File::executeTest() {
    struct Sha1Test {
        Sha1Test(std::string sFile, std::string sExpectedSha1) : sFile(sFile), sExpectedSha1(sExpectedSha1) {}
        std::string sFile;
        std::string sExpectedSha1;
    };

    std::vector<Sha1Test *> tests;
    tests.push_back(new Sha1Test("data/test_file0", "7093e61cecfcf8ae864d1c56a52f6d04f6f4e94c"));
    tests.push_back(new Sha1Test("data/test_file1", "899cb945a21da884413a5e952650ae35c4ad06d8"));

    unsigned int nSuccess = 0;
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::string sOriginal = tests[i]->sFile;
        std::string sExpectedSha1 = tests[i]->sExpectedSha1;
        std::string sGotSha1 = WsjcppHashes::getSha1ByFile(sOriginal);
        sExpectedSha1 = WsjcppCore::toLower(sExpectedSha1);
        sGotSha1 = WsjcppCore::toLower(sGotSha1);
        compare("text '" + sOriginal + "'", sGotSha1, sExpectedSha1);
    }
}

// ---------------------------------------------------------------------

bool UnitTestGetSha1File::doAfterTest() {
    // do somethig after test
    return true;
}


