#include    <iostream>

using namespace std;

#define NUM_OF_TRIANGLES    6

int     max_sum,edge[NUM_OF_TRIANGLES+1];
int     length[NUM_OF_TRIANGLES+1][3];
bool    used[NUM_OF_TRIANGLES+1];

char    input(void)
{
    char    ret;

    for(int i=1;i<=NUM_OF_TRIANGLES;i++)
    {
        cin>>length[i][0]>>length[i][1]>>length[i][2];
    }

    cin>>ret;
    max_sum = 0;

    fill(&edge[1],&edge[NUM_OF_TRIANGLES+1],0);
    fill(&used[1],&used[NUM_OF_TRIANGLES+1],false);

    return  ret;
}

void    simulate(int idx,int current_sum)
{
    if( idx > NUM_OF_TRIANGLES )
    {
        max_sum = max(max_sum,current_sum);
        return;
    }

    for(int t=1;t<=NUM_OF_TRIANGLES;t++)
    {
        if( used[t] == true )
        {
            continue;
        }

        used[t] = true;

        for(int i=0;i<3;i++)
        {
            if( idx == 1 )
            {
                edge[1] = length[t][(i+1)%3];
                edge[6] = length[t][(i+2)%3];

                simulate(idx+1,current_sum+length[t][i]);
            }
            else
            {
                if( idx == NUM_OF_TRIANGLES )
                {
                    if( edge[idx-1]==length[t][(i+2)%3]
                        && edge[NUM_OF_TRIANGLES]==length[t][(i+1)%3] )
                    {
                        simulate(idx+1,current_sum+length[t][i]);
                    }
                }
                else
                {
                    if( edge[idx-1] == length[t][(i+2)%3] )
                    {
                        edge[idx] = length[t][(i+1)%3];
                        simulate(idx+1,current_sum+length[t][i]);
                    }
                }
            }
        }

        used[t] = false;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        char    c = input();

        simulate(1,0);
        
        if( max_sum == 0 )
        {
            cout<<"none\n";
        }
        else
        {
            cout<<max_sum<<'\n';
        }

        if( c == '$' )
        {
            break;
        }
    }

    return  0;
}