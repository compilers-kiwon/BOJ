#include    <iostream>
#include    <string>

using namespace std;

const string    lower = "abcdefghijklmnopqrstuvwxyz";

#define get_index(c)    ((int)((c)-'a'))
#define shift(c,s)      (lower[(get_index((c))+s)%lower.length()])

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

string  encode_str(const string& str,int num_of_shifts)
{
    string  ret;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( IN_RANGE('a',c,'z') )
        {
            c = shift(c,num_of_shifts);
        }

        ret.push_back(c);
    }

    return  ret;
}

int     get_num_of_possible_messages(const string& str)
{
    int ret = 0;

    for(int s=0;s<lower.length();s++)
    {
        string  m = encode_str(str,s);

        if( m.find('i') == string::npos )
        {
            ret++;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;
    int     num;

    getline(cin,str);
    num = get_num_of_possible_messages(str);

    if( num != 0 )
    {
        cout<<num<<'\n';
    }
    else
    {
        cout<<"impossible\n";
    }

    return  0;
}