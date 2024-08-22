//
// File: file_log.c
//
// this file contain the implementation of the
// all functions in file_log.h that will do the
// job of writing the log message to a log file
//

#include "file_log.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

// <<<<<<<<<<====================>>>>>>>>>> (file_name): this function combine the file path + file name
char* file_name()
{
  static char name[sizeof(FILE_PATH)+sizeof(FILE_NAME)+1];
  snprintf(name, sizeof(name), "%s/%s", FILE_PATH, FILE_NAME);
  return name;
}

// <<<<<<<<<<====================>>>>>>>>>> (file_check): this function check the file exist.
int file_check(const char* fname)
{
  FILE* f_name = file_open(fname,"r");
  if(f_name)
    {
      file_close(f_name);
      return 1;
    }
  return 0;
}

// <<<<<<<<<<====================>>>>>>>>>> (file_create): this function create the file log.txt, if it's not found.
int file_create(const char* fname)
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

// <<<<<<<<<<====================>>>>>>>>>> (file_open): this function open the file to write the log message.
FILE* file_open(const char* fname, const char* mode)
{
  FILE* f = fopen(fname, mode);
  if(!f)
    {
      return NULL;
    }
  return f;
}

// <<<<<<<<<<====================>>>>>>>>>> (file_close): this function close the log file.
void file_close(FILE* flog)
{
  if(fclose(flog) != 0)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }
}

// <<<<<<<<<<====================>>>>>>>>>> (write_log): this function write the log message to the log.txt file
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
  else if(file_check(fname))
    {
      FILE* f = file_open(fname, "a");
      fprintf(f,"%s\n", message);
      file_close(f);
    }
  else
    perror("Error");
}
