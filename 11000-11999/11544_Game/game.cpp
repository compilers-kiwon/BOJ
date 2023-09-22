#include    <iostream>

using namespace std;

#define NUM_OF_CARDS        5
#define MAX_NUM_OF_PLAYERS  20
#define DEADALUS_IDX        0

const static int cards[NUM_OF_CARDS] = {1,10,100,1000,10000};

int get_info_of_this_round(int& budget,int p[],
                                int num_of_players)
{
    int ret = 0;

    cin>>budget;
    
    for (int i=0;i<num_of_players;i++) {
        cin>>p[i];
        ret += p[i];
    }

    return  ret;
}

int get_max_points(int sum,int budget,int p[])
{
    int ret = 0;

    for (int i=0;i<NUM_OF_CARDS;i++) {
        if (sum-p[DEADALUS_IDX]+cards[i] <= budget) {
            ret = cards[i];
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,total_extra_points;;

    cin>>N>>M;
    total_extra_points = 0;

    for (int round=0;round<M;round++) {
        int budget,players[MAX_NUM_OF_PLAYERS];
        int sum,max_points,cur_points;

        sum = get_info_of_this_round(budget,players,N);
        cur_points = (sum<=budget)?players[DEADALUS_IDX]:0;
        
        max_points = get_max_points(sum,budget,players);
        total_extra_points += max(0,max_points-cur_points);
    }

    cout<<total_extra_points<<'\n';
    return  0;
}