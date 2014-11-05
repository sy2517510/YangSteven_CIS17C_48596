#include <iostream>

using namespace std;

float savings(float, float, int);
int sum(int*, int);

int main()
{
    int array[4] = {4, 8, 2, 7};
    
    cout<< "Amount in savings is: " << savings(2500, .04, 3) << endl;
    cout << "The sum is: " << sum(array, 4);
   
    return 0;
}

float savings(float pv, float i, int n)
{
    if(n == 0) return pv;
    
    return savings(pv * (1+i), i, n-1);
}

int sum(int * a, int n)
{
    if(n == 1) return a[0];
    
    return  a[0] + sum(a + 1, n-1);
}

