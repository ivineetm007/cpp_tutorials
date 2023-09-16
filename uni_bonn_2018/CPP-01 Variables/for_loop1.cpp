#include <iostream>

int main()
{
    bool num = true;
    const int kIterCount = 10;
    int i = 2;
    std::cout << "i before loop:" << i << std::endl;
    for (i = 0; i < kIterCount; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "i after loop:" << i << std::endl;
    return 0;
}