//
// File: log_time.c
//
// This file is the implementation of the file log_time.h, which
// contain the function required to get the current time, and date
//

#include "log_time.h"

#include <time.h>
#include <string.h>

void current_time(char* c_time)
{
  size_t index = 22;
  char time_text[index];
  time_t time_now = time(NULL);
  struct tm *local_time = localtime(&time_now);
  strftime(time_text, sizeof(c_time[0]) * 22, "%Y-%m-%d %H:%M:%S ", local_time);
  memcpy(c_time,time_text,sizeof(time_text[0])*index);
}
