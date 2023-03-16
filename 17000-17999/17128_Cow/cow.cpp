#include    <iostream>
#include    <vector>

using namespace std;

#define WINDOW_SIZE 4

#define get_idx(s,o,size)   (((s)+(o))%(size))

typedef long long int   int64;

typedef struct{
    int64 value;
    vector<int> related;  
} Cow;

static int  N,Q;

int input(vector<Cow>& v,vector<int>& q)
{
    cin>>N>>Q;

    for(int i=0;i<N;i++)
    {
        Cow c;

        cin>>c.value;

        for(int offset=0;offset<WINDOW_SIZE;offset++)
        {
            c.related.push_back(get_idx(i,offset,N));
        }

        v.push_back(c);
    }

    for(int i=0;i<Q;i++)
    {
        int n;

        cin>>n;
        q.push_back(n-1);
    }

    return  0;
}

int64   get_sum(const vector<Cow>& c,vector<int64>& sum)
{
    int64   ret = 0;

    sum.resize(c.size(),1);

    for(int i=0;i<c.size();i++)
    {
        for(int j=0;j<WINDOW_SIZE;j++)
        {
            sum[c[i].related[j]] *= c[i].value;
        }
    }

    for(int i=0;i<sum.size();i++)
    {
        ret += sum[i];
    }

    return  ret;
}

int64 do_query(int idx,vector<Cow>& c,vector<int64>& sum,int64 s)
{
    int64   ret = s;

    for(int i=0;i<WINDOW_SIZE;i++)
    {
        int64   from = sum[c[idx].related[i]];
        int64   to = -sum[c[idx].related[i]];
        
        ret += to-from;
        sum[c[idx].related[i]] = to;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Cow>     C;
    vector<int64>   S;
    vector<int>     Q;
    int64           sum;

    input(C,Q);
    sum = get_sum(C,S);

    for(int i=0;i<Q.size();i++)
    {
        sum = do_query(Q[i],C,S,sum);
        cout<<sum<<'\n';
    }

    return  0;
}