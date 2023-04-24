#include    <iostream>
#include    <string>

using namespace std;

#define char2int(c) ((int)((c)-'0'))
#define int2char(n) ((char)((n)+(int)'0'))

int convert_to_base(const string& num,
                    int base,string& converted)
{
    int     current = 0;
    string  result;
    bool    all_zero = true;

    for(int i=0;i<num.length();i++)
    {
        current = current*10+char2int(num[i]);

        if( current < base )
        {
            if(!result.empty()) result.push_back('0');
            continue;
        }

        if( current/base != 0 )
        {
            all_zero = false;
        }

        result.push_back(int2char(current/base));
        current %= base;    
    }

    converted.push_back(int2char(current));
    
    return  (all_zero==true)?0:convert_to_base(result,base,converted);
}

int is_palindrome(const string& str)
{
    for(int h=0,t=str.length()-1;h<t;h++,t--)
    {
        if( str[h] != str[t] )
        {
            return  0;
        }
    }

    return  1;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  n;
    bool    printed = false;

    cin>>n;

    for(int b=2;b<=10;b++)
    {
        string  converted;

        if( b != 10 )
        {
            convert_to_base(n,b,converted);
        }
        else
        {
            converted = n;
        }

        if( is_palindrome(converted) )
        {
            cout<<b<<' '<<converted<<'\n';
            printed = true;
        }
    }

    if( printed == false )
    {
        cout<<"NIE\n";
    }

    return  0;
}