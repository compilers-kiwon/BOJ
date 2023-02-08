#include    <iostream>

using namespace std;

#define PASSWORD    "ILOVEYONSEI"

int get_distance(char c)
{
    int ret = 0;
    const char* p = PASSWORD;

    for(int i=0;p[i]!='\0';i++)
    {
        ret += max(p[i],c)-min(p[i],c);
        c = p[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char    c;

    cin>>c;
    cout<<get_distance(c)<<'\n';

    return  0;
}