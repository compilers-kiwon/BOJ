#include    <iostream>
#include    <string>

using namespace std;

const string open_door[2] = {"01010","10101"};

int main(void)
{
    int S;
    long long int   N;

    cin>>N>>S;

    if( N > 5)
    {
        cout<<"Love is open door\n";
        return  0;
    }

    for(int i=1;i<N;i++)
    {
        cout<<open_door[S][i]<<'\n';
    }

    return  0;
}