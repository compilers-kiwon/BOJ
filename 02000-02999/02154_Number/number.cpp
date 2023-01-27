#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

string  get_number(queue<char>& buf)
{
    string  ret;

    for(int i=1,size=buf.size();i<=size;i++)
    {
        char    c = buf.front();

        ret.push_back(c);
        buf.pop();buf.push(c);
    }

    return  ret;
}

int     push(char c,queue<char>& buf,int max_size)
{
    int ret = 0;

    if( buf.size() == max_size )
    {
        buf.pop();
        ret = 1;
    }

    buf.push(c);

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,prev,found;
    string      str;
    queue<char> buf;

    cin>>N;
    prev = found = 0;
    str = to_string(N);
    
    for(int i=1;i<=N;i++)
    {
        string  num;

        num = to_string(i);
        
        for(int p=0;p<num.length();p++)
        {
            prev += push(num[p],buf,str.length());
            
            if( buf.size()==str.length() &&
                num[p]==str.back() && get_number(buf)==str )
            {
                found = prev+1;
                break;
            }
        }

        if( found != 0 )
        {
            break;
        }
    }

    cout<<found<<'\n';

    return  0;
}