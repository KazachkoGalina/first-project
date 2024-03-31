#include <sstream>

#include "file.hpp"
#include "command.hpp"

CommandParameters const& Command::GetCommandParameters() const 
{
    return mCommandParameters;
}

void Command::ParseCommand( int count, char* argument_list[] )
{
    for( int index = 0; index < count; index++ )
    {
        if( std::strcmp( argument_list[ index ], "-f" ) == 0 )
        {
            index++;

            if( index >= count )
            {
                break;
            }

            mCommandParameters.mFileName = argument_list[ index ];
        }
        else if( std::strcmp( argument_list[ index ], "-m" ) == 0 )
        {
            index++;

            if( index >= count )
            {
                break;
            }

            if( std::strcmp( argument_list[ index ], "words" ) == 0 )
            {
                mCommandParameters.mOperationName = types::OperationName::WORDS;
                mCommandParameters.mOperatingMode = types::OperatingMode::WORD_COUNT;
            }
            else if ( std::strcmp( argument_list[ index ], "checksum" ) == 0 )
            {
                mCommandParameters.mOperationName = types::OperationName::CHECHKSUM;
                mCommandParameters.mOperatingMode = types::OperatingMode::BIT_CHECHKSUM;
            }
        }
        else if( std::strcmp( argument_list[ index ], "-v" ) == 0 )
        {   
            index++;

            if( index >= count )
            {
                break;
            }

            mCommandParameters.mCountedWord = argument_list[ index ];
        }
        else if( std::strcmp( argument_list[ index ], "-h" ) == 0 )
        {
            mCommandParameters.mOperatingMode = types::OperatingMode::PROGRAM_INFO;
        }
    }
}

void Command::Run( Executor const& executor )
{
    if( mCommandParameters.mOperatingMode == types::OperatingMode::WORD_COUNT )
    {
        std::stringstream buffer;

        File::ReadBinaryFile( mCommandParameters.mFileName, buffer );

        auto words_count = executor.CountWordsNumberInLine( buffer.str(), mCommandParameters.mCountedWord );

        std::cout << "words_count : " << words_count << std::endl;
    }
    else if( mCommandParameters.mOperatingMode == types::OperatingMode::BIT_CHECHKSUM )
    {
        std::stringstream buffer;

        File::ReadBinaryFile( mCommandParameters.mFileName, buffer );

        auto checksum = executor.CalculateChecksum( buffer );

        std::cout << "checksum : " << checksum << std::endl;
    }
    else if( mCommandParameters.mOperatingMode == types::OperatingMode::PROGRAM_INFO )
    {
        executor.PrintProgramInfo();
    }
    else
    {
        std::cout << "unknown command format" << std::endl;
    }
}