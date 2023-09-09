#include <iostream>
int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cerr << "Hello Error World!" << std::endl; // stderr is faster than stdout (buffered)
    return 0;
}
