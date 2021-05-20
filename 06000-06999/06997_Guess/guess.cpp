#include    <iostream>
#include    <string>

using namespace std;

#define DIGIT_LEN   4
#define IGNORE      ' '

int count_circle(string& s,string& g)
{
    int ret = 0;

    for(int i=0;i<DIGIT_LEN;i++)
    {
        if( s[i] == g[i] )
        {
            ret++;
            s[i] = g[i] = IGNORE;
        }
    }

    return  ret;
}

int count_square(const string& s,const string& g)
{
    int s_cnt[0x100],g_cnt[0x100];

    for(char c='0';c<='9';c++)
    {
        s_cnt[c] = g_cnt[c] = 0;
    }

    for(int i=0;i<DIGIT_LEN;i++)
    {
        if( s[i] != IGNORE )
        {
            s_cnt[s[i]]++;
        }

        if( g[i] != IGNORE )
        {
            g_cnt[g[i]]++;
        }
    }

    int ret = 0;

    for(char c='0';c<='9';c++)
    {
        ret += min(s_cnt[c],g_cnt[c]);
    }

    return  ret;
}

void    input(string& s,string& g)
{
    cin>>s>>g;

    if( s.length() < DIGIT_LEN )
    {
        s.insert(0,DIGIT_LEN-s.length(),'0');
    }

    if( g.length() < DIGIT_LEN )
    {
        g.insert(0,DIGIT_LEN-g.length(),'0');
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int     cnt_of_circles,cnt_of_squares;
        string  secret,guess;

        input(secret,guess);
        cout<<"For secret = "<<secret<<" and guess = "<<guess<<", ";

        cnt_of_circles = count_circle(secret,guess);
        cnt_of_squares = count_square(secret,guess);

        cout<<cnt_of_circles<<" circles and "<<cnt_of_squares<<" squares will light up.\n";
    }

    return  0;
}