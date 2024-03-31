#pragma once

#include <iostream>
#include <map>

#include "types/enums.hpp"
#include "executor.hpp"

struct CommandParameters
{
    std::string mFileName = {};
    std::string mCountedWord = {};
    types::OperatingMode mOperatingMode = types::OperatingMode::NONE;
    types::OperationName mOperationName = types::OperationName::NONE;
};

class Command
{
public:
    CommandParameters const& GetCommandParameters() const;

    void ParseCommand( int count, char* argument_list[] );

    void Run( Executor const& executor );

private:
    CommandParameters mCommandParameters;
};