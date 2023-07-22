#include    <iostream>
#include    <string>

using namespace std;

#define convert(str,len) \
    ((str)=string((len)-(str).length(),'0')+(str))

#define is_large(c1,c2) ((c1)>='7'&&(c2)>='7')
#define is_small(c1,c2) ((c1)<='2'&&(c2)<='2')

string  dexor(const string& n1,const string& n2)
{
    string  ret;

    for(int i=0;i<n1.length();i++)
    {
        char d1 = n1[i];
        char d2 = n2[i];

        if( is_large(d1,d2) || is_small(d1,d2) )
        {
            ret.push_back('0');
        }
        else
        {
            ret.push_back('9');
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  n1,n2;

    cin>>n1>>n2;

    convert(n1,max(n1.length(),n2.length()));
    convert(n2,max(n1.length(),n2.length()));

    cout<<dexor(n1,n2)<<'\n';
    return  0;
}