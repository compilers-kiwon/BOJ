#include <iostream>

using namespace std;

int main(void)
{
    int A,B,C,D,P;
    int X,Y;
    
    cin>>A>>B>>C>>D>>P;
    
    X = A*P;
    Y = B;
    
    if( (P-C)>0 )
    {
        Y += (P-C)*D;
    }
    
    if( X < Y )
    {
        cout<<X<<endl;
    }
    else
    {
        cout<<Y<<endl;
    }
    
    return 0;
}
