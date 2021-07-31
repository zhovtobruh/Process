#ifndef CMDPARSER
#define CMDPARSER
#include<string> 
#include<boost/program_options.hpp> 
#include<string> 
#include<vector> 



class CmdParser
{ 
  public:
    CmdParser( int arg_counter, char** argv,std::string output );
    ~CmdParser()=default;
    void parse_cla();
    int get_process_duration();
    std::string get_output_name();
  private:
    //process duration in ms 
    int process_duration; 
    std::string output; 
    const std::string CONST_OUTPUT; 
    std::vector<std::string> params;
    const int LOWER_BOUND = 1; 
    const int UPPER_BOUND = 1000;
};

#endif
