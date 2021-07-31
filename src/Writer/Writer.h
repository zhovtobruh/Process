#ifndef WRITER
#define WRITER 

#include<fstream> 
#include<iostream> 
#include<string>

class Writer
{
  private:
    std::string out_name;
    const std::string CONST_OUT;
    std::ofstream out;
  public:
    Writer(const std::string& fname, const std::string& const_out);
    void write_message(const std::string&); 
    std::string get_out_name();
    ~Writer();
};

#endif
