#include    <iostream>
#include    <vector>
#include    <string>
#include    <cmath>

using namespace std;

#define MAX_LEN 15

typedef long long int   int64;

int64   dec2oct(int64 dec)
{
    int64   sign = (dec<0)?-1:1;
    int64   ret = 0;
    vector<int64> n;

    for(dec=dec*sign;dec>0;dec/=8)
    {
        n.push_back(dec%8);
    }

    for(;!n.empty();n.pop_back())
    {
        ret = ret*10+n.back();
    }

    return  ret*sign;
}

int parse(string& str,int& A,int& B,char& op)
{
    op = ' ';

    for(int i=1;i<str.length();i++)
    {
        if( !isdigit(str[i]) )
        {
            swap(op,str[i]);
            break;
        }
    }

    char    n1[MAX_LEN],n2[MAX_LEN];
    string  o1,o2;

    sscanf(str.c_str(),"%s %s",n1,n2);

    o1 = string(n1);
    o2 = string(n2);

    A = stoi(o1,nullptr,8);
    B = stoi(o2,nullptr,8);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     A,B;
    char    op;
    string  str;

    cin>>str;
    parse(str,A,B,op);

    switch(op)
    {
        case    '+':
            cout<<dec2oct((int64)A+(int64)B)<<'\n';
            break;
        case    '*':
            cout<<dec2oct((int64)A*(int64)B)<<'\n';
            break;
        case    '/':
            if( B == 0 )
            {
                cout<<"invalid\n";
            }
            else
            {
                int64   diff = 0;

                if( (A<0 && B>0) || (A>0 && B<0) )
                {
                    diff = (abs(A)%abs(B))?-1:0;
                }

                cout<<dec2oct((int64)A/(int64)B)+diff<<'\n';
            }
            break;
        case    '-':
            cout<<dec2oct((int64)A-(int64)B)<<'\n';
            break;
        default:
            // do nothing
            break;
    }

    return  0;
}