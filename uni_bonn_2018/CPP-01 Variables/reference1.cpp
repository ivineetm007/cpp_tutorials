#include <iostream>

int main()
{
    int num = 0;
    // Cannot set it to number. rvalue can't be int
    int &num_ref = num;
    std::cout << num << " ref:" << num_ref << std::endl;
    num_ref = 7;
    std::cout << num << " ref:" << num_ref << std::endl;
    return 0;
}
