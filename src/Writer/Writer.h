#ifndef WRITER
#define WRITER 

#include <sys/stat.h>
#include <fcntl.h>
#include<string>

class Writer
{
  private:
    std::string out_name;
    int fd;
    const int STDOUT = 1;
  public:
    Writer(const std::string& fname, const std::string& const_out);
    void write_message(const std::string&); 
    std::string get_out_name();

    ~Writer();
};

#endif
