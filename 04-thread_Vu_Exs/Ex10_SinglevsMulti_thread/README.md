This is README file for Ex10
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c to an excutable file
- make clean: remove exec excutable file and a.txt
- ./main <number>  (number = 1/2). Wrong args, usage will be printed to stdout and exit
  + 1: for creating a.txt and write 0 to 100000 to it by 1 thread
  + 2: do the same but with 2 thread

*Codes explaination:
  -Remember to add flag -pthread to Makefile when compling code with thread
  -The function createFile(int maxcount) is use for thread func (3rd parametter of pthread_create()) will create a file name a.txt and write maxcount number to each line
  -When use 1 thread (./main 1) the program completed after only ~ 3 seccond.
  -When use 2 thread to do the same task (./main 2) the program completed after over ~ 35 seconds
 
  => Multi-threading help us manipulate the time using the resource, prevent time lost or waste but not the time taken to do some specific task like this example. 