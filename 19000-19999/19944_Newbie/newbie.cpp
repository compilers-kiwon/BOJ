#include    <iostream>

using namespace std;

#define is_newbie(m)    ((m)==1||(m)==2)
#define is_oldbie(m,n)  ((m)<=(n))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;

    cin>>N>>M;

    if( is_newbie(M) )
    {
        cout<<"NEWBIE!\n";
    }
    else if( is_oldbie(M,N) )
    {
        cout<<"OLDBIE!\n";
    }
    else
    {
        cout<<"TLE!\n";
    }

    return  0;
}