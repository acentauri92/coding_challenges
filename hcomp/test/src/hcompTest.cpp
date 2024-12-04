extern "C"{
  #include "parse.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(parse_options)
{
    void setup()
    {
    }

    void teardown()
    {

    }
};


TEST(parse_options, test_params_zero)
{

	int argc =2;
	char* argv[] = {"-a"};
	
	char expected[PATH_MAX] = {0};

	parse_options(argc, argv);

	MEMCMP_EQUAL(expected, input_params.input_file, PATH_MAX);
	MEMCMP_EQUAL(expected, input_params.output_file, PATH_MAX);
}
