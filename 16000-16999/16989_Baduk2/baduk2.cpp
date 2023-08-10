#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>
#include    <map>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4

#define EMPTY   0
#define ME      1
#define ENEMY   2

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    //first:row,second:col

static int  N,M,grid[MAX_SIZE][MAX_SIZE];
static bool visited[MAX_SIZE][MAX_SIZE];

static map<Pos,int> locked_by_one;
static map<pair<Pos,Pos>,int> locked_by_two;

#define add_max_value_to_sum(sum,pq) \
    {if(!(pq).empty()){(sum)+=(pq).top();(pq).pop();}}

int input(void)
{
    cin>>N>>M;

    for (int row=1;row<=N;row++) {
        for(int col=1;col<=M;col++) {
            cin>>grid[row][col];
        }
    }

    return  0;
}

int find_group(int row,int col,int& cnt,set<Pos>& adj_empty)
{
    visited[row][col] = true;
    cnt++;

    for (int d=0;d<MAX_DIR;d++) {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if (!IN_RANGE(1,adj_row,N)
                || !IN_RANGE(1,adj_col,M)) {
            continue;
        }

        if (grid[adj_row][adj_col] == EMPTY) {
            adj_empty.insert({adj_row,adj_col});
        }

        if (grid[adj_row][adj_col]!=ENEMY 
                || visited[adj_row][adj_col]!=false) {
            continue;
        }

        find_group(adj_row,adj_col,cnt,adj_empty);
    }

    return  0;
}

int get_current_state(void)
{
    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            if (grid[row][col]==ENEMY 
                    && visited[row][col]==false) {
                int         cnt = 0;
                set<Pos>    adj_empty;
                
                set<Pos>::iterator  front;
                set<Pos>::reverse_iterator  back;

                find_group(row,col,cnt,adj_empty);

                switch (adj_empty.size()) {
                    case    1:
                        locked_by_one[*(adj_empty.begin())] += cnt;
                        break;
                    case    2:
                        front = adj_empty.begin();
                        back = adj_empty.rbegin();
                        locked_by_two[{*front,*back}] += cnt;
                        break;
                    default:
                        /* do nothing */
                        break;                        
                }
            }
        }
    }

    return  0;
}

int lock_two_groups(void)
{
    int ret = 0;
    priority_queue<int> pq;
    map<Pos,int>::iterator it;

    for(it=locked_by_one.begin();it!=locked_by_one.end();it++) {
        pq.push(it->second);
    }

    add_max_value_to_sum(ret,pq);
    add_max_value_to_sum(ret,pq);

    return  ret;
}

int get_max_num_of_enemy_to_be_defeated(void)
{
    int ret = 0;
    map<pair<Pos,Pos>,int>::iterator   it;

    for (it=locked_by_two.begin();it!=locked_by_two.end();it++) {
        int cur_num_of_defeated_enemy = it->second;
        Pos p1 = it->first.first;
        Pos p2 = it->first.second;

        cur_num_of_defeated_enemy += locked_by_one[p1]+locked_by_one[p2];
        ret = max(ret,cur_num_of_defeated_enemy);
    }

    return  max(ret,lock_two_groups());
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_current_state();
    cout<<get_max_num_of_enemy_to_be_defeated()<<'\n';

    return  0;
}