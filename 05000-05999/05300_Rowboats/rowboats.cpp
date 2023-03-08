#include    <iostream>

using namespace std;

#define BOAT_SIZE   6

int print(int from,int to,char last)
{
    for(int i=from;i<to;i++)
    {
        cout<<i<<' ';
    }

    cout<<"Go!"<<last;
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    
    for(int i=1;i<=N;i+=BOAT_SIZE)
    {
        print(i,min(i+BOAT_SIZE,N+1),
                (i+BOAT_SIZE<=N)?' ':'\n');
    }

    return  0;
}