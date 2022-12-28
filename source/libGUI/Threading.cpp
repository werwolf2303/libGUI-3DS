#include <3ds.h>
#include <string.h>
#include <stdio.h>

#define STACKSIZE (4 * 1024)

bool s = false;
void* m = NULL;
void run(void* arg) {
    u64 sleepDuration = 1000000ULL * (u32)1;
    while (!s)
    {
        m;
        svcSleepThread(sleepDuration);
    }
}

class Threading {
    public:
    volatile bool r = false;
    Thread thread;
    s32 p = 0;
    Threading() {
        svcGetThreadPriority(&p, CUR_THREAD_HANDLE);
    }
    void setThreadVoid(void* method) {
        m = method;
    }
    void start() {
        r = true;
        s = false;
        thread = threadCreate(run, 0, STACKSIZE, p-1, -2, false);
    }
    void stop() {
        s = true;
        threadJoin(thread, U64_MAX);
		threadFree(thread);
        r = false;
    }

};