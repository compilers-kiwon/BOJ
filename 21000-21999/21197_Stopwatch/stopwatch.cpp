#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,time;

    cin>>N;
    time = 0;

    if( N%2 == 1 )
    {
        cout<<"still running\n";
        return  0;
    }

    for(int i=0;i<N;i+=2)
    {
        int t1,t2;

        cin>>t1>>t2;
        time += t2-t1;
    }

    cout<<time<<'\n';

    return  0;
}