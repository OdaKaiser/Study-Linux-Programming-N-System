This is README file for Ex8
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c to an excutable file
- make clean: remove exec excutable file 
- ./main. It will send a SIGINT, a SIGUSR1, and a SIGUSR2

*To manually send signal, do as below:
- open a nother terminal Ctrl + C to verify that code is running "ha ha ha".
- run ps -aux | grep "./main" get pid of ./main
- use kill -n 10 <pid> to use SIGUSR1
- use kill -n 12 <pid> to use SIGUSR2

*Codes explaination:
  - Register SIGINT print ha ha ha to stdout.
  - Register SIGUSR1 print he he he to stdout.
  - Register SIGUSR2 print he he he to stdout.

*Potential improvement : I'll write a shell script to automate the manual step.
