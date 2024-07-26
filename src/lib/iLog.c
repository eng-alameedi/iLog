/*
 * The file iLog.c is a main part
 * of the log message project with c
 * it has the implementation of the
 * main function that formed the total
 * project.
 */

#include "iLog.h"

#include <unistd.h>

// this is the check function of the message empty or not
int is_msg(const char *msg)
{
  if(msg[0] == '\0')
    return 0;
  return 1;
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
    msg = "INFO";
    break;
  case WARNING:
    msg = "WARN";
    break;
  case ERROR:
    msg = "ERROR";
    break;
    default:
      msg = "UNKNOWN";
      }
  return msg;
}

// this is the log function
void iLog(char *msg, level lv)
{
  char* level = log_level(lv);
  int buf = size(msg) + size(level) + 3;
  char log_message[buf];
  int len =0;
  log_message[len] = '[';
  int i = 0;
  while(level[i] != '\0')
    {
      ++len;
      log_message[len] = level[i];
      ++i;
    }
  ++len;
  log_message[len] = ']';
  i = 0;
  while(msg[i] !='\0')
    {
      ++len;
      log_message[len] = msg[i];
      ++i;
    }
  ++len;
  log_message[len] = '\0';
  write(STDOUT_FILENO, log_message, size(log_message));
}
