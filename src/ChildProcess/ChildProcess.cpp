#include"ChildProcess.h"

int ChildProcess::counter;
int ChildProcess::fd;

ChildProcess::ChildProcess(int argc, char** argv)
{
   // argument order
   // count time descriptor1 descriptor2
   counter = std::stoi( std::string(argv[1]) );
   time_period = std::stoi(  std::string(argv[2]) );
   int fdr, fdw;
   fdr = std::stoi( std::string( argv[3]) );
   fdw = std::stoi( std::string( argv[4]) );
   fd = fdw;
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
    std::this_thread::sleep_for( std::chrono::milliseconds( time_period ) );
    counter++;
    writer.write_message( std::string("Counter ")+std::to_string(counter) );
  }

}

void ChildProcess::sig_term_handler(int num)
{

  std::string buff;
  buff = std::to_string(counter);
  write(fd, buff.c_str(), buff.size()+1 );
  exit(1);
}

ChildProcess::~ChildProcess()
{
  close(fd);
}
