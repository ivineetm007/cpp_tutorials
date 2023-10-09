#include <iostream>
using namespace std;

int Sum(int a, int b);

int main()
{
    int c = Sum(3, 4);
    cout << c << endl;
    return 0;
}

int Sum(int a, int b)
{
    int c = a + b;
    return c;
}
