#include"ChildProcess.h"
#include"constants.h"




int main(int argc, char** argv)
{
	ChildProcess child(argc, argv);
	Writer writer(child.get_file_name(), constants::CONST_OUTPUT);
	writer.write_message(std::string("Start child process with counter value ") 
	                      + std::string( argv[1] ) );

	child.run(writer);	
	return 0;
}


