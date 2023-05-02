#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_LEN 3000000
 
static int  r1[MAX_LEN],r2[MAX_LEN];

#define max_len(s1,s2)  (max((s1).length(),(s2).length()))

int compare_number(const int n1[],const int n2[],const int length)
{
    int ret = '=';

    for(int i=length-1;i>=0;i--)
    {
        if( n1[i] != n2[i] )
        {
            ret = (n1[i]>n2[i])?'>':'<';
            break;
        }
    }

    return  ret;
}

int calculate(const string& str,int ret[],int length)
{
    int pos = 0;

    fill(ret,ret+length,0);

    for(int i=0;i<str.length();i++)
    {
        switch(str[i])
        {
            case    '(':
                pos += (str[i+1]=='(')?1:0;
                ret[pos] += (str[i+1]==')')?1:0;
                i += (str[i+1]==')')?1:0;
                break;
            case    ')':
                pos--;break;
            default:
                // do nothing
                break;
        }
    }

    for(int i=0;i<str.length();i++)
    {
        ret[i+1] += ret[i]/2;
        ret[i] %= 2;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  f1,f2;

        cin>>f1>>f2;

        calculate(f1,r1,max_len(f1,f2));
        calculate(f2,r2,max_len(f1,f2));

        cout<<(char)compare_number(r1,r2,max_len(f1,f2))<<'\n';
    }

    return  0;
}