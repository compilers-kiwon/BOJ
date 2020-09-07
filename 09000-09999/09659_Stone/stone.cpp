#include <iostream>

using namespace std;

int main(void)
{
    unsigned long long N;
    
    cin>>N;
    
    if( N%2 == 1 )
    {
        cout<<"SK\n";
    }
    else
    {
        cout<<"CY\n";
    }
    
    return 0;
}
