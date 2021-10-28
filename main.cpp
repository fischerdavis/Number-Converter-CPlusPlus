#include "NumConverter.h"

int main()
{
    // Following three lines used to take in user input.
    std::string input;
    bool notnum = false;

    std::cout << "NumConverter>";
    std::cin  >> input; 

    // Used to check if input is valid i.e. doesn't contain any characters other than '-'.
    for (int i = 0; i < input.length(); i++)
    {
        if(!isdigit(input.at(i)))
        {
            if(i > 0 || input.at(0) != '-')
            {
                std::cout << "Invalid Input\n";
                notnum = true;
                break;
            }
        }
    }

    // UserInput stores the converted string to int value.
    int UserInput = 0;

    // If statement used to try and convert the string into an int value, and will reject if not a 32-bit int.
    if(notnum == false)
    {
        try
        {
            UserInput = stoi(input);
        }
        catch(...)
        {
            std::cout << "Invalid Input\n";
            notnum = true;
        }
    }

    // Checks to see if the input is still valid after converting it into an int then creates and calls the object Convert to convert the number to english.
    if(notnum == false)
    {
        NumConverter Convert(UserInput);
        std::cout << std::endl;
    }

    return 0;
}