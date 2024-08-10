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
 * @param this function take a parameter of type char[22].
 *
 * @return this function return nothing (void), its just update the char* with current time.
 */
void current_time(char c_time[22]);

#endif    // _LOG_TIME_H_
