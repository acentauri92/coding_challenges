
#include "parse_args.h"

void init_params(input_params_t* input){
    input->connection_mode = CCNC_TCP_SERVER; /* By default TCP server*/
    input->listen_mode = 0;
    input->port = 0;
}

int parse_args(int argc, char* argv[], input_params_t* params){
    int option;
    init_params(params);

    while( (option = getopt(argc, argv, "lup:z")) != -1 ){
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

            default: /* ? */
                fprintf(stderr, "./ccnc: [-l] [-u] [-p port]\n");
                return CCNC_FAILURE;
        }
    }
    return CCNC_SUCCESS;
}


