#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int num;

        cin>>num;
        cout<<num<<' '<<num<<'\n';
    }

    return  0;
}