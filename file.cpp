#include <fstream>
#include <iostream> 
#include <sstream>

#include "file.hpp"

void File::ReadBinaryFile( std::filesystem::path const& path, std::stringstream& st )
{
    std::ifstream ifstr( path, std::ios::binary );
    if( !ifstr.is_open() )
    {
        std::cout << "Failed to open file : " << path << std::endl;
        return;
    }

    st << ifstr.rdbuf();
    ifstr.close();
}

