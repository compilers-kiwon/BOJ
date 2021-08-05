#include    <iostream>

using namespace std;

#define MAX_SIZE    (4000+1)

#define OFF         0
#define ON          1
#define MAX_STATE   2

#define CHANGE_STATE(s) (((s)+1)%2)

int N,M,s[MAX_SIZE];

void    chage_state(int from,int to)
{
    for(int i=from;i<=to;i++)
    {
        s[i] = CHANGE_STATE(s[i]);
    }
}

void    print(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<s[i]<<' ';
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>s[i];
    }

    for(int m=1;m<=M;m++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        int&    i = b;
        int&    x = c;
        int&    l = b;
        int&    r = c;

        switch(a)
        {
            case    1:
                s[i] = x;
                break;
            case    2:
                chage_state(l,r);
                break;
            case    3:
                fill(&s[l],&s[r+1],OFF);
                break;
            case    4:
                fill(&s[l],&s[r+1],ON);
                break;
            default:
                // do nothing
                break;
        }
    }

    print();

    return  0;
}