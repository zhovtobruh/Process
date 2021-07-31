#ifndef CHILDPROCESS
#define CHILDPROCESS

#include<vector> 
#include <unistd.h>
#include<thread> 
#include<chrono>
#include<iostream> 
#include<string> 
#include<signal.h>
#include"Writer.h"

class ChildProcess{
  private:
     static int counter;
     static std::vector<int> fd; 
     // time is given in milliseconds
     int time_period; 
     std::string fname;
  public:
     static void sig_term_handler(int);
     ChildProcess(int count, char** args);
     void run(Writer& writer);
     void add_counter();
     std::string get_file_name();
     ~ChildProcess();    

};

#endif
