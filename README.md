# iLog
      is a customize log function, that will log a message to the console and log file. This function will use a low level output **STDOUT** for message log. This function will run on a **UNIX** based system.

## Developing Steps:
- step 1: create a simple log function, for message log on console.
- step 2: add a log to file new function.

## Flow Diagram

                                        iLog
                                [INFO, WARNING, ERROR]
                                          |
                                 _________|__________
                                |                    |
                             Console                File
                         [INFO, WARNING]           [ERROR]
                              |                     |
                      Continue Execution      Stop Execution

## File Structure
iLog.h: This header file contains the necessary definitions like(functions, enum, etc...).

iLog.c: This file contains the implementation of the logs function.
