#include    <iostream>
#include    <string>

using namespace std;

#define NONE    -1

int write_number(int s,const string& written)
{
    int ret;

    for(int i=s,pos=0;pos<written.length();i++)
    {
        string  num = to_string(i);
        string  sub = written.substr(pos,
                    min(num.length(),written.length()-pos));

        if( num != sub )
        {
            ret = NONE;
            break;
        }

        ret = i;
        pos += num.length();
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     A,B;
    string  S;

    cin>>S;

    for(A=1;;A++)
    {
        if( (B=write_number(A,S)) != NONE )
        {
            break;
        }
    }

    cout<<A<<' '<<B<<'\n';

    return  0;
}