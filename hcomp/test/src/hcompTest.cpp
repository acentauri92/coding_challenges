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


TEST(parse_options, test_params_struct_zero)
{

	int argc =2;
	char* argv[] = {"-a"};
	
	char expected[PATH_MAX] = {0};

	parse_options(argc, argv);

	MEMCMP_EQUAL(expected, input_params.input_file, PATH_MAX);
	MEMCMP_EQUAL(expected, input_params.output_file, PATH_MAX);
}


TEST(parse_options, test_no_params)
{

	int argc =1;
	char** argv = NULL;

	LONGS_EQUAL(-1, parse_options(argc, argv));
}
	

TEST(parse_options, test_input)
{

	int argc = 3;
	char* argv[] = {"-i", "test"};

	parse_options(argc, argv);

	printf("%s", input_params.input_file);
	STRCMP_EQUAL("test", input_params.input_file);
}
