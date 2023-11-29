This is README file for Ex6
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c to an excutable file
- make clean: remove exec excutable file
- ./main <number>  (number = 1/2). Wrong args, usage will be printed to stdout and exit

*Codes explaination:
- main.c: using fork() to make a child process from a parent process and check for error
  + Child process: print pid and ppid
  + Parent process: Show its process ID and 
  use wait() if argument is 1 or use SIGCHLD if argument is 2 to prevent zombie process