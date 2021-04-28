#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM     100
#define int2char(i) ((char)(i+(int)'0'))

int     n;
string  str,num[MAX_NUM+1];

void    int2str(int i)
{
    for(int t=i;t>0;t/=10)
    {
        num[i].push_back(int2char(t%10));
    }

    for(int h=0,t=num[i].length()-1;h<t;h++,t--)
    {
        swap(num[i][h],num[i][t]);
    }
}

void    init(void)
{
    for(int i=1;i<=n;i++)
    {
        int2str(i);
    }
}

int     find_missing_number(void)
{
    int ret;

    for(int i=1,ptr=0;i<=n;i++)
    {
        if( ptr>=str.length() || str.substr(ptr,num[i].length())!=num[i] )
        {
            ret = i;
            break;
        }

        ptr += num[i].length();
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>str;
    init();

    cout<<find_missing_number()<<'\n';

    return  0;
}