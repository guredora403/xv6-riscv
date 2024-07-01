#Include "types.h"
#include "rtc.h"

uint32 rtc_read(uint32 offset){
    return *(volatile uint32*)(GOLDFISH_RTC_BASE + offset);
}

uint64 gettime(void){
    uint32 low = rtc_read(RTC_TIME_LOW);
    uint32 high = rtc_read(RTC_TIME_HIGH);
    return ((uint64)high << 32) | low;
}

uint64 sys_gettime(void){
    return gettime();
}
