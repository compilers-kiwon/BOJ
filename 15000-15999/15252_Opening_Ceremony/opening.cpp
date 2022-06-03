#include    <iostream>

using namespace std;

#define MAX_NUM_OF_COUNTRIES    (1000+1)

int input(int country[],int count[])
{
    int c,n;

    cin>>c>>n;
    fill(&count[1],&count[c+1],0);

    for(int i=1;i<=c;i++)
    {
        cin>>country[i];
    }

    for(int i=1;i<=n;i++)
    {
        int b;

        cin>>b;
        count[b]++;
    }

    return  c;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;

    cin>>K;

    for(int k=1;k<=K;k++)
    {
        int c,max_diff;
        int m[MAX_NUM_OF_COUNTRIES];
        int n[MAX_NUM_OF_COUNTRIES];

        c = input(m,n);
        max_diff = 0;
        
        for(int i=1;i<=c;i++)
        {
            max_diff = max(max_diff,m[i]-n[i]);
        }

        cout<<"Data Set "<<k<<":\n"<<max_diff<<'\n'<<'\n';
    }

    return  0;
}