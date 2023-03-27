#include    <iostream>
#include    <string>

using namespace std;

int print(const string str,int num)
{
    for(int i=1;i<=num;i++)
    {
        cout<<str<<'\n';
    }
    
    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int W,H;

        cin>>W>>H;
        print(string(W,'X'),H);
    }

    return  0;
}