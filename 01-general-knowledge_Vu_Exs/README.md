This is README file for Ex1 and Ex2
Author: Phan Tuan Vu

*Make usage:
make all : to build all the libraries, binaries
make mk_objs: make object files
make mk_shared: make shared library
sudo make install (type root password): install shared library to /usr/bin (install rule require root privilege to run)
make mk_static: make static library
make clean: remove every file except for the make file, inc and src. 

*Directory structure:
bin: Directory for the excutable file.
obj: Directory for the object files.
inc: Directory for the header files.
src: Directory for the C and Cpp files.
lib: Directory for the static and shared lib.

*Codes explaination:
- bar: just echo bar 
- foo: echo foo and its parameter
- main: call the foo() with parameter 1997 and call the bar() 
- create static lib by using ar with flag -rsc
- create shared lib by creating object files using -fPIC flag, make and install it to usr/bin (install need root privilege)
