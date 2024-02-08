#ifndef NTP_H
#define NTP_H

#include <stdint.h>

/*Offset between NTP and Unix time*/
#define NTP_EPOCH_OFFSET    ( (70UL * 365UL + 17UL) * 86400UL )

#define NTP_LEAP_INDICATOR_BIT_POSITION     6
#define NTP_VERSION_BIT_POSITION            3
#define NTP_MODE_BIT_POSITION               0
/* NTP Leap indicator warnings*/
typedef enum{
    NTP_NO_WARNING = 0,
    NTP_LAST_MINUTE_HAS_61_S,    
    NTP_LAST_MINUTE_HAS_59_S,    
    NTP_UNSYNCHRONIZED_MODE     
}leap_indicator_t;

typedef enum{
    NTP_VERSION_3 = 3,
    NTP_VERSION_4
}ntp_version_t;

/*NTP Modes*/
typedef enum{
    NTP_RESERVED = 0,
    NTP_SYMMETRIC_ACTIVE,
    NTP_SYMMETRIC_PASSIVE,
    NTP_CLIENT,
    NTP_SERVER,
    NTP_BROADCAST,
    NTP_NTP_CONTROL_MESSAGE,
    NTP_RESERVED_PRIVATE
}ntp_mode_t;

typedef struct __attribute__((packed)){
    uint32_t seconds;
    uint32_t fraction;
}ntpTimeFormat_t;

typedef struct __attribute__((packed)){
    uint8_t li_vn_mode;         // Leap Indicator, Version Number, Mode
    uint8_t stratum;            // Stratum
    uint8_t poll;              
    int8_t precision;           
    uint32_t rootDelay;        
    uint32_t rootDispersion;   
    uint32_t refID;   

    ntpTimeFormat_t refTimestamp;     
    ntpTimeFormat_t origTimestamp;    
    ntpTimeFormat_t rxTimestamp;    
    ntpTimeFormat_t txTimestamp;
}ntpHeader_t;

#endif // NTP_H