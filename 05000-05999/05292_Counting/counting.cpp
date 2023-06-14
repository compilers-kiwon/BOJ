#include    <iostream>

using namespace std;

#define is_multiple(n,m)    ((n)%(m)==0)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        if( !is_multiple(i,3) && !is_multiple(i,5) )
        {
            cout<<i<<(i==N?'\n':' ');
        }
        else
        {
            cout<<(is_multiple(i,3)?"Dead":"");
            cout<<(is_multiple(i,5)?"Man":"");
            cout<<'\n';
        }
    }

    return  0;
}