#include <iostream>
#include <string>
#include <vector>
int main(int argc, char* argv[])
{
    // Convert comand line arguments to vector of strings
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };
    // Loop over all comand line arguments and outputs and print out. size_t is a 
    // special data type...? Better than using int i to itterate.
    // Check if common options are given and output the expected responce.
    bool option_given{false};
    for (size_t i{0}; i < cmdLineArgs.size(); i++)
    { 
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help")
            {
                std::cout << "Usage: dsada" << std::endl;
            }
        if (cmdLineArgs[i] == "--version")
            {
                std::cout << "Version 1.0" << std::endl;
            }
        if (cmdLineArgs[i] == "-i")
        {
            if (i==cmdLineArgs.size()-1)
            {
                std::cout << "ERROR - If option flag given there must be a following argument" << std::endl;
                return 0;
            }
            else
            {
                std::cout << cmdLineArgs[i+1] << std::endl;
                option_given = true;
            }
        }
        if (cmdLineArgs[i]=="-o")
        {
            if (i==cmdLineArgs.size()-1)
            {
                std::cout << "ERROR" << std::endl;
                return 0;
            }
            else
            {
                std::cout << cmdLineArgs[i+1] << std::endl;
                option_given = true;
            }
        }
        if (option_given)
        {
            option_given=false;
            continue;
        }

    }
    
    char in_char{'x'};
    std::string out_str{""};

    // Take each letter from user input and in each case:
    while(std::cin >> in_char)
    {
        // Check if character is alphabetic
        if (std::isalpha(in_char))
        {
            // - Convert to upper case
           out_str += std::toupper(in_char); 
           continue;
        }
        
        // - Change numbers to words
        switch (in_char)
        {
            case '0':
                out_str += "ZERO";
                break;
            case '1':
                out_str += "ONE";
                break;
            case '2':
                out_str += "TWO";
                break;
            case '3':
                out_str += "THREE";
                break;
            case '4':
                out_str += "FOUR";
                break;
            case '5':
                out_str += "FIVE";
                break;
            case '6':
                out_str += "SIX";
                break;
            case '7':
                out_str += "SEVEN";
                break;
            case '8':
                out_str += "EIGHT";
                break;
            case '9':
                out_str += "NINE";
                break;
            default:
                break;

        }
        // - Ignore any other (non-alpha) characters
    }
    // print out the new string. CTRL-D ends while loop. (Means exit())
    std::cout << out_str << std::endl;
}
