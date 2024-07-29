// File: file_log.h
//
// This file contain the basic functions that check
// the log text file exist on the required directory
// if not, contain the required functions to create
// the file and log the message.
//

#ifndef _FILE_LOG_H_
#define _FILE_LOG_H_

#define FILE_NAME "log.txt"    // default log file name
#define FILE_PATH "log"      // default log file directory

/**
 * @brief this function check the existence of the log.txt file
 *
 * @param1 the function take no parameter.
 *
 * @return the function return true (1) if file exist or false (0) if not.
 *
 */
int file_check();

/**
 * @brief this function do the job of creation log file (log.txt) in the specific directory
 *
 * @param1 the log file name (log.txt)
 *
 * @param2 the path to the log file (/log/)
 *
 * @return the function return true (1) if file creation done or false (0) if not.
 */
//int file_create(const char*, const char*);
int file_create();

/**
 * @brief this function open the file for (append)
 *
 * @param1 the function take a file name string (char*)
 *
 * @return the function will return nothing
 *
 */
void file_open(const char*);

/**
 * @brief this function will do the job of writing the log message to the file.
 *
 * @param1 this function take the text log message (char*) as parameter
 *
 * @return this function return nothing.
 *
 */
void write_log(char*);

/**
 * @brief this function will do the job of closing the log.txt file before quite the program
 *
 * @param1 this function will take the file name as parameter.
 *
 * @return this function will return nothing
 *
 */
void file_close(char*);

#endif   // _FILE_LOG_H_
