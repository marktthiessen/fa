#ifndef TEXT_FILE_FOR_OUTPUT_H
#define TEXT_FILE_FOR_OUTPUT_H

#include <fstream>
#include <string>

class TextFileForOutput
{
public:
    explicit TextFileForOutput(std::string const & fileName)
    : file(fileName)
    {
    }

    ~TextFileForOutput()
    {
        file.close();
    }

    bool isOpen()
    {
        return file.is_open();
    }

private:
    TextFileForOutput(); // prevent default construction
    std::ofstream file;
};

#endif
