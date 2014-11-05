#include <iostream>

using namespace std;

int sum(float, float, int);

int main()
{
    
    cout<<"The sum is: " << sum(2500, .04, 3) << endl;
   
    return 0;
}

int sum(float pv, float i, int n)
{
    if(n == 0) return pv;
    
    return sum(pv * (1+i), i, n-1);
}


