#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;

    cin>>N>>S;

    for(int i=0;i<N-1;i++)
    {
        if( S[i+1] == 'J' )
        {
            cout<<S[i]<<'\n';
        }
    }

    return  0;
}