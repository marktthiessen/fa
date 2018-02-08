#ifndef TEXT_FILE_FOR_INPUT_H
#define TEXT_FILE_FOR_INPUT_H

#include <ifstream>
#include <string>

class TextFileForInput
{
public:
    explicit TextFileForInput(std::string const & fileName)
    : file(fileName)
    {
    }

    ~TextFileForInput()
    {
        file.close();
    }

    bool isOpen()
    {
        return file.is_open();
    }

private:
    std::ifstream file;
};

#endif
