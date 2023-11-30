This is README file for Ex5
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c and DigitalClock.c link them to an excutable file
- make clean: remove exec excutable file
- ./main to run clock. To turn off, open another termial, use ps -aux | grep "./main" and kill the excutable process

*Codes explaination:
- DigitalClock.c: this is a program intented for child process to run 
  + Get current time of system to init the clock values
  + Print a Digital Clock and the infomations of its process ID, and parent's process ID to stdout 
  + Update time every second  
- main.c: using fork() to make a child process from a parent process and check for error
  + Child process: run DigitalClock.c
  + Parent process: Show its process ID
