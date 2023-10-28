#include <iostream>
using namespace std;

// Returning reference which gets deleted after call and leds to Segmentation Fault
int &Sum(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    int c = Sum(3, 4);
    cout << c << endl;
    return 0;
}