

Usage: 

After building there are two applications in build directory: 
parent.x and child.x.

parent.x starts child process which  performs the child.x routine. 

Command line argument for parent.x routine:

  -h [ --help ]                    produce help message
  -t [ --time ] arg                Periodicity for the child process (in 
                                   milliseconds, accepted interval [1,1000] )
  -o [ --output ] arg (=std::cout) Name of the output file where the output 
                                   will be redirected (if name is not given, stdout will be used)

