/*
 * This file iLog.h is a part
 * of the iLog message project
 * contains the necessary tools
 * for defining user log message
 */

#ifndef _ILOG_H_
#define _ILOG_H_

typedef enum { INFO, WARNING, ERROR } level;

#define INFO level.INFO
#define WARN level.WARNING
#define ERROR level.ERROR

int is_msg(char*);                // This function take (char* message), and check the text message and return (1,0) true/false

int size(char*);                  // This function take a (char* message), and return the length of the message.

const char* log_level(level);     // This function return the log level (info, warn, error)

void iLog(int, char*);            // This is the main log function that take (char* message), and (int size of message)

// Macro Define for log message to the user

#define LOG (level) (message, ...) iLog(level, message)

#endif  // _ILOG_H_
