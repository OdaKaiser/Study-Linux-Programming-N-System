This is README file for Ex17
Author: Phan Tuan Vu

*Make usage:
- make all : to build main.c to excutable files, remember the linking "-lrt" option
- make clean: remove all excutable files
- run ./exec

*Code explaination:
Flow of message queue
mq_open
mq_send
mq_receive
mq_close
mq_unlink