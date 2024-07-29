//
// File: file_log.c
//
// this file contain the implementation of the
// all functions in file_log.h that will do the
// job of writing the log message to a log file
//

#include "file_log.h"
#include "iLog.h"


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

char* file_name()    // function that combine path+filename and return all
{
  static char name[sizeof(FILE_PATH)+sizeof(FILE_NAME)+1];
  snprintf(name, sizeof(name), "%s/%s", FILE_PATH, FILE_NAME);
  return name;
}

int file_check(const char* fname)    // function to check file status
{
  FILE* f_name = file_open(fname,"r");
  if(f_name)
    {
      file_close(f_name);
      return 1;
    }
  return 0;
}

int file_create(const char* fname)     // function to create the log file
{
  if(mkdir(FILE_PATH, 0755) != 0)
    {
      perror("Error");
      return 0;
    }
  else
    {
      FILE *f;
      f = file_open(fname, "w");
      if(!f)
        {
          perror("Error");
          return 0;
        }
      file_close(f);
    }
  return 1;
}

FILE* file_open(const char* fname, const char* mode)     // function to open the log file for add log message
{
  FILE* f = fopen(fname, mode);
  if(!f)
    {
      return NULL;
    }
  return f;
}

void file_close(FILE* flog)   // function to close the log file after append log message
{
  if(fclose(flog) != 0)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }
}

void write_log(const char* message)
{
  char* fname = file_name();
  if(!file_check(fname))
    {
      if(file_create(fname))
        {
          FILE* f = file_open(fname, "a");
          fprintf(f, "%s\n", message);
          file_close(f);
        }
      else
        perror("Error");
    }
  else
    perror("Error");
}
