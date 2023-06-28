#include    <iostream>

using namespace std;

int simulate(int climb,int fall,int height)
{
    int pos,num_of_days;

    for(pos=0,num_of_days=1;;num_of_days++)
    {
        pos += climb;
        if(pos>=height) break;
        pos -= fall;
    }

    return  num_of_days;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int a,b,h;

    cin>>a>>b>>h;
    cout<<simulate(a,b,h)<<'\n';

    return  0;
}