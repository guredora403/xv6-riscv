#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "spinlock.h"
#include "param.h"
#include "proc.h"

uint64 sys_getopening(){
    struct proc *p = myproc();
    uint64 ops = 0;
    for(int i = 0; i <= 15; i++){
        if(p->ofile[i]){
            int b = 1;
            ops |= b << i;
        }
    }
    return ops;
}
