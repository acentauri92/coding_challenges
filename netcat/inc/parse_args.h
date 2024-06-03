#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CCNC_SUCCESS            0
#define CCNC_FAILURE            -1

#define CCNC_LISTEN_MODE        1

#define CCNC_TCP_SERVER         10
#define CCNC_UDP_SERVER         20

typedef struct{
    int listen_mode;
    int port;
    int connection_mode;
    int port_test_mode;
}input_params_t;

extern char* optarg;

void init_params(input_params_t* input);
int parse_args(int argc, char* argv[], input_params_t* params);

#endif // PARSE_ARGS_H