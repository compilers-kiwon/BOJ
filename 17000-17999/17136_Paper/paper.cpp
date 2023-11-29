#include    <iostream>

using namespace std;

const static int MAX_SIZE = 10;
const static int NUM_OF_PAPERS = 5;

static int grid[MAX_SIZE+1][MAX_SIZE+1];
static int cnt_of_papers[NUM_OF_PAPERS+1];
static int num_of_ones;

void input(void)
{
    for (int row=1;row<=MAX_SIZE;row++) {
        for (int col=1;col<=MAX_SIZE;col++) {
            cin>>grid[row][col];
            num_of_ones += ((grid[row][col]==1)?1:0);
        }
    }

    for (int i=1;i<=NUM_OF_PAPERS;i++) {
        cnt_of_papers[i] = NUM_OF_PAPERS;
    }
}

bool find_zero(int r,int c,int s)
{
    for (int row=r;row<r+s;row++) {
        for (int col=c;col<c+s;col++) {
            if (grid[row][col] == 0) return true;
        }
    }

    return false;
}

void fill_grid(int r,int c,int s,int n)
{
    for (int row=r;row<r+s;row++) {
        for (int col=c;col<c+s;col++) {
            grid[row][col] = n;
        }
    }
}

static inline void attach_paper(int row,int col,int size) {
    fill_grid(row,col,size,0);
    cnt_of_papers[size]--;
}

static inline void restore_paper(int row,int col,int size) {
    fill_grid(row,col,size,1);
    cnt_of_papers[size]++;
}

void simulate(int row,int col,int cnt,
                int& min_num_of_papers)
{
    if (col > MAX_SIZE) {
        row++;
        col = 1;
    }

    if (row > MAX_SIZE) {
        min_num_of_papers =
            min(cnt,min_num_of_papers);
        return;
    }

    if (grid[row][col] == 0) {
        simulate(row,col+1,cnt,min_num_of_papers);
        return;
    }

    int possible_size =
        min(MAX_SIZE-max(row,col)+1,NUM_OF_PAPERS);

    for (int p=1;p<=possible_size;p++) {
        if (cnt_of_papers[p]==0
                || find_zero(row,col,p)) continue;
        attach_paper(row,col,p);
        simulate(row,col+1,cnt+1,min_num_of_papers);
        restore_paper(row,col,p);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_used_papers = 0x7FFFFFFF;

    input();
    simulate(1,1,0,num_of_used_papers);

    if (num_of_used_papers == 0x7FFFFFFF) {
        cout<<"-1\n";
    } else {
        cout<<num_of_used_papers<<'\n';
    }
    
    return  0;
}