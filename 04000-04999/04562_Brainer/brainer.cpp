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
        int X,Y;

        cin>>X>>Y;
        cout<<(X>=Y?"MMM BRAINS\n":"NO BRAINS\n");
    }

    return  0;
}
