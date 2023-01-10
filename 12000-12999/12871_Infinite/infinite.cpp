#include    <iostream>
#include    <string>

using namespace std;

int get_gcd(int a,int b)
{
    int big = max(a,b);
    int small = min(a,b);

    for(int mod=big%small;mod!=0;mod=big%small)
    {
        big=small;small=mod;
    }

    return  small;
}

int get_lcm(int a,int b)
{
    return  a*b/get_gcd(a,b);
}

string  build_str(const string& src,int required_length)
{
    string  ret;

    for(;ret.length()<required_length;ret+=src);

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s,t;
    int     length;

    cin>>s>>t;
    length = get_lcm(s.length(),t.length());

    cout<<(build_str(s,length)==build_str(t,length)?1:0)<<'\n';

    return  0;
}