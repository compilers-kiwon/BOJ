#include    <iostream>
#include    <vector>

using namespace std;

typedef pair<int,int>   Pos;

const static int MAX_SIZE = 500+1;
const static int MAX_DIR = 4;
const static int SAFE = 1;
const static int UNSAFE = 0;

const static char SHEEP = 'S';
const static char WOLF = 'W';
const static char FENCE = 'D';
const static char EMPTY = '.';

const static struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

static int R,C;
static char grid[MAX_SIZE][MAX_SIZE+1];

static inline bool in_range(int MIN,int n,int MAX) {
    return  (MIN<=n && n<=MAX);
}

static inline void install_fence(const vector<Pos>& p) {
    for (int i=0;i<p.size();i++) {
        grid[p[i].first][p[i].second] = FENCE;
    }
}

void input(vector<Pos>& w)
{
    cin>>R>>C;

    for (int row=1;row<=R;row++) {
        cin>>&grid[row][1];
        for (int col=1;col<=C;col++) {
            if (grid[row][col] == WOLF) {
                w.push_back({row,col});
            }
        }
    }
}

bool get_fence_pos(const Pos& w,vector<Pos>& f)
{
    for (int d=0;d<MAX_DIR;d++) {
        int adj_row = w.first+adj[d].d_row;
        int adj_col = w.second+adj[d].d_col;

        if (!in_range(1,adj_row,R)
                || !in_range(1,adj_col,C)) {
            continue;
        }

        switch (grid[adj_row][adj_col]) {
            case SHEEP:return false;
            case EMPTY:f.push_back({adj_row,adj_col});break;
            default:/*do nothing*/;break;
        }
    }

    return  true;
}

int simulate(const vector<Pos>& w)
{
    for (int i=0;i<w.size();i++) {
        vector<Pos> fence_pos;
        if(!get_fence_pos(w[i],fence_pos)) return UNSAFE;
        install_fence(fence_pos);
    }

    return  SAFE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> wolves;

    input(wolves);
    
    if (simulate(wolves) == SAFE) {
        cout<<"1\n";
        for (int row=1;row<=R;row++) {
            cout<<&grid[row][1]<<'\n';
        }
    } else {
        cout<<"0\n";
    }

    return  0;
}