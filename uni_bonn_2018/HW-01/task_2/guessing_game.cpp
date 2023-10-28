#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));          // use current time as seed for random generator
    int random_variable = std::rand() % 100; // Random number within [0,99]
    int guess = -1;
    while (true)
    {
        std::cout << "Guess a number between 0 and 99\n";
        std::cin >> guess;
        if (guess == random_variable)
        {
            std::cout << "Guessed it right. You won!\n";
            break;
        }
        else if (guess < random_variable)
        {
            std::cout << "Your number is smaller. Try again!\n";
        }
        else
        {
            std::cout << "Your number is larger. Try again!\n";
        }
    }
    return 1;
}