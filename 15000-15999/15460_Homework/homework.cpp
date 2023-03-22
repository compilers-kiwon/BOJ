#include    <iostream>
#include    <vector>
#include    <map>

using namespace std;

#define MAX_SIZE    (100000+1)

static int  N,score[MAX_SIZE],sum[MAX_SIZE];
static map<int,int> score_table;

#define get_total_score()           (sum[N])
#define min_score(t)                ((t).begin()->first)
#define get_average(a,b)            ((double)(a)/(double)(b))

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>score[i];
        sum[i] = sum[i-1]+score[i];
        score_table[score[i]]++;
    }

    return  0;
}

int simulate(vector<int>& result)
{
    double  max_avg = 0.0;

    for(int K=1;K<=N-2;K++)
    {
        int remaining_score = get_total_score()-sum[K];

        if( --score_table[score[K]] == 0 )
        {
            score_table.erase(score[K]);
        }

        int     available_score = 
                    remaining_score-min_score(score_table);
        double  current_avg = get_average(available_score,(N-K-1));
        
        if( current_avg >= max_avg )
        {
            if( current_avg > max_avg )
            {
                result.clear(); 
                max_avg = current_avg;
            }
            
            result.push_back(K);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> K;

    input();
    simulate(K);

    for(int i=0;i<K.size();i++)
    {
        cout<<K[i]<<'\n';
    }

    return  0;
}