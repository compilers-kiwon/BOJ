#include    <iostream>

using namespace std;

#define MAX_NUM_OF_SHUFFLES (1000+1)
#define MAX_NUM_OF_CARDS    (100*2+1)

static int  cards[MAX_NUM_OF_SHUFFLES][MAX_NUM_OF_CARDS];

int init_cards(int num_of_cards)
{
    for (int i=1;i<=num_of_cards*2;i++) cards[0][i]=i;
    return  0;
}

int shuffle_k(int to,int num_of_cards,int k)
{
    int from = to-1;
    int pos = 1;

    for (int i=k+1;i<=num_of_cards*2;i++,pos++) {
        cards[to][pos] = cards[from][i];
    }

    for (int i=1;i<=k;i++,pos++) {
        cards[to][pos] = cards[from][i];
    }

    return  0;
}

int shuffle_0(int to,int num_of_cards)
{
    int from = to-1;
    int pos = 1;

    for (int i=1;i<=num_of_cards;i++) {
        cards[to][pos++] = cards[from][i];
        cards[to][pos++] = cards[from][num_of_cards+i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m;

    cin>>n>>m;
    init_cards(n);

    for (int i=1;i<=m;i++) {
        int k;

        cin>>k;
        (k==0)?shuffle_0(i,n):shuffle_k(i,n,k);
    }

    for (int i=1;i<=n*2;i++) cout<<cards[m][i]<<'\n';
    return  0;
}