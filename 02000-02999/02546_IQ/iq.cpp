#include    <iostream>
#include    <queue>

using namespace std;

typedef long long int   int64;

#define is_increased_without(size,n,sum) \
        (((size)*((sum)-(n)))>((sum)*((size)-1)))

#define is_increased_with(size,n,sum) \
        ((((sum)+(n))*(size))>((sum)*((size)+1)))

static int64    N,M,IQ_sum_of_c,IQ_sum_of_economics;

int get_IQ(priority_queue<int64>* ptr,int size,int64& sum)
{
    for(int i=1;i<=size;i++)
    {
        int64   n;

        cin>>n;
        sum += n;

        if(ptr!=NULL) (*ptr).push(-n);
    }

    return  0;
}

int input(priority_queue<int64>& c_IQ)
{
    cin>>N>>M;
    IQ_sum_of_c = IQ_sum_of_economics = 0;

    get_IQ(&c_IQ,N,IQ_sum_of_c);
    get_IQ(NULL,M,IQ_sum_of_economics);

    return  0;
}

int simulate(priority_queue<int64>& c_IQ)
{
    int ret = 0;

    for(;!c_IQ.empty();c_IQ.pop())
    {
        int64   current_IQ = -c_IQ.top();

        if( !is_increased_without(N,current_IQ,IQ_sum_of_c) )
        {
            break;
        }

        if( is_increased_with(M,current_IQ,IQ_sum_of_economics) )
        {
            ret++;
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
        priority_queue<int64>   c_IQ;

        input(c_IQ);
        cout<<simulate(c_IQ)<<'\n';
    }

    return  0;
}