#include "NumConverter.h"

// Constructor
NumConverter::NumConverter(long input){

    // Assigns the number variable with the user input.
    number = input;

    // Calls the Controller function to start converting the user entered number.
    Controller(number);
}

void NumConverter::Controller(long num)
{
    // This if statement is used to print negative if the user input a negative number, then converts it to a positive in order to print the number.
    if(number < 0)
    {
        std::cout << "negative ";
        number *= -1;   // Sets the stored number as a positive number.

        // This is needed because it sets the number that will be used in the if/else if statements to positive.
        num *= -1;      // Sets the passed in number to a positive.
    }

    // The following if/else statements are used to determine which function to call to print the number depending on how big the number is.
    if(num < 10)
    {
        ones(num);
    }
    else if(num < 20)
    {
        teens(num);
    }
    else if(num < 100)
    {
        tens(num);
    }
    else if(num < 1000)
    {
        LargeValuePrint(num, 100, "hundred");
    }
    else if(num < 1000000)
    {
        LargeValuePrint(num, 1000, "thousand");
    }
    else if(num < 1000000000)
    {
        LargeValuePrint(num, 1000000, "million");
    }
    else if(num <= 2147483648)
    {
        LargeValuePrint(num, 1000000000, "billion");
    } 
}

void NumConverter::ones(long number)
{
    // Prints out a number from the ones string array, and deducts itself from the number, which is used in the case for larger numbers so the number isn't printed repeatedly.
    std::cout << m_ones[number] << " ";
    number -= number;
}

void NumConverter::tens(long number)
{
    // Place used to find the location in the array for printing and also used for printing the single digits in case the number contains ones i.e. 43, 41, 23, and not i.e 20, 30, 40, 50.
    int place = (number / 10);

    std::cout << m_tens[place - 2] << " ";

    // This equation gets the ones place if there are any such as 43 will set number equal to 3.
    number -= place*10;

    // Calls the ones function in case the number includes ones for example: 21, 43, 55.
    if(number > 0)
    {
        ones(number);
    }

}

void NumConverter::teens(long number)
{
    // This will find and print the teens number including 10 to the user and subtract it from number.
    std::cout << m_teens[number - 10] << " ";
    number -= number;
}

void NumConverter::LargeValuePrint(long number, int num, std::string n)
{
    // This is used to take off the first 1-3 digits to further break them down to print for the user.
    // i.e. for the number 343,265 it will return 343
    long stored = number / num;

    // This stores the string that was passed in from the function which could be "hundreds", "millions", "billions".
    std::string s = n;

    // This take the number previously calculated above then subtract it from the total.
    // i.e. from number above it will be 343,265 - 343,000.
    number -= (stored*num);

    // Calls the Controller function as the number will need to be broken down more a number that is one billion may also contain three hundred million.
    Controller(stored);

    std::cout << s << " ";

    // This is used when the remainder is zero, so a zero doesn't get printed.
    if(number % num != 0)
    {
        Controller(number);
    }
}