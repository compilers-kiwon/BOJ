#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define TRUE    1
#define FALSE   0

#define MIN_NUM 2
#define MAX_NUM 9

const string keypad[MAX_NUM+1] = {
    "","","ABC","DEF","GHI","JKL",
    "MNO","PQRS","TUV","WXYZ"
};

int is_palindrome(const vector<int>& number)
{
    for(int h=0,t=number.size()-1;h<t;h++,t--)
    {
        if( number[h] != number[t] )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int get_upper_str(string& str)
{
    for(int i=0;i<str.length();i++)
    {
        str[i] = toupper(str[i]);
    }

    return  0;
}

int get_number(char c)
{
    int ret = 0;

    for(int i=MIN_NUM;i<=MAX_NUM;i++)
    {
        if( keypad[i].find(c) != string::npos )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string      str;
        vector<int> number;

        cin>>str;
        get_upper_str(str);

        for(int i=0;i<str.length();i++)
        {
            number.push_back(get_number(str[i]));
        }

        cout<<(is_palindrome(number)?"YES":"NO")<<'\n';
    }

    return  0;
}