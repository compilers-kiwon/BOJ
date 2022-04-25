#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

int             N;
string          str;
map<char,int>   table;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_len,head,tail;

    cin>>N>>str;
    head = tail = 0;
    table[str[head]] = 1;

    for(max_len=0;;)
    {
        if( table.size() <= N )
        {
            max_len = max(max_len,tail-head+1);

            if( tail+1 < str.length() )
            {
                table[str[++tail]]++;
            }
            else
            {
                break;
            }
        }
        else
        {
            char    removed = str[head++];

            if( --table[removed] == 0 )
            {
                table.erase(removed);
            }
        }
    }

    cout<<max_len<<'\n';

    return  0;
}