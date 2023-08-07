#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define IN  '+'
#define OUT '-'

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int q,cnt;
    map<string,int> present;
    map<string,int>::iterator it;

    cin>>q;
    cnt = 0;

    for(int i=1;i<=q;i++)
    {
        string  name;
        char    state;

        cin>>name>>state;

        if( state == IN )
        {
            present[name]++;
        }
        else
        {
            if( (it=present.find(name)) != present.end() )
            {
                if( (--it->second) == 0 )
                {
                    present.erase(it);
                }
            }
            else
            {
                cnt++;
            }
        }
    }

    for(it=present.begin();it!=present.end();it++)
    {
        cnt += it->second;
    }

    cout<<cnt<<'\n';
    return  0;
}