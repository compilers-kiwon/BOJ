#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_NUM 5000000

static bool is_prime[MAX_NUM+1];
static bool called[MAX_NUM+1];
static priority_queue<int> pq[2];

typedef long long int   int64;

#define TIE -1
#define DW  0
#define GS  1
#define NUM_OF_PLAYERS  2

#define MAX_Q_SIZE  3
#define UNIT_SCORE  1000

#define get_min_num(p) \
    ((pq[(p)].size()<MAX_Q_SIZE)?UNIT_SCORE:-pq[(p)].top())

#define determine_winner(dw_score,gs_score) \
    (((dw_score)==(gs_score))?TIE:((dw_score)>(gs_score))?DW:GS)

int get_prime_numbers(void)
{
    fill(&is_prime[0],&is_prime[MAX_NUM+1],true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2;i<=MAX_NUM;i++)
    {
        if( is_prime[i] == true )
        {
            for(int j=i+i;j<=MAX_NUM;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    return  0;
}

int simulate(void)
{
    int     N;
    int64   score[NUM_OF_PLAYERS] = {0,};

    cin>>N;

    for(int i=0;i<N*NUM_OF_PLAYERS;i++)
    {
        int n,me,other;

        cin>>n;
        
        me = i%NUM_OF_PLAYERS;
        other = (i+1)%NUM_OF_PLAYERS;

        if( is_prime[n] == false )
        {
            score[other] += (int64)get_min_num(other);
            continue;
        }

        if( called[n] == true )
        {
            score[me] -= UNIT_SCORE;
            continue;
        }

        called[n] = true;
        pq[me].push(-n);

        if( pq[me].size() > MAX_Q_SIZE )
        {
            pq[me].pop();
        }
    }
    
    return  determine_winner(score[DW],score[GS]);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int result;

    get_prime_numbers();
    result = simulate();

    cout<<((result==TIE)?"우열을 가릴 수 없음":
                (result==DW)?"소수의 신 갓대웅":"소수 마스터 갓규성")<<'\n';

    return  0;
}