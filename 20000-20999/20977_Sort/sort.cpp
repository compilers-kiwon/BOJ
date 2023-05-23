#include    <iostream>
#include    <string>

using namespace std;

#define JOI "JOI"

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  S;

    cin>>N>>S;

    for(int i=0;i<string(JOI).length();i++)
    {
        for(int j=0;j<N;j++)
        {
            if( string(JOI)[i] == S[j] )
            {
                cout<<S[j];
            }
        }
    }

    cout<<'\n';
    return  0;
}