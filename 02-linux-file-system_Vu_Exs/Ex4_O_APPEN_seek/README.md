This is README file for Ex4
Author: Phan Tuan Vu

*Make usage:
- make all : to build all the exec excutable file
- make clean: remove exec excutable file

*Codes explaination:
- Creating an open file descriptor with O_APPEND flag 
- Using lseek to set the open file descriptor 
  offset to the beginning of the file then write some data to it
- Close file descriptor 

*Q&A:
Q:Where is the data going to appear in the file and why?
A:
- The data is going to be written at the end of the file and 
it doesn't override the last written data of the file
- The reason:
    The open file descriptor was created by the O_APPEND flag means the 
    offset always positions at the end of the last write() operation 
    regardless of the lseek() set the offset to the beginning 
    of the file
