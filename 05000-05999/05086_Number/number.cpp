#include    <iostream>

using namespace std;

int main(void)
{
    while(1)
    {
        int    n1,n2;
        
        cin>>n1>>n2;
        
        if( n1 == 0 && n2 == 0 )
        {
            break;
        }
        
        if( n2%n1 == 0 )
        {
            cout<<"factor\n";
        }
        else if( n1%n2 == 0 )
        {
            cout<<"multiple\n";
        }
        else
        {
            cout<<"neither\n";
        }
    }
    return    0;
}
