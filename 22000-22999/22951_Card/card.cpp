#include    <iostream>

using namespace std;

#define MAX_NUM_OF_CARDS    (100*10+1)

typedef struct{int num,player,prev,next;}   Card;

static Card c[MAX_NUM_OF_CARDS];

int input(void)
{
    int N,K,pos;

    cin>>N>>K;
    pos = 1;

    for(int p=1;p<=N;p++)
    {
        for(int i=1;i<=K;i++,pos++)
        {
            int n;

            cin>>n;
            c[pos] = {n,p,pos-1,pos+1};
        }
    }

    c[1].prev = N*K;
    c[N*K].next = 1;

    return  N*K;
}

int simulate(int num_of_cards)
{
    int pos = 1;

    for(int i=1;i<num_of_cards;i++)
    {
        int prev_card = c[pos].prev;
        int next_card = c[pos].next;
        
        c[prev_card].next = next_card;
        c[next_card].prev = prev_card;

        for(int current_num=c[pos].num;current_num!=0;current_num--)
        {
            pos = c[pos].next;
        }
    }

    return  pos;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_cards,last_card;
    
    num_of_cards = input();
    last_card = simulate(num_of_cards);
    
    cout<<c[last_card].player<<' '<<c[last_card].num<<'\n';

    return  0;
}