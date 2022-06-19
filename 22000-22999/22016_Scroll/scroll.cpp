#include    <iostream>

using namespace std;

#define MAX_LEN (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,K,i;
    char    T[MAX_LEN+1],table[0x100];

    table['J'] = 'j';
    table['O'] = 'o';
    table['I'] = 'i';

    table['j'] = 'J';
    table['o'] = 'O';
    table['i'] = 'I';

    cin>>N>>K>>&T[1];

    for(i=1;i<K;i++)
    {
        cout<<T[i];
    }

    for(;i<=N;i++)
    {
        cout<<table[T[i]];
    }

    cout<<'\n';

    return  0;
}