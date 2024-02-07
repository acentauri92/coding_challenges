#ifndef NTP_H
#define NTP_H
#include <stdint.h>

typedef enum{
    NO_WARNING = 0,
    LAST_MINUTE_HAS_61_S,    
    LAST_MINUTE_HAS_59_S,    
    UNSYNCHRONIZED_MODE     
}leap_indicator_t;

typedef struct {
    uint8_t li_vn_mode;         // Leap Indicator, Version Number, Mode
    uint8_t stratum;            // Stratum
    uint8_t poll;              
    int8_t precision;           
    uint32_t rootDelay;        
    uint32_t rootDispersion;   
    uint32_t refID;           
    uint64_t refTimestamp;     
    uint64_t origTimestamp;    
    uint64_t rxTimestamp;    
    uint64_t txTimestamp;
}ntpHeader_t;



#endif