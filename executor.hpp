#pragma once

#include <sstream>

class Executor 
{
public:
    int CountWordsNumberInLine( std::string const& line, std::string const& word ) const;

    std::uint32_t CalculateChecksum( std::stringstream& buffer ) const; 

    void PrintProgramInfo() const;
};