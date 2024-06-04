#include "parse_args.h"

int main(int argc, char* argv[]) {
    input_params_t params;
    parse_args(argc, argv, &params);
    return 0;
}
