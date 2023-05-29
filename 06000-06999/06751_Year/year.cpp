#include    <iostream>
#include    <string>

using namespace std;

bool    is_distinct(string year)
{
    int     cnt = 0;
    bool    visited[0x100] = {false,};

    for(int i=0;i<year.length();i++)
    {
        if( visited[year[i]] == false )
        {
            cnt++;
            visited[year[i]] = true;
        }
    }

    return  (year.length()==cnt);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Y;

    cin>>Y;

    for(;;)
    {
        if( is_distinct(to_string(++Y)) )
        {
            cout<<Y<<'\n';
            break;
        }
    }

    return  0;
}