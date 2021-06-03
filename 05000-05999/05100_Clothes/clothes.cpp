#include    <iostream>
#include    <string>

using namespace std;

#define JOE         0
#define JEAN        1
#define JANE        2
#define JAMES       3
#define UNREADABLE  4
#define MAX_SIZE    5

int     str2int(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*10+(int)(str[i]-'0');
    }

    return  ret;
}

int     read_size(const string& str)
{
    if( str=="M" || str=="L" )
    {
        return  JOE;
    }

    if( str == "S" )
    {
        return  JAMES;
    }

    if( str != "X" )
    {
        if( str2int(str) >= 12 )
        {
            return  JEAN;
        }
        else
        {
            return  JANE;
        }
    }

    return  UNREADABLE;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int N,cnt[MAX_SIZE];

        cin>>N;

        if( N == 0 )
        {
            break;
        }

        fill(&cnt[0],&cnt[MAX_SIZE],0);

        for(int i=1;i<=N;i++)
        {
            string  size;

            cin>>size;
            cnt[read_size(size)]++;
        }

        for(int i=0;i<MAX_SIZE;i++)
        {
            cout<<cnt[i]<<' ';
        }
        cout<<'\n';
    }

    return  0;
}