// driver for virtio goldfish RTC

#include "types.h"


//data offsets
#define RTC_TIME_LOW     0x00
#define RTC_TIME_HIGH    0x04


uint32 rtc_read(int offset);
uint64 gettime(void);
