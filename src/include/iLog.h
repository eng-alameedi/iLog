// File: iLog.h
//
// this file contain the must basic function of
// the Log message project, that will log a
// message to the user on console, and to a
// file.
//

#ifndef _I_LOG_H_
#define _I_LOG_H_

typedef enum { INFO, WARNING, ERROR } level;      // this enum called level, contain the must log level to the user

/**
 * @brief this function take a string text and check if it's valid.
 *
 * @param1 const char*: is a pointer (C-style string) contain the log message.
 *
 * @return the function return a true/false is the text message valid
 */

int is_msg(const char*);

/**
 * @brief this function take a string text message to find its length
 *
 * @param1 const char* is a (C-style string) log message
 *
 * @return the function return the length of the text message (letter count)
 */

int size(const char*);

char* log_level(level);

char* message_format(char*,level);

void iLog(const char*,level);

// Macro Define for log message to the user

#define LOG(level,message) iLog(message,level)

#endif  // _I_LOG_H_
