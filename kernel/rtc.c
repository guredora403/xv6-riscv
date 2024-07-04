#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"
#include "rtc.h"

uint32 rtc_read(int offset){
    volatile uint32 *ptr = (uint32*)(GOLDFISH_RTC0 + offset);
    return *ptr;
}

uint64 gettime(void){
    uint32 low = rtc_read(RTC_TIME_LOW);
    uint32 high = rtc_read(RTC_TIME_HIGH);
    return (((uint64)high << 32) | low) / 1000000000;
}

uint64 sys_gettime(void){
    return gettime();
}
