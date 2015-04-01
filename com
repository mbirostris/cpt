g++ -std=c++0x pruba.cc `root-config --libs --cflags` -o foo
g++ -std=c++0x  src/* bin/pruba.cc `root-config --libs --cflags` -o foo  -lboost_system -lboost_regex  && rm temp/* &&  rm trees/* 
 scl enable devtoolset-1.1 bash
