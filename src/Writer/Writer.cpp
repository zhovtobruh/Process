#include"Writer.h"

Writer::Writer(const std::string& fname, const std::string& const_out)
  :out_name(fname),CONST_OUT(const_out), out()
{
  if( out_name != CONST_OUT)
  {
    out.open(fname, std::ios_base::app);
  }

};

void Writer::write_message(const std::string& message)
{
  if( out_name != CONST_OUT )
  {
    out<<message<<std::endl;
  }else{
    std::cout<<message<<std::endl;  
  }
}

std::string Writer::get_out_name()
{
  return out_name;
}

Writer::~Writer()
{
  if( out_name != CONST_OUT )
  {
    out.close();
  }  
}

