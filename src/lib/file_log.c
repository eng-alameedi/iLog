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


char* file_name()
{
  static char name[sizeof(FILE_PATH)+sizeof(FILE_NAME)+1];
  snprintf(name, sizeof(name), "%s/%s", FILE_PATH, FILE_NAME);
  return name;
}
int file_check()
{
  char* fname = file_name();
   FILE *f_name;
  f_name = fopen(fname, "r");
  if(f_name)
    {
      fclose(f_name);
      return 1;
    }
  return 0;
}


int file_create()
{
  if(file_check())
    {
      LOG(INFO,"File Exist\n");
      return 0;
    }
  else
    {
      LOG(INFO,"Create Directory\n");
      if(mkdir(FILE_PATH, 0755) != 0)
        {
          perror("Error");
          return 0;
        }
      else
        {
          char* fname = file_name();
          FILE *f;
          f = fopen(fname, "w");
          if(!f)
            {
              perror("Error");
              return 0;
            }
          fclose(f);
        }
    }
  return 1;
}
