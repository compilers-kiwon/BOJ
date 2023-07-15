#include    <iostream>

using namespace std;

#define MAX_NUM_OF_TOPPINGS (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,m,cnt;
    bool    dislike[MAX_NUM_OF_TOPPINGS] = {false,};

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;
        dislike[a] = true;
    }
    
    cin>>m;
    cnt = 0;

    for(int i=1;i<=m;i++)
    {
        int k,ordered;

        cin>>k;
        ordered = 1;

        for(int j=1;j<=k;j++)
        {
            int b;

            cin>>b;

            if( dislike[b] == true )
            {
                ordered = 0;
            }
        }

        cnt += ordered;
    }

    cout<<cnt<<'\n';
    return  0;
}