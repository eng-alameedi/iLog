//
// File: log_time.h
//
// This file contain the main function that return the local current time, and date.
// this function use the time.h functions and parameters to fetch the time, and date.
//

#ifndef _LOG_TIME_H_
#define _LOG_TIME_H_

/**
 * @brief this function fetch the time, and date of the local timezone
 *
 * @param this function take no parameter.
 *
 * @return this function return formatted time, and date as string of type char*
 */
char* current_time();

#endif    // _LOG_TIME_H_
