#include <iostream>
using namespace std;

int Sum(const int &a, int b)
{
    a = 10;
    return a + b;
}

int main()
{
    const int a = 1;
    int sum = Sum(a, 2);
    cout << a << endl;
    cout << sum << endl;
    return 0;
}