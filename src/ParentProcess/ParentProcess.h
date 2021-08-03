#ifndef PARENTPROCESS
#define PARENTPROCESS
#include<iostream>
#include<string>
#include<signal.h>
#include<unistd.h>
#include <sys/types.h>
#include<vector>
#include"Writer.h"

class ParentProcess
{
  private:
    std::string prog_name;
    int time_period;
    std::vector<int> fd;
    pid_t pid;
  public:
     ParentProcess(int time, std::string prog_name );
     ~ParentProcess();
     void run(Writer& ,int);
     void restart(Writer& );


};



#endif
