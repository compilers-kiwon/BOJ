#include    <iostream>
#include    <string>

using namespace std;

int count(int num,char digit)
{
    int ret,pos;

    ret = pos = 0;

    for(string str=to_string(num);
            (pos=str.find(digit,pos))!=string::npos;pos++,ret++);
    
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     from,to,cnt;
    char    d;

    cin>>from>>to>>d;
    cnt = 0;

    for(int i=from;i<=to;i++)
    {
        cnt += count(i,d);
    }

    cout<<cnt<<'\n';

    return  0;
}