#include    <iostream>
#include    <string>

using namespace std;

int input(string& s1,string& s2)
{
    int N;

    cin>>N>>s1>>s2;
    return  0;
}

int verify_dyslexia(const string& original,
                        const string& rewritten)
{
    int ret = 0;

    for(int i=0;i<original.length();i++)
    {
        ret += (original[i]==rewritten[i])?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  original,rewritten;

    input(original,rewritten);
    cout<<verify_dyslexia(original,rewritten)<<'\n';

    return  0;
}