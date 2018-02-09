#include <iostream>
#include <string>
#include <vector>

#include "TextFileForInput.h"
#include "TextFileForOutput.h"

bool argumentsExist( int const & argc, char const * const * const & argv );
void reportAnyErrors( int const & argc, char const * const * const & argv );
void runProgram( int const & argc, char const * const * const & argv );
std::vector< std::string > convert( char const * const * const & argv );
void loadInput( std::string const & fileName );
void process();
void saveResults( std::string const & fileName );

int main( int argc, char * argv[] )
{
    if ( ! argumentsExist( argc, argv ) )
        return 1;

    runProgram( argc, argv );
    return 0;
}

bool argumentsExist( int const & argc, char const * const * const & argv )
{
    if ( argc >= 3 )
        return true;

    reportAnyErrors( argc, argv );
    return false;
}

void reportAnyErrors( int const & argc, char const * const * const & argv )
{
    if ( argc == 2 )
        std::cout << "syntax: " << argv[0] << " " << argv[1] << " <output file name>" << std::endl;

    if ( argc == 1 )
        std::cout << "syntax: " << argv[0] << " <input file name> <output file name>" << std::endl;
}

void runProgram( int const & argc, char const * const * const & argv )
{
    std::vector< std::string > fileNames = convert( argv );
    loadInput( fileNames[ 0 ] );
    process();
    saveResults( fileNames[ 1 ] );
}

std::vector< std::string > convert( char const * const * const & argv )
{
    std::vector< std::string > fileNames;
    fileNames.push_back( argv[ 1 ] );
    fileNames.push_back( argv[ 2 ] );
    return fileNames;
}

void loadInput( std::string const & fileName )
{
    TextFileForInput file( fileName );
    if ( ! file.isOpen() )
        std::cout << "Error! Input file " << fileName << " is not open." << std::endl;
}

void process()
{
}

void saveResults( std::string const & fileName )
{
    TextFileForOutput file( fileName );
    if ( ! file.isOpen() )
        std::cout << "Error! Output file " << fileName << " is not open." << std::endl;
}

