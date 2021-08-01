#include"Writer.h"
#include<iostream>
#include <unistd.h>

Writer::Writer(const std::string& fname, const std::string& const_out)
  :out_name(fname)
{
  if( out_name != const_out)
  {
    int file_descriptor = open( fname.c_str(), O_CREAT | O_APPEND | O_WRONLY, 
                               S_IRWXU | S_IRWXO  );
    if( file_descriptor == -1 )
    {
      std::cerr<<"Cannot open file. Exit"<<std::endl;
    }
    fd = file_descriptor;
  }else{
    fd = STDOUT;  
  }

};

void Writer::write_message(const std::string& message)
{
    std::string buff = message + "\n";
    write(fd, buff.c_str(), buff.size() );
}

std::string Writer::get_out_name()
{
  return out_name;
}

Writer::~Writer()
{
  if( fd != STDOUT )
  {
    close(fd);
  }  
}

