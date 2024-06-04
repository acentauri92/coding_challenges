
#include "parse_args.h"
#include "string.h"

void init_params(input_params_t* input){
    input->connection_mode = CCNC_TCP_SERVER; /* By default TCP server*/
    input->listen_mode = 0;
    input->port = 0;
    input->scan_mode = 0;
    input->process_mode = 0;
    memset(input->process, 0, CCNC_PROCESS_NAME_LENGTH_MAX);
}

int parse_args(int argc, char* argv[], input_params_t* params){
    int option;
    init_params(params);

    while( (option = getopt(argc, argv, "lup:zxe:")) != -1 ){
        switch(option){
            case 'l':
                params->listen_mode = CCNC_LISTEN_MODE;
                break;

            case 'u':
                params->connection_mode = CCNC_UDP_SERVER;
                break;

            case 'p':
                int port = atoi(optarg);
                if( (port > 0) && (port < 65536)){
                    params->port = port;
                    break;
                }
                else{
                    fprintf(stderr, "Port %d invalid. Should be in range \
                            0 - 65535\n", port);
                    return CCNC_FAILURE;
                }

            case 'z':
                params->scan_mode = CCNC_PORT_TEST_MODE;
                break;

            case 'x':
                params->hex_dump_mode = CCNC_HEX_DUMP_MODE;
                break;

            case 'e':
                params->process_mode = CCNC_PROCESS_MODE;
                strncpy(params->process, optarg, strlen(optarg));
                break;

            default: /* ? */
                fprintf(stderr, "Usage: ./ccnc: [-l] [-u] [-p port]\n");
                return CCNC_FAILURE;
        }
    }
    return CCNC_SUCCESS;
}


