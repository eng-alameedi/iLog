//
// File: log_time.c
//
// This file is the implementation of the file log_time.h, which
// contain the function required to get the current time, and date
//

#include "log_time.h"
#include <time.h>

char* current_time()
{
  time_t time_now = time(NULL);
  struct tm *local_time = localtime(&time_now);

  char text_time[22];
  strftime(text_time, sizeof(text_time), "%Y-%m-%d %H:%M:%S ", local_time);

  char* local = text_time;
  return local;
}
