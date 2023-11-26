This is README file for Ex3
Author: Phan Tuan Vu

*Make usage:
make all : to build all the exec excutable file
make clean: remove exec excutable file

*Codes explaination:
- Creating an open file descriptor with open and O_CREAT flag to create the file if it doesn't exist
- Creating struct stat, assigning the file path to stat(), printing to stdout the information of the created file
    + Making a switch case to find the right file type by using this formula 
    "st_mode AND S_IFMT" (test file type bit value) returns the right bit value for the file type
    + Using st_ino for file Inode information, st_size for file size information
    + Using time.h for the information related to time
- Close file descriptor 