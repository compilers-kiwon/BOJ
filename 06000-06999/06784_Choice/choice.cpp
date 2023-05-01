#include    <iostream>
#include    <string>

using namespace std;

int input(string& s)
{
    int N;

    cin>>N;

    for(int i=0;i<2*N;i++)
    {
        char    c;

        cin>>c;
        s.push_back(c);
    }

    return  N;
}

int simulate(const string& s,int length)
{
    int ret = 0;

    for(int i=0;i<length;i++)
    {
        ret += (s[i]==s[i+length])?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     len;
    string  str;

    len = input(str);
    cout<<simulate(str,len)<<'\n';

    return  0;
}