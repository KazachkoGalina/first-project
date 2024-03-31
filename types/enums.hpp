namespace types
{

/** Режимы работы программы */
enum class OperatingMode
{
    NONE = 0,
    WORD_COUNT = 1,
    BIT_CHECHKSUM = 2,
    PROGRAM_INFO = 3
};

/** Название операции совершаемой над файлом */
enum class OperationName
{
    NONE = 0,
    WORDS = 1,
    CHECHKSUM = 2
};

}