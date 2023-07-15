#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4
#define COMFORTABLE 3

static bool occupied[1+MAX_SIZE+1][1+MAX_SIZE+1];
static int  num_of_occupied_adj[1+MAX_SIZE+1][1+MAX_SIZE+1];

const struct{int dx,dy;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}}; 

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt;

    cin>>N;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        int x,y;

        cin>>x>>y;
        x++;y++;

        occupied[x][y] = true;
        cnt += (num_of_occupied_adj[x][y]==COMFORTABLE)?1:0;
        
        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_x = x+adj[d].dx;
            int adj_y = y+adj[d].dy;

            num_of_occupied_adj[adj_x][adj_y]++;
            
            if( occupied[adj_x][adj_y] == true )
            {
                cnt += (num_of_occupied_adj[adj_x][adj_y]==COMFORTABLE)?1:
                    (num_of_occupied_adj[adj_x][adj_y]==COMFORTABLE+1)?-1:0;
            }
        }

        cout<<cnt<<'\n';
    }

    return  0;
}