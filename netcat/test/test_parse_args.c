#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "parse_args.h"

input_params_t test_input;
extern int optind;
int test_argc;

static int setup(void **state) {
    test_argc = 3;
    optind = 1; /* Reset index to begin parsing again*/
    return 0;
}
 
static int teardown(void **state) {
    return 0;
}

static void test_init_params(void** state){
    init_params(&test_input);
    assert_int_equal(0, test_input.listen_mode);
    assert_int_equal(0, test_input.port);
    assert_int_equal(CCNC_TCP_SERVER, test_input.connection_mode);
    assert_int_equal(0, test_input.scan_mode);
    assert_int_equal(0, test_input.hex_dump_mode);
    assert_int_equal(0, test_input.process_mode);
    assert_string_equal(test_input.process, "");
}

static void test_parse_args_pass(void** state){
    char* test_argv[] = {"parse_args.c", "-l"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(CCNC_LISTEN_MODE, test_input.listen_mode);
}

static void test_parse_args_failure(void** state){
    char* test_argv[] = {"parse_args.c", "-d"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_FAILURE, status);
}

static void test_parse_args_udp(void** state){
    char* test_argv[] = {"parse_args.c", "-u"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(CCNC_UDP_SERVER, test_input.connection_mode);
}

static void test_parse_args_valid_port(void** state){
    char* port = "8080";
    char* test_argv[] = {"parse_args.c", "-p", port};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(8080, test_input.port);
}

static void test_parse_args_invalid_port_range(void** state){
    char* port = "70000";
    char* test_argv[] = {"parse_args.c", "-p", port};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_FAILURE, status);

}

static void test_parse_args_port_test(void** state){
    char* test_argv[] = {"parse_args.c", "-z"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(CCNC_PORT_TEST_MODE, test_input.scan_mode);
}

static void test_parse_args_hex(void** state){
    char* test_argv[] = {"parse_args.c", "-x"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(CCNC_HEX_DUMP_MODE, test_input.hex_dump_mode);
}

static void test_parse_process_mode(void** state){
    char* test_argv[] = {"parse_args.c", "-e", "/bin/bash"};
    int status = parse_args(test_argc, test_argv, &test_input);
    assert_int_equal(CCNC_SUCCESS, status);
    assert_int_equal(CCNC_PROCESS_MODE, test_input.process_mode);
    assert_string_equal("/bin/bash", test_input.process);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_params),
        cmocka_unit_test_setup_teardown(test_parse_args_pass, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_failure, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_udp, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_valid_port, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_invalid_port_range, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_port_test, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_args_hex, \
                                        setup, teardown),
        cmocka_unit_test_setup_teardown(test_parse_process_mode, \
                                        setup, teardown)                                            
        
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
