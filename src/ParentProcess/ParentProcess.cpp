#include"ParentProcess.h"


ParentProcess::ParentProcess(int time, std::string program_path)
:time_period(time), prog_name(program_path),fd(),pid()
{
  int descriptors[2];
  if( pipe(descriptors) < 0 )
  {
    std::cerr<<"Cannot create process pipe.Exit"<<std::endl;
    exit(1);
  }
  fd.push_back(descriptors[0] );
  fd.push_back(descriptors[1] );

}
void ParentProcess::run(Writer& writer, int counter = 0)
{

  pid = fork();
  if(pid > 0)
  {
    writer.write_message("Start child process");
    writer.write_message( std::string("Pid process ")+std::to_string(pid) );
  }

  if(pid != 0) close(fd[1]);
  if(pid == 0)
  {
	  std::string count, time,desc_r, desc_w;
	  count = std::to_string(counter);
	  time = std::to_string(time_period);
	  desc_r = std::to_string(fd[0]);
	  desc_w = std::to_string(fd[1]);
	  // count time descriptor1 descriptor2
	  execl(prog_name.c_str(), prog_name.c_str(),count.c_str(),
			   time.c_str(), desc_r.c_str(), desc_w.c_str(),
			   writer.get_out_name().c_str(), NULL);
  }

}

void ParentProcess::restart(Writer& writer)
{
  int current_counter;
  const int buff_size = 50;
  char buff[buff_size];
  int nbytes = read(fd[0],buff, buff_size);
  current_counter = std::stoi(std::string(buff));
  close(fd[0]);
  int desc[2];
  if(pipe(desc) < 0)
  {
	  std::cerr<<"Cannot create pipe.Exit"<<std::endl;
	  exit(1);
  }
  fd[0] = desc[0];
  fd[1] = desc[1];
  writer.write_message("Child process will be restarted ");
  run(writer, current_counter);
}




ParentProcess::~ParentProcess()
{
  close(fd[0]);
}
