#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

static int  N,M,S[MAX_SIZE],E[MAX_SIZE];

#define is_exclusive(s1,e1,s2,e2)   ((s1)>=(e2)||(e1)<=(s2))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        cin>>N>>M;
        if(N==0 && M==0) break;

        for(int i=1;i<=N;i++)
        {
            int src,dst,start,duration;

            cin>>src>>dst>>start>>duration;

            S[i] = start;
            E[i] = start+duration;
        }

        for(int i=1;i<=M;i++)
        {
            int s,e,d,cnt;

            cin>>s>>d;

            e = s+d;
            cnt = 0;

            for(int j=1;j<=N;j++)
            {
                if(!is_exclusive(s,e,S[j],E[j])) cnt++;
            }

            cout<<cnt<<'\n';
        }
    }

    return  0;
}