#include <iostream>

using namespace std;

int savings(float, float, int);

int main()
{
    
    cout<< "Amount in savings is: " << sum(2500, .04, 3) << endl;
   
    return 0;
}

int savings(float pv, float i, int n)
{
    if(n == 0) return pv;
    
    return savings(pv * (1+i), i, n-1);
}


