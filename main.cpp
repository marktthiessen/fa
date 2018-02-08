#include <iostream>
#include <string>
#include <vector>

std::vector< std::string > evaluateArguments( int const & argc, char const * const argv[] )
{
    std::vector< std::string > fileNames;

    if ( argc > 0 )
        fileNames.push_back( argv[ 0 ] );

    if ( argc > 1 )
        fileNames.push_back( argv[ 1 ] );

    if ( argc > 2 )
        fileNames.push_back( argv[ 2 ] );

    if ( argc == 2 )
        std::cout << "syntax: " << argv[0] << " " << argv[1] << " <output file name>" << std::endl;

    if ( argc == 1 )
        std::cout << "syntax: " << argv[0] << " <input file name> <output file name>" << std::endl;

    return fileNames;
}

void loadInput( std::string const & fileName )
{
    std::cout << "input: " << fileName << std::endl;
}

void generateResults()
{
}

void saveResults( std::string const & fileName )
{
    std::cout << "output: " << fileName << std::endl;
}

int main( int argc, char * argv[] )
{
    std::vector< std::string > fileNames = evaluateArguments( argc, argv );

    if ( fileNames.size() < 3 )
        return 1;

    loadInput( fileNames[ 1 ] );
    generateResults();
    saveResults( fileNames[ 2 ] );
    return 0;
}

