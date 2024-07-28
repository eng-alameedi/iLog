#include "iLog.h"
#include "file_log.h"

int main(void) {
  LOG(INFO,"Hello, World\n");
  LOG(INFO,FILE_NAME);
  return 0;
}
