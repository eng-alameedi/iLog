//
// File: log_time.c
//
// This file is the implementation of the file log_time.h, which
// contain the function required to get the current time, and date
//

#include "log_time.h"

#include <time.h>

void current_time(char c_time[22])
{
  time_t time_now = time(NULL);
  struct tm *local_time = localtime(&time_now);
  strftime(c_time, sizeof(c_time[0]) * 22, "%Y-%m-%d %H:%M:%S ", local_time);
}
