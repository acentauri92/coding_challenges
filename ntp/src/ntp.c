#include <stdio.h>
#include "ntp.h"
#include <sys/time.h>

ntpHeader_t ntpHeader;

struct timeval time;

int main(void){


    gettimeofday(&time, NULL);

    printf("tvsec: %ld\n", time.tv_sec);
    printf("tv usec: %ld\n", time.tv_usec);


    // ntpHeader.li_vn_mode |= UNSYNCHRONIZED_MODE << 6;
    // ntpHeader.li_vn_mode |= 4 << 3;


    // printf("Value of li: %u\n", ntpHeader.li_vn_mode);

}