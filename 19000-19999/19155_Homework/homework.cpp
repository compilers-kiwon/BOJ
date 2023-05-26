#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        int num;

        cin>>num;
        cout<<(N-num)+1<<(i==N?'\n':' ');
    }

    return  0;
}