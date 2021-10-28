#include <iostream>

class NumConverter
{
    public:
        //Constructor. Initializes the number variable and calls the Controller function.
        NumConverter(long num);

        // Controller is used to determine which function needs to be called to print the numbers.
        void Controller(long number);

        // Ones are used to print out single digit numbers 0-9.
        void ones(long number);

        // Tens are used to print out double-digit numbers excluding 10-19.
        void tens(long number);

        // Teens are used to print the numbers 10-19.
        void teens(long number);

        // LargeValuePrint is used to print all numbers in the hundreds and greater.
        void LargeValuePrint(long number, int num, std::string n);

    private:
        // Used to store the number that was entered by the user.
        // This also needs to be a long, so it can support the negative int when it is turned positive, as int ranges are 2,147,483,647 through -2,147,483,648.
        long number;
        
        // The following three constant string arrays are used for printing the user entered numbers.
        const std::string m_ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        const std::string m_teens[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        const std::string m_tens[8] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
};