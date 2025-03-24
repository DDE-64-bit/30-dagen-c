#include <stdio.h>
#include <stdarg.h>

void simplePrintf(const char *formatString, ...)
{
    va_list argList;
    va_start(argList, formatString);

    while (*formatString)
    {
        if (*formatString == '%')
        {
            formatString++;
            switch (*formatString)
            {
                case 'd':
                {
                    int intValue = va_arg(argList, int);
                    printf("%d", intValue);
                    break;
                }
                case 'c':
                {
                    int charValue = va_arg(argList, int); // chars are promoted to int intValuen varargList
                    putchar(charValue);
                    break;
                }
                case 's':
                {
                    char *stringValue = va_arg(argList, char *);
                    printf("%s", stringValue);
                    break;
                }
                default:
                    putchar('%');
                    putchar(*formatString);
            }
        }
        else
        {
            putchar(*formatString);
        }
        formatString++;
    }

    va_end(argList);
}

int main()
{
    simplePrintf("Hello %s! Jouw score is een %d.\n", "World", 95);
    return 0;
}
