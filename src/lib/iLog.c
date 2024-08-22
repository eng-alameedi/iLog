//
// File: iLog.c
//
// this a main part of the log message project
// written with c language, it has the core,
// implementation of the log message function
// that displayed to the user console, and to
// a log text file with time and date.
//

#include "iLog.h"
#include "file_log.h"
#include "log_time.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

// <<<<<<<<<==========================>>>>>>>>> (is_msg): this function check log message.
int is_msg(const char *msg)
{
  if(msg[0] == '\0')
    return False;
  return True;
}

// <<<<<<<<<==========================>>>>>>>>> (size): this function count the length of log message.
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

// <<<<<<<<<==========================>>>>>>>>> (log_level): this function change log level to string.
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

// <<<<<<<<<==========================>>>>>>>>> (iLog): this function log message to console, and to a log file 
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
  if(lv != INFO)
    write_log(log_message);
}
