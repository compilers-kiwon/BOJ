#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_WEIGHT  5

static int  package[MAX_WEIGHT+1];

#define merge(prev,current)     ((prev)+=(current))
#define pack(buckets,current)   ((buckets).push_back((current)))

int input(void)
{
    for(int w=1;w<=MAX_WEIGHT;w++)
    {
        cin>>package[w];
    }

    return  0;
}

int simualte(void)
{
    vector<int> bucket;

    for(int w=MAX_WEIGHT;w>=1;w--)
    {
        for(int i=1;i<=package[w];i++)
        {
            bool    packed = false;

            for(int j=0;j<bucket.size()&&packed!=true;j++)
            {
                if( bucket[j]+w <= MAX_WEIGHT )
                {
                    merge(bucket[j],w);
                    packed = true;
                }
            }

            if( packed == false )
            {
                pack(bucket,w);
            }
        }
    }

    return  bucket.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simualte()<<'\n';

    return  0;
}