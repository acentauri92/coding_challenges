extern "C"{
  #include "hcomp.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(hcomp)
{
    void setup()
    {
    }

    void teardown()
    {

    }
};


TEST(hcomp, test)
{
  LONGS_EQUAL(0, 0);
}
