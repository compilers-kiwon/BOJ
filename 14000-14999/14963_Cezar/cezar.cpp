#include    <iostream>

using namespace std;

#define MIN_VALUE   2
#define MAX_VALUE   11

static int  num_of_cards[MAX_VALUE+1] = {0,0,4,4,4,4,4,4,4,4,16,4};

int input(void)
{
    int N,ret;

    cin>>N;
    ret = 21;

    for (int i=1;i<=N;i++) {
        int v;
        cin>>v;

        ret -= v;
        num_of_cards[v]--;
    }

    return  ret;
}

int get_num_of_cards(int min_value,int max_value)
{
    int ret = 0;

    for (int i=min_value;i<=max_value;i++) {
        ret += num_of_cards[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X = input();
    int num_of_cards_gt_X = get_num_of_cards(X+1,MAX_VALUE);
    int num_of_cards_lte_X = get_num_of_cards(MIN_VALUE,X);

    cout<<(num_of_cards_gt_X>=num_of_cards_lte_X?"DOSTA":"VUCI")<<'\n';    
    return  0;
}