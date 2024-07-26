/*
 * This file iLog.h is a part
 * of the iLog message project
 * contains the necessary tools
 * for defining user log message
 */

#ifndef _ILOG_H_
#define _ILOG_H_

typedef enum { INFO, WARNING, ERROR } level;

int is_msg(const char*);                       // This function take (char* message), and check the text message and return (1,0) true/false

int size(const char*);                         // This function take a (char* message), and return the length of the message.

char* log_level(level);                  // This function return the log level (info, warn, error)

char* message_format(char*,level);       // This function for format the output message 

void iLog(char*,level);                         // This is the main log function that take (char* message), and (int size of message)

// Macro Define for log message to the user

#define LOG(level,message) iLog(message,level)

#endif  // _ILOG_H_
