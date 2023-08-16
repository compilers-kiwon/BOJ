#include    <iostream>
#include    <cstring>

using namespace std;

#define MAX_SIZE            (1000)
#define MAX_STAMP_SIZE      (500)
#define MAX_NUM_OF_STAMPS   (500+1)
#define MAX_NUM_OF_DRAWS    (10000+1)

#define NONE    -1
#define EMPTY   '.'

typedef struct{
    int     h,w;
    char    p[MAX_STAMP_SIZE][MAX_STAMP_SIZE+1];
} Stamp;

typedef struct{int T,Y,X;}  Draw;

static int      N,M,K,Q,end_pos[MAX_SIZE][MAX_SIZE];
static char     grid[MAX_SIZE][MAX_SIZE];
static Stamp    s[MAX_NUM_OF_STAMPS];
static Draw     d[MAX_NUM_OF_DRAWS];

int read_stamps(void)
{
    for (int i=1;i<=K;i++) {
        Stamp&  cur = s[i];
        cin>>cur.h>>cur.w;

        for (int row=0;row<cur.h;row++) {
            cin>>&cur.p[row][0];
        }
    }

    return  0;
}

int stamp(int idx,int y,int x)
{
    Stamp&  cur = s[idx];

    for (int row=0;row<cur.h&&y+row<N;row++) {
        for (int col=0;col<cur.w&&x+col<M;) {
            int r = y+row;
            int c = x+col;

            if (end_pos[r][c] == NONE) {
                end_pos[r][c] = x+cur.w;
                grid[r][c] = cur.p[row][col];
                col++;
            } else {
                col += end_pos[r][c]-(x+col);
            }
        }
    }

    return  0;
}

int init(void)
{
    cin>>N>>M>>K;
    memset(grid,EMPTY,sizeof(grid));
    memset(end_pos,NONE,sizeof(end_pos));

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    read_stamps();

    cin>>Q;

    for (int i=1;i<=Q;i++) {
        cin>>d[i].T>>d[i].Y>>d[i].X;
    }

    for (int i=Q;i>=1;i--) {
        stamp(d[i].T,d[i].Y,d[i].X);
    }

    for (int row=0;row<N;row++) {
        for (int col=0;col<M;col++) {
            cout<<grid[row][col];
        }
        cout<<'\n';
    }

    return  0;
}
