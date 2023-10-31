#include    <iostream>

using namespace std;

int simulate(int a,int b)
{
    int ret = 0;
    
    ret++,b--;

    if (a > b) ret+=b+b+1;
    else ret+=a+a;
    
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X,Y;
    
    cin>>X>>Y;
    cout<<max(simulate(X,Y),simulate(Y,X))<<'\n';
    
    return  0;
}