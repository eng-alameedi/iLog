/*
 * The file iLog.c is a main part
 * of the log message project with c
 * it has the implementation of the
 * main function that formed the total
 * project.
 */

#include "iLog.h"
#include "file_log.h"
#include "log_time.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

// this is the check function of the message empty or not
int is_msg(const char *msg)
{
  if(msg[0] == '\0')
    return False;
  return True;
}

// this is the length function of the log message.
int size(const char *msg)
{
  if(is_msg(msg))
    {
      int count = 0;
      while(msg[count] != '\0')
        ++count;
      return count;
    }
  return 0;
}

// this is the log level choice function
char* log_level(level lv)
{
  char* msg;
  switch (lv) {
  case INFO:
    msg = "[INFO] ";
    break;
  case WARNING:
    msg = "[WARN] ";
    break;
  case ERROR:
    msg = "[ERROR] ";
    break;
    default:
      msg = "[UNKNOWN] ";
      }
  return msg;
}

// this is the log function
void iLog(const char *msg, level lv)
{
  char* level = log_level(lv);
  char local_time[22];
  current_time(local_time);
  size_t buffer = size(msg) + size(level) + size(local_time);
  char log_message[buffer];

  memcpy(log_message, level, size(level));
  memcpy(log_message + size(level), local_time, size(local_time));
  memcpy(log_message + size(level) + size(local_time), msg, size(msg));
  log_message[buffer] = '\0';

  write(STDOUT_FILENO, log_message, buffer);

  // files open and write the log message then close it
  if(lv == ERROR)
    write_log(log_message);
}
