#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM_OF_COFFEE   2

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,cnt,c;
    string  str;

    c = cnt = 0;
    cin>>n>>str;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == '1' )
        {
            cnt++;
            c = MAX_NUM_OF_COFFEE;
        }
        else
        {
            if( c != 0 )
            {
                cnt++;
                c--;
            }
        }
    }

    cout<<cnt<<'\n';
    return  0;
}