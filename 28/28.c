#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <stdarg.h>

int Printf(const char *Format, ...) {
    static int (*OriginalPrintf)(const char *, ...) = NULL;
    if (!OriginalPrintf) OriginalPrintf = dlsym(RTLD_NEXT, "printf");

    va_list Args;
    va_start(Args, Format);
    int Result = OriginalPrintf("[Hooked] ");
    Result += vprintf(Format, Args);
    va_end(Args);
    return Result;
}
