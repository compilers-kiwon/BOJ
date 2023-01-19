#include    <iostream>
#include    <string>

using namespace std;

int     get_sum_of_digits(int n)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        ret += n%10;
    }

    return  ret;
}

void    print(const string& str)
{
    for(int i=0;i<str.length();i++)
    {
        int n = get_sum_of_digits((int)str[i]);

        for(int j=0;j<n;j++)
        {
            cout<<str[i];
        }

        cout<<'\n';
    }
}

void    input(string& str)
{
    cin>>str;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    input(str);
    print(str);

    return  0;
}