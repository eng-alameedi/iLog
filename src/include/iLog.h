//
// File: iLog.h
//
// this file contain the must basic function of
// the Log message project, that will log a
// message to the user on console, and to a
// file.
//

#ifndef _I_LOG_H_
#define _I_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

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

/**
 * @brief this function format the log level depend on the user message level.
 *
 * @param1 enum level, this function take a parameter of type enumeration (INFO, WARN, ERROR, ...etc)
 *
 * @return this function return a log level of type char* like ([INFO])
 */
char* log_level(level);

/**
 * @brief this function is the main core function of the log message project, it show log message to the user on console and file.
 *
 * @param1 const char*, this function use the message from user.
 *
 * @param2 enum level, the log message level chosen by user
 *
 * @return this function has no return type (void)
 */
void iLog(const char*,level);

/**
 * @brief this is a macro to log a message from user, in format of LOG(level, message)
 */
#define LOG(level,message) iLog(message,level)

#ifdef __cplusplus
}
#endif

#endif  // _I_LOG_H_
