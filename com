scl enable devtoolset-1.1 bash
g++ -std=c++0x  src/* bin/pruba.cc `root-config --libs --cflags` -o run  -lboost_system -lboost_regex 
rm temp/* 
rm trees/* 
