#include <iostream>

#include "executor.hpp"

int Executor::CountWordsNumberInLine( std::string const& line, std::string const& word ) const
{
    int result = 0;

    auto pos = line.find( word );
    while( pos != std::string::npos )
    {
        result++;
        pos = line.find( word, pos + word.size() );
    }

    return result;
}

std::uint32_t Executor::CalculateChecksum( std::stringstream& buffer ) const
{
    std::uint32_t result = 0;
    std::uint32_t word;

    while ( buffer.read( reinterpret_cast<char*>( &word ), sizeof( word ) ) ) 
    {
        result += word;
    }

    return result;
}

void Executor::PrintProgramInfo() const 
{
    std::cout << "-f <file_path>      : specify the path to the file" << std::endl;
    std::cout << "-m <operation_name> : indicate the name of the operation" << std::endl;
    std::cout << "   words            : operation of counting the number of occurrences of a word in a file" << std::endl;
    std::cout << "   checksum         : operation of calculating the 32-bit checksum of a file" << std::endl;
    std::cout << "-v <word>           : specify the word to count (works in conjunction with the \"words\" command)" << std::endl;
    std::cout << "-h                  : prints program information and parameter descriptions" << std::endl;
}