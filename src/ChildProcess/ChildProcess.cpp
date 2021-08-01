#include"ChildProcess.h"

int ChildProcess::counter;
std::vector<int> ChildProcess::fd;

ChildProcess::ChildProcess(int argc, char** argv)
{
   int count; 
   int time;
   // argument order 
   // count time descriptor1 descriptor2 
   count = std::stoi( std::string(argv[1]) );
   time = std::stoi(  std::string(argv[2]) );
   int fdr, fdw;
   fdr = std::stoi( std::string(argv[3]) );
   fdw = std::stoi( std::string(argv[4]) );
   counter = count; 
   fd.push_back( fdr ); fd.push_back( fdw );
   close(fdr);
   fname = std::string( argv[5] );
   signal(SIGTERM, ChildProcess::sig_term_handler);
}

std::string ChildProcess::get_file_name()
{
   return fname; 
}

void ChildProcess::run(Writer& writer)
{
  while( true )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( counter ) );
    add_counter();
    writer.write_message( std::string("Counter ")+std::to_string(counter) );  
  }

}
void ChildProcess::add_counter()
{
  counter++;
}

void ChildProcess::sig_term_handler(int num)
{
  std::cout<<"Child process received the SIGTERM signal "<<std::endl;
  std::string buff;
  buff = std::to_string(counter);
  std::cout<<"Buff value "<<buff<<std::endl;
  write(fd[1], buff.c_str(), buff.size()+1 ); 
  exit(1);
}

ChildProcess::~ChildProcess()
{
  close(fd[1]);
}
