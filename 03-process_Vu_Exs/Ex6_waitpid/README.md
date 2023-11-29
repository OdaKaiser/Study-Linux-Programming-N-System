This is README file for Ex6
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c to an excutable file
- make clean: remove exec excutable file
- ./main <number>  (number > 0). Wrong args, usage will be printed to stdout
- Comment 1 of 3 blocks in code to see effect

*Codes explaination:
- main.c: using fork() to make a child process from a parent process and check for error
  + Child process: print pid and ppid
  + Parent process: Show its process ID and check for wait() or waitpid() success or not from its child process
