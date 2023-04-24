#include    <iostream>
#include    <string>

using namespace std;

const static string allowed = "IOSHZXN";

#define is_allowed(c)   (allowed.find((c))!=string::npos)

int main(void)
{
    string  w;
    bool    ret = true;

    cin>>w;

    for(int i=0;i<w.length();i++)
    {
        if( !is_allowed(w[i]) )
        {
            ret = false;
            break;
        }
    }

    cout<<((ret==true)?"YES":"NO")<<'\n';

    return  0;
}