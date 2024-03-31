#pragma once

#include <string>
#include <filesystem> 

class File
{
public:
    static void ReadBinaryFile( std::filesystem::path const& path, std::stringstream& st );
};