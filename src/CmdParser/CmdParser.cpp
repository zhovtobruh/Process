#include"CmdParser.h"
#include<iostream>
#include<exception> 

namespace po = boost::program_options;


CmdParser::CmdParser( int arg_counter, char** argv, std::string out)
            :params(), process_duration(0), output(), CONST_OUTPUT(out)
{
   if( arg_counter == 1)
   {
     std::cout<<"Time Duration for child process should be provided. Exit.\n"
              <<"For program usage run with options -h or --help \n"<<std::endl;
     exit(1);   
   }
   
   for(int i = 1; i < arg_counter; i++)
     params.push_back(argv[i]);
   

}

void CmdParser::parse_cla()
{
    po::options_description desc("Allowed options");
    int duration;
    desc.add_options()
     ("help,h", "produce help message")
     ("time,t",   po::value<int>(), "Periodicity of the child process (in milliseconds [1, 1000] )")
     ("output,o", po::value<std::string>()->default_value(CONST_OUTPUT),
     "Name of the output file where the output will be redirected (without this option stdout will be used)");
  
     po::variables_map vm;
     po::basic_command_line_parser<char> parser( params );
     parser.options( desc );

     try
     {
       po::store(parser.run(), vm);
     }
     catch(std::exception& e)
     {
       std::cout<<"Cannot parse the command line arguments. Check input \n"
                <<"Type -h or --help for help message\n"
                <<e.what()<<std::endl;
       exit(1);     
     }

     po::notify( vm );  

     if (vm.count("help")) {
       std::cout << desc << "\n";
       exit(1);
     }
     if( vm.count("time") == 0 )
     {
       std::cout<<"Please provide the mandatory time period in milliseconds or use -h for help"<<std::endl;
       exit(1);
     }else{ 
       try
       { 
          duration = vm["time"].as<int>(); 
       }catch(std::exception& e)
       {
          std::cout<<"Cannot convert time command line argument to int. Exit\n"
                   <<"Check the input and try again. Exit. "<<std::endl;
          exit(1);
       } 
       if( duration > UPPER_BOUND || duration < LOWER_BOUND )
       {
          std::cout<<"The time should be in range ["<<LOWER_BOUND<<":"
                   <<UPPER_BOUND<<"] miliseconds. Exit."<<std::endl;
          exit(1);
       }
     }
     
     process_duration = duration;
     output = vm["output"].as<std::string>();

}

std::string CmdParser::get_output_name()
{
   return output;
}

int CmdParser::get_process_duration() 
{
  return process_duration;
}




