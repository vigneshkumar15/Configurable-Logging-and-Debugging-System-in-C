# Configurable Logging and Debugging System Using C

A simple C project using preprocessor directives to control ERROR, WARNING, INFO and DEBUG logs.

## Files
- src/main.c
- src/logger.c
- include/logger.h
- include/log_config.h
- Makefile

## Compile
gcc -Wall -Iinclude src/main.c src/logger.c -o logger

## Run
logger.exe
