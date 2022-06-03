#include    <iostream>
#include    <string>

using namespace std;

#define LENGTH  4

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    string  s1,s2;

    n = 1;
    cin>>s1>>s2;

    for(int i=0;i<LENGTH;i++)
    {
        if( s1[i] != s2[i] )
        {
            n *= 2;
        }
    }

    cout<<n<<'\n';

    return  0;
}