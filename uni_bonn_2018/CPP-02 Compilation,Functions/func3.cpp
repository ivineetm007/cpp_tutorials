#include <iostream>
using namespace std;

int Sum(int &a, int b)
{
    a = 10;
    return a + b;
}

int main()
{
    int a = 1;
    a = Sum(a, 2);
    cout << a << endl;
    return 0;
}