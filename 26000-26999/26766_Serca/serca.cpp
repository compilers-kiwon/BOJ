#include    <iostream>

using namespace std;

int print(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<" @@@   @@@ \n";
        cout<<"@   @ @   @\n";
        cout<<"@    @    @\n";
        cout<<"@         @\n";
        cout<<" @       @ \n";
        cout<<"  @     @  \n";
        cout<<"   @   @   \n";
        cout<<"    @ @    \n";
        cout<<"     @     \n";
    }
    
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;print(N);
    return  0;
}