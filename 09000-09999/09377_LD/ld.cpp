#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>

using namespace std;

#define NONE        0
#define EMPTY_STR   1
#define DUPLICATED  2


void    reverse_str(string& str)
{
    for(int h=0,t=str.length()-1;h<t;h++,t--)
    {
        swap(str[h],str[t]);
    }
}

bool    input(vector<string>& w)
{
    int n;

    cin>>n;

    if( n == 0 )
    {
        return  false;
    }

    for(int i=1;i<=n;i++)
    {
        string  str;

        cin>>str;

        reverse_str(str);
        w.push_back(str);
    }

    return  true;
}

int do_string_ld(vector<string>& words)
{
    int ret;

    for(ret=0;;ret++)
    {
        int result = NONE;
        map<string,int> cnt;

        for(int i=0;i<words.size();i++)
        {
            string& w = words[i];

            if( w.length() == 1 )
            {
                result = EMPTY_STR;
                break;
            }

            w.pop_back();

            if( cnt[w] != 0 )
            {
                result = DUPLICATED;
                break;
            }

            cnt[w]++;
        }

        if( result != NONE )
        {
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        vector<string>  w;

        if( input(w) == false )
        {
            break;
        }

        cout<<do_string_ld(w)<<'\n';
    }

    return  0;
}