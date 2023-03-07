#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N;
    string          S;
    vector<string>  m;

    cin>>N>>S;

    for(int cnt=0;;)
    {
        string  n,c;

        cin>>n>>c;

        if( n == S )
        {
            for(int i=0;i<m.size();i++)
            {
                if( m[i] == c )
                {
                    cnt++;
                }
            }

            cout<<cnt<<'\n';
            break;
        }

        m.push_back(c);
    }

    return  0;
}