#include    <iostream>

using namespace std;

#define NUM_OF_CONNECTION_POINTS    5

void    input(int* c)
{
    for(int i=1;i<=NUM_OF_CONNECTION_POINTS;i++)
    {
        cin>>c[i];
    }
}

bool    is_compatible(int* c1,int* c2)
{
    for(int i=1;i<=NUM_OF_CONNECTION_POINTS;i++)
    {
        if( c1[i] == c2[i] )
        {
            return  false;
        }
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int c1[NUM_OF_CONNECTION_POINTS+1],c2[NUM_OF_CONNECTION_POINTS+1];

    input(c1);input(c2);
    cout<<(is_compatible(c1,c2)?'Y':'N')<<'\n';

    return  0;
}