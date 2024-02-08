#include <stdio.h>
#include "ntp.h"
#include <sys/time.h>

ntpHeader_t ntpHeader;

struct timeval time;

static void timevalToNtp(struct timeval* tv, ntpTimeFormat_t* ntptimeformat);
static void ntp_to_timeval(struct timeval* tv, ntpTimeFormat_t* ntptimeformat);

int main(void){


    gettimeofday(&time, NULL);

    printf("tvsec: %ld\n", time.tv_sec);
    printf("tv usec: %ld\n", time.tv_usec);

    /* Set the first 8 bits of the header*/
    ntpHeader.li_vn_mode |= NTP_UNSYNCHRONIZED_MODE << NTP_LEAP_INDICATOR_BIT_POSITION;
    ntpHeader.li_vn_mode |= NTP_VERSION_4 << NTP_VERSION_BIT_POSITION;
    ntpHeader.li_vn_mode |= NTP_CLIENT << NTP_MODE_BIT_POSITION;

    timevalToNtp(&time, &(ntpHeader.origTimestamp));

    printf("ntp time format(s): %u\n", ntpHeader.origTimestamp.seconds);
    printf("ntp time format(ns): %u\n", ntpHeader.origTimestamp.fraction);

}

static void timevalToNtp(struct timeval* tv, ntpTimeFormat_t* ntptimeformat){
    ntptimeformat->seconds = tv->tv_sec + NTP_EPOCH_OFFSET;
       
    ntptimeformat->fraction = (uint32_t)((double)(tv->tv_usec + 1) * \
                            (double)(1LL << 32) * 1.0e-6);
}

static void ntp_to_timeval(struct timeval* tv, ntpTimeFormat_t* ntptimeformat){
    tv->tv_sec = ntptimeformat->seconds - 2208988800;
    tv->tv_usec = (uint32_t)((double)ntptimeformat->fraction * 1.0e6 / \
                    (double)(1LL << 32));
}
 