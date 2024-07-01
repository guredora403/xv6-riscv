// driver for virtio goldfish RTC

#include "types.h"

// base address
#define GOLDFISH_RTC_BASE 0x101000

//data offsets
#define RTC_TIME_LOW     0x00
#define RTC_TIME_HIGH    0x04


uint32 rtc_read(uint32 offset);
uint64 gettime(void);
