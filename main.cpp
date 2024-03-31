#include <iostream>

#include "command.hpp"
#include "executor.hpp"

int main( int argc, char* argv[] )
{
    Command command; 
    command.ParseCommand( argc, argv );

    Executor executor;

    command.Run( executor );
}
