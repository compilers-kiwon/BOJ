#include    <iostream>
#include    <string>

using namespace std;

#define MAX_BASE    36

const string    base_symbol = " 123456789abcdefghijklmnopqrstuvwxyz0";

typedef unsigned long long  uint64;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

uint64  char2uint64(const char c)
{
    uint64  ret;

    if( IN_RANGE('0',c,'9') )
    {
        ret = c-'0';
    }
    else
    {
        ret = (c-'a')+10;
    }

    return  ret;
}

uint64  find_max_symbol(const string& str)
{
    uint64  ret = 0;
    bool    zero = false;

    for(int i=0;i<str.length();i++)
    {
        uint64  s = char2uint64(str[i]);

        if( s == 0 )
        {
            zero = true;
        }

        ret = max(ret,s);
    }

    if( !(ret==1 && zero==false) )
    {
        ret++;
    }

    return  ret;
}

uint64  str2uint64(const string& str,const uint64 b)
{
    uint64  ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*b+char2uint64(str[i]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int n=1;n<=N;n++)
    {
        string  s,X,Y,Z;
        char    op,eq;
        uint64  x,y,z,s_base;

        cin>>X>>op>>Y>>eq>>Z;
        s_base = max(find_max_symbol(X),max(find_max_symbol(Y),find_max_symbol(Z)));
        
        for(uint64 b=s_base;b<=MAX_BASE;b++)
        {
            uint64  left,right;

            x = str2uint64(X,b);
            y = str2uint64(Y,b);
            z = str2uint64(Z,b);
            
            if( !IN_RANGE(0,x,0xFFFFFFFFUL) || !IN_RANGE(0,y,0xFFFFFFFFUL) || !IN_RANGE(0,z,0xFFFFFFFFUL) )
            {
                continue;

            }

            switch(op)
            {
                case    '+':
                    left = x+y;
                    right = z;
                    break;
                case    '*':
                    left = x*y;
                    right = z;
                    break;
                case    '/':
                    left = x;
                    right = z*y;
                    break;
                default:
                    left = x;
                    right = z+y;
                    break;
            }
            
            if( left == right )
            {
                s.push_back(base_symbol[(int)b]);
            }
        }

        if( s.empty() )
        {
            cout<<"invalid\n";
        }
        else
        {
            cout<<s<<'\n';
        }
    }
    
    return  0;
}