#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define CCNC_SUCCESS            0
#define CCNC_FAILURE            -1

#define CCNC_LISTEN_MODE        1

#define CCNC_TCP_SERVER         10
#define CCNC_UDP_SERVER         20

#define CCNC_PORT_TEST_MODE     30
#define CCNC_HEX_DUMP_MODE      40
#define CCNC_PROCESS_MODE       50

/* TODO: Better name for process mode */
#define CCNC_PROCESS_NAME_LENGTH_MAX     255

typedef struct{
    uint8_t listen_mode;
    uint16_t port;
    uint8_t connection_mode;
    uint8_t scan_mode;
    uint8_t hex_dump_mode;
    uint8_t process_mode;
    char process[CCNC_PROCESS_NAME_LENGTH_MAX];
}input_params_t;

/* External variables used by getopt*/
extern char* optarg;
extern int optind;
extern int opterr;
extern int optopt;

void init_params(input_params_t* input);
int parse_args(int argc, char* argv[], input_params_t* params);

#endif // PARSE_ARGS_H