#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  S;

    cin>>N>>S;

    for(size_t p=0;p<N;p+=3)
    {
        p = S.find("joi",p);

        if( p == string::npos )
        {
            break;
        }

        S[p+0] = 'J';
        S[p+1] = 'O';
        S[p+2] = 'I';
    }

    cout<<S<<'\n';
    return  0;
}