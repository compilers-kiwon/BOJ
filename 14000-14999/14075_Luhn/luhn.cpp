#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define chr2int(c)  ((int)((c)-'0'))

void    get_numbers(const string& str,vector<int>& num)
{
    for(int i=0;i<str.length();i++)
    {
        num.push_back(chr2int(str[i]));
    }
}

void    make_double(vector<int>& num)
{
    for(int i=0;i<num.size();i++)
    {
        if( i%2 == 0 )
        {
            num[i] *= 2;

            if( num[i] >= 10 )
            {
                num[i] = num[i]/10+num[i]%10;
            }
        }
    }
}

int     get_sum(vector<int>& num)
{
    int ret = 0;

    for(int i=0;i<num.size();i++)
    {
        ret += num[i];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string      str;
    vector<int> num;

    cin>>str;
    get_numbers(str,num);

    make_double(num);
    cout<<((get_sum(num)%10==0)?"DA":"NE")<<'\n';

    return  0;
}