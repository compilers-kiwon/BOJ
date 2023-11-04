#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int H,I,A,R,C;

    cin>>H>>I>>A>>R>>C;
    cout<<H*I-A*R*C<<'\n';

    return  0;
}