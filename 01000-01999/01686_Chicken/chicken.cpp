#include    <iostream>
#include    <queue>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE    1000

typedef pair<double,double> Pos;    // first:x,second:y

int         num_of_holes,visited[MAX_SIZE+2];
double      v,m;
Pos         c[MAX_SIZE+2];
vector<int> connected[MAX_SIZE+2];

#define get_distance(x1,y1,x2,y2)   (sqrt(((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2))))

void    input(void)
{
    double  tmp_x,tmp_y;

    scanf("%lf %lf %lf %lf %lf %lf",&v,&m,&c[0].first,&c[0].second,&tmp_x,&tmp_y);

    for(double x,y;scanf("%lf %lf",&x,&y)==2;)
    {
        num_of_holes++;
        c[num_of_holes] = make_pair(x,y);
    }

    c[++num_of_holes] = make_pair(tmp_x,tmp_y);
    v *= 60.0;
}

void    get_connected(void)
{
    for(int i=0;i<num_of_holes;i++)
    {
        for(int j=i+1;j<=num_of_holes;j++)
        {
            double& x1 = c[i].first;
            double& y1 = c[i].second;

            double& x2 = c[j].first;
            double& y2 = c[j].second;

            double  d = get_distance(x1,y1,x2,y2);
            
            if( d/v >= m )
            {
                continue;
            }
            
            connected[i].push_back(j);
            connected[j].push_back(i);
        }
    }
}

int     run(void)
{
    int         ret;
    queue<int>  hole_q;

    visited[0] = 1;
    hole_q.push(0);

    for(ret=-1;!hole_q.empty();hole_q.pop())
    {
        int current_hole = hole_q.front();
        
        if( current_hole == num_of_holes )
        {
            ret = visited[current_hole]-2;
            break;
        }

        vector<int>&    adj = connected[current_hole];

        for(int i=0;i<adj.size();i++)
        {
            if( visited[adj[i]] == 0 )
            {
                visited[adj[i]] = visited[current_hole]+1;
                hole_q.push(adj[i]);
            }
        }
    }

    return  ret;
}

int     main(void)
{
    input();
    get_connected();

    int num_of_visited_holes = run();

    if( num_of_visited_holes == -1 )
    {
        puts("No.");
    }
    else
    {
        printf("Yes, visiting %d other holes.\n",num_of_visited_holes);
    }

    return  0;
}