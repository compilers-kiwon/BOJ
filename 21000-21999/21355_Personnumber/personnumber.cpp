#include    <iostream>
#include    <string>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define LOWER_YEAR          1840
#define UPPER_YEAR          2019
#define MID_POS             6

int str2int(string s)
{
    int ret = 0;

    for(int i=0;i<s.length();i++)
    {
        ret = ret*10+(int)(s[i]-'0');
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  number;

    cin>>number;

    for(int year=LOWER_YEAR;year<=UPPER_YEAR;year++)
    {
        char    c = (IN_RANGE(1820,year,1919)?'+':'-');

        if( c==number[MID_POS]
            && year%100==str2int(number.substr(0,2)) )
        {
            cout<<year<<number.substr(2,4)
                <<number.substr(MID_POS+1,4)<<'\n';
            break;
        }
    }

    return  0;
}