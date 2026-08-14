#include "logger.h"
#include <stdarg.h>
#include <time.h>
#include <string.h>

static const char *get_time()
{
    static char buf[20];
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buf, sizeof(buf), "%H:%M:%S", tm_info);
    return buf;
}

void log_write(int level, const char *level_str,
               const char *file, int line,
               const char *func, const char *fmt, ...)
{
    FILE *fp = stdout;
    (void)level;

#if LOG_OUTPUT_TARGET == LOG_OUTPUT_FILE
    static FILE *fileptr = NULL;
    if (fileptr == NULL)
        fileptr = fopen(LOG_FILE_NAME, "a");
    if (fileptr != NULL)
        fp = fileptr;
#else
    if (strcmp(level_str, "ERROR") == 0)
        fp = stderr;
#endif

    fprintf(fp, "[%s]", level_str);
#if LOG_SHOW_TIMESTAMP
    fprintf(fp, "[%s]", get_time());
#endif
#if LOG_SHOW_FILE_LINE
    fprintf(fp, "[%s:%d]", file, line);
#endif
#if LOG_SHOW_FUNC_NAME
    fprintf(fp, "[%s]", func);
#endif

    fprintf(fp, " ");

    va_list ap;
    va_start(ap, fmt);
    vfprintf(fp, fmt, ap);
    va_end(ap);

    fprintf(fp, "\n");
}
