#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <cmath>

using namespace std;

#define NUM_OF_CLASS    4
#define INF     0x7FFFFFFF

static int  k,n;

#define is_better(prev_sum,current_sum,prev_diff,current_diff) \
    ((current_diff)<(prev_diff)||\
        ((current_diff)==(prev_diff)&&(current_sum)<(prev_sum)))

int input(vector<int>* weight)
{
    cin>>k>>n;

    for(int i=0;i<NUM_OF_CLASS;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w;

            cin>>w;
            weight[i].push_back(w);
        }
    }

    return  0;
}

int get_sum_of_weight(int c1,int c2,
        vector<int>& sum,vector<int>* weight)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum.push_back(weight[c1][i]
                            +weight[c2][j]);
        }
    }

    return  0;
}

int get_best_weight(vector<int>* weight)
{
    int         ret,diff;
    vector<int> sum1,sum2;

    get_sum_of_weight(0,1,sum1,weight);
    get_sum_of_weight(2,3,sum2,weight);

    sort(sum2.begin(),sum2.end());
    diff = INF;

    for(int idx1=0;idx1<sum1.size();idx1++)
    {
        int idx2,sum;
        
        idx2 = lower_bound(sum2.begin(),
                sum2.end(),k-sum1[idx1])-sum2.begin();
        
        idx2 -= (idx2==sum2.size())?1:0;
        sum = sum1[idx1]+sum2[idx2];

        if( sum == k )
        {
            return  sum;
        }

        if( is_better(ret,sum,diff,abs(sum-k)) )
        {
            ret = sum;
            diff = abs(ret-k);
        }

        if( idx2 != 0 )
        {
            sum = sum1[idx1]+sum2[idx2-1];

            if( is_better(ret,sum,diff,abs(sum-k)) )
            {
                ret = sum;
                diff = abs(ret-k);
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        vector<int> weight[NUM_OF_CLASS];

        input(weight);
        cout<<get_best_weight(weight)<<'\n';
    }

    return  0;
}