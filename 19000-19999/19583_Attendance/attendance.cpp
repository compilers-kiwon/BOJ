#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         cnt;
    string      S,E,Q;
    set<string> attended;

    cin>>S>>E>>Q;

    for(cnt=0;;)
    {
        string  time,name;

        cin>>time>>name;

        if( time.empty() )
        {
            break;
        }

        if( time <= S )
        {
            attended.insert(name);
            continue;
        }

        if( time>=E && time <=Q )
        {
            set<string>::iterator   it = attended.find(name);

            if( it != attended.end() )
            {
                cnt++;
                attended.erase(it);
            }

            continue;
        }
    }

    cout<<cnt<<'\n';

    return  0;
}