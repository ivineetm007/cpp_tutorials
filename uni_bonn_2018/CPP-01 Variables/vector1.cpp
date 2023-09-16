#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2};
    std::cout << "Len of vector:" << vec.size() << std::endl;
    std::cout << "Front element:" << vec.front() << std::endl;
    std::cout << "Back element:" << vec.back() << std::endl;
    std::cout << "Pushing back an integer 10" << std::endl;
    vec.push_back(10);
    std::cout << "Len of vector:" << vec.size() << std::endl;
    std::cout << "Back element:" << vec.back() << std::endl;
    std::cout << "Pushing back an double 3.2" << std::endl;
    vec.push_back(3.2);
    std::cout << "Back element:" << vec.back() << std::endl;
    return 0;
}
