Writing Unittests with Gtest suite 

Installation of Gtest package: 

* I am using cygwin for compiling and running my source code and it does not come with googletests libraries. 
* So I had to clone `https://github.com/google/googletest.git` 
* Install "cmake" from Cygwin archives. 
* Run `cmake -G <> ..` to generate UNIX archive files from a build folder.  
* Copy the .a files to cygwin lib directory. 
* Headers : Copy the header files to `\usr\include` of cygwin folder. 
* Sources Link : Add `-lgtest -lgtest_main -lpthread` to `$LDFLAGS` variables in Makefile. 


ASSERT : Fatal failure
EXPECT : Non-Fatal Failure

* EXPECT_EQ, ASSERT_EQ
* EXPECT_NE, ASSERT_NE
* EXPECT_LT, ASSERT_LT
* EXPECT_GT, ASSERT_GT
* EXPECT_LE, ASSERT_LE
* EXPECT_GE, ASSERT_GE

For string comparisons 

* EXPECT_STREQ, ASSERT_STREQ 
* EXPECT_STRNE, ASSERT_STRNE 
* EXPECT_STRCASEEQ, ASSERT_STRCASEEQ  
* EXPECT_STRCASENE, ASSERT_STRCASENE  

You don't have to `InitGoogleTest` from main or write a separate main function, linking gtest main does the work! 

### Writing a Test Fixture for a Stack Class

### Writing Mocks 

Ref : https://google.github.io/googletest/gmock_for_dummies.html

I faced a weird SegV error with gmock in cygwin. To resolve I cleaned up build dir and recreated it and ran 
`$ cmake ... -Dgtest_disable_pthreads=ON`. This will generate new lib files, copy it to cygwin's lib.


