#include "iLog.h"
#include "file_log.h"

int main(void) {
  LOG(INFO,"Hello, World\n");

  if(file_check())
    LOG(INFO,"File Exist\n");
  else
    LOG(INFO,"File not Found\n");

  if(file_create())
    LOG(INFO,"File Created\n");
  else
    LOG(WARNING,"File Not Created\n");
  return 0;
}
