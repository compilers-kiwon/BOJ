#include    <iostream>
#include    <string>

using namespace std;

static int  cnt[0x100];

#define is_even(n)  ((n)%2==0)

int parse_string(const string& str)
{
    for(int i=0;i<str.length();i++)
    {
        cnt[str[i]]++;
    }

    return  0;
}

string  determine_string(void)
{
    int num_of_odds,num_of_evens;

    num_of_odds = num_of_evens = 0;

    for(char c='a';c<='z';c++)
    {
        if( cnt[c] == 0 )
        {
            continue;
        }

        is_even(cnt[c])?num_of_evens++:num_of_odds++;
    }

    return  (num_of_evens!=0&&num_of_odds!=0)?
                    "2":(num_of_evens==0)?"1":"0";
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;

    parse_string(str);
    cout<<determine_string()<<'\n';

    return  0;
}