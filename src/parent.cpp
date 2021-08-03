#include"ParentProcess.h"
#include"CmdParser.h"
#include<sys/wait.h>
#include"constants.h"
#include"Writer.h"

int main(int argc, char** argv)
{
   CmdParser parser(argc, argv, constants::CONST_OUTPUT);
   parser.parse_cla();
   int periodicity = parser.get_process_duration();

   std::string fname= parser.get_output_name();
   Writer writer(fname, constants::CONST_OUTPUT);
   ParentProcess parent(periodicity, constants::CHILD_PROGRAM);
   parent.run(writer,0);
   while(true)
   {
     wait(nullptr);
     parent.restart(writer);
   }

   return 0;
}
