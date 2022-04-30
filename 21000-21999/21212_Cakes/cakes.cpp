#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,num_of_cakes;

    cin>>N;
    num_of_cakes = 0x7FFFFFFF;

    for(int i=1;i<=N;i++)
    {
        int a,b;

        cin>>a>>b;
        num_of_cakes = min(num_of_cakes,b/a);
    }

    cout<<num_of_cakes<<'\n';

    return  0;
}