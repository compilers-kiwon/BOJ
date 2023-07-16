#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  S,result;

    cin>>N>>S;

    for(int i=0;i<N;i++)
    {
        if( result.empty() ||
                result.back()!=S[i] )
        {
            result.push_back(S[i]);
        }
        else
        {
            result.back() = toupper(result.back());
            result.push_back(toupper(S[i]));
        }
    }

    cout<<result<<'\n';
    return  0;
}