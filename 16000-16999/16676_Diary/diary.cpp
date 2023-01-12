#include    <iostream>

using namespace std;

int main(void)
{
    int N,num_of_packs;

    cin>>N;
    num_of_packs = 1;

    for(int n=10;n<N;n=n*10+10,num_of_packs++);
    cout<<num_of_packs<<'\n';

    return  0;
}