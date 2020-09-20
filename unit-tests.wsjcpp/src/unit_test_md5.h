#ifndef UNIT_TEST_MD5_H
#define UNIT_TEST_MD5_H

#include <wsjcpp_unit_tests.h>

class UnitTestMd5 : public WsjcppUnitTestBase {
    public:
        UnitTestMd5();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_MD5_H
