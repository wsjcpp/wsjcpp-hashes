#ifndef UNIT_TEST_SHA1_H
#define UNIT_TEST_SHA1_H

#include <wsjcpp_unit_tests.h>

class UnitTestSha1 : public WsjcppUnitTestBase {
    public:
        UnitTestSha1();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_SHA1_H
