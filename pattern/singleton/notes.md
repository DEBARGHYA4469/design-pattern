Installation of Gtest package: 

* I am using cygwin for compiling and running my source code and it does not come with googletests libraries. 
* So I had to clone `https://github.com/google/googletest.git` 
* Install "cmake" from Cygwin archives. 
* Run cmake -G to generate UNIX archive files. 
* Copy the .a files to cygwin lib directory. 
* Headers : Copy the header files to \usr\include of cygwin folder. 
* Sources Link : Add "-lgtest -lgtest_main -lpthread" to $LDFLAGS variables in Makefile. 