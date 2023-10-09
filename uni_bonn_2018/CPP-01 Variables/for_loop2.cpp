#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<float> vec = {1.0f, 2.1f};
    // Standard iteration
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }

    // Range for loop
    for (float num : vec)
    {
        std::cout << num << std::endl;
    }

    // Since strings could be of variable length. Reference should be used
    // If we skip const, the actual string could be changed by reference
    std::vector<std::string> vec2 = {"Hello", "World"};
    for (const auto &st : vec2)
    {
        std::cout << st << std::endl;
    }

    // Iterating over single string
    for (const auto &c : vec2.front())
    {
        std::cout << c << std::endl;
    }
    return 0;
}