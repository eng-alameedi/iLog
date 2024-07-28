// File: file_log.h
//
// This file contain the basic functions that check
// the log text file exist on the required directory
// if not, contain the required functions to create
// the file and log the message.
//

#ifndef _FILE_LOG_H_
#define _FILE_LOG_H_

#define FILE_NAME "log.txt"
#define FILE_PATH "/"

void file_check();

void file_create();

void file_open();

void file_close();

#endif   // _FILE_LOG_H_
