
#include <wsjcpp_core.h>
#include <wsjcpp_unit_tests.h>
#include <wsjcpp_hashes.h>

// ---------------------------------------------------------------------
// UnitTestGetMd5File

class UnitTestGetMd5File : public WsjcppUnitTestBase {
    public:
        UnitTestGetMd5File();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestGetMd5File)

UnitTestGetMd5File::UnitTestGetMd5File()
    : WsjcppUnitTestBase("UnitTestGetMd5File") {
}

// ---------------------------------------------------------------------

bool UnitTestGetMd5File::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestGetMd5File::executeTest() {
    struct Md5Test {
        Md5Test(std::string sFile, std::string sExpectedMd5) : sFile(sFile), sExpectedMd5(sExpectedMd5) {}
        std::string sFile;
        std::string sExpectedMd5;
    };

    std::vector<Md5Test *> tests;
    tests.push_back(new Md5Test("data/test_file0", "2ceadcd1a95ddea67516c36fc75a5218"));
    tests.push_back(new Md5Test("data/test_file1", "d2066ac59c5a0a153836c2a9c1fb1901"));

    unsigned int nSuccess = 0;
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::string sFile = tests[i]->sFile;
        std::string sExpectedMd5 = tests[i]->sExpectedMd5;
        std::string sGotMd5 = WsjcppHashes::getMd5ByFile(sFile);
        sExpectedMd5 = WsjcppCore::toLower(sExpectedMd5);
        sGotMd5 = WsjcppCore::toLower(sGotMd5);
        compare("text '" + sFile + "'", sGotMd5, sExpectedMd5);
    }
}

// ---------------------------------------------------------------------

bool UnitTestGetMd5File::doAfterTest() {
    // do somethig after test
    return true;
}


