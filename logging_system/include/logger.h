#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include "log_config.h"

void log_write(int level, const char *level_str,
               const char *file, int line,
               const char *func, const char *fmt, ...);

#ifndef ENABLE_LOGGING

#define LOG_ERROR(fmt, ...) do { } while(0)
#define LOG_WARN(fmt, ...)  do { } while(0)
#define LOG_INFO(fmt, ...)  do { } while(0)
#define LOG_DEBUG(fmt, ...) do { } while(0)

#else

#if CURRENT_LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(fmt, ...) log_write(LOG_LEVEL_ERROR, "ERROR", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#else
#define LOG_ERROR(fmt, ...) do { } while(0)
#endif

#if CURRENT_LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...) log_write(LOG_LEVEL_WARN, "WARN", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#else
#define LOG_WARN(fmt, ...) do { } while(0)
#endif

#if CURRENT_LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...) log_write(LOG_LEVEL_INFO, "INFO", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...) do { } while(0)
#endif

#if CURRENT_LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(fmt, ...) log_write(LOG_LEVEL_DEBUG, "DEBUG", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...) do { } while(0)
#endif

#endif

#define LOG_ASSERT(cond, msg) do {     if (!(cond))         LOG_ERROR("Condition failed: %s", msg); } while(0)

#endif
