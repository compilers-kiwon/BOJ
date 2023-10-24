#include    <iostream>
#include    <vector>

using namespace std;

typedef pair<int,int>   Pos;

const static int EMPTY = 0;
const static int MIN_NUM = 1;
const static int MAX_NUM = 20000;

const static int NUM_OF_CONNECTIONS = 8;
const static int SQUARE_SIZE = 3;

const static int MID_ROW = 2;
const static int MID_COL = 2;

const static Pos connected[NUM_OF_CONNECTIONS][SQUARE_SIZE] = {
    {{1,1},{1,2},{1,3}},    // 0
    {{2,1},{2,2},{2,3}},    // 1
    {{3,1},{3,2},{3,3}},    // 2
    {{1,1},{2,1},{3,1}},    // 3
    {{1,2},{2,2},{3,2}},    // 4
    {{1,3},{2,3},{3,3}},    // 5
    {{1,1},{2,2},{3,3}},    // 6
    {{1,3},{2,2},{3,1}}     // 7
};

const static vector<int> included[SQUARE_SIZE+1][SQUARE_SIZE+1] = {
    {{},{},{},{}},
    {{},{0,3,6},{0,4},{0,5,7}},
    {{},{1,3},{1,4,6,7},{1,5}},
    {{},{2,3,7},{2,4},{2,5,6}}
};

static int  square[SQUARE_SIZE+1][SQUARE_SIZE+1];

static inline bool in_range(int MIN,int n,int MAX) {
    return  ((MIN<=n) && (n<=MAX));
}

int get_adj(int idx)
{
    int ret = 0;

    for (int i=0;i<SQUARE_SIZE;i++) {
        ret += square[connected[idx][i].first][connected[idx][i].second];
    }

    return  ret;
}

int get_sum(void)
{
    int ret = 0;

    for (int i=0;i<NUM_OF_CONNECTIONS;i++) {
        bool    is_empty = false;
        for (int j=0;j<SQUARE_SIZE;j++) {
            int n = square[connected[i][j].first][connected[i][j].second];
            
            if (n == EMPTY) {
                is_empty = true;
                break;
            }
            
            ret += n;
        }

        if (!is_empty) break;
        ret = 0;
    }

    return  ret;
}

int get_attr(int idx,int& sum)
{
    int num_of_empty;

    sum = num_of_empty = 0;

    for (int i=0;i<SQUARE_SIZE;i++) {
        int n = square[connected[idx][i].first][connected[idx][i].second];
        if (n == EMPTY) num_of_empty++;
        sum += n;
    }

    return  num_of_empty;
}


int get_num_of_empty(void)
{
    int ret = 0;

    for (int row=1;row<=SQUARE_SIZE;row++) {
        for (int col=1;col<=SQUARE_SIZE;col++) {
            ret += (square[row][col]==EMPTY?1:0);
        }
    }

    return  ret;
}

int simulate(void)
{
    int sum = get_sum();

    if (sum != 0) {
        for(;get_num_of_empty()!=0;) {
            for (int row=1;row<=SQUARE_SIZE;row++) {
                for (int col=1;col<=SQUARE_SIZE;col++) {
                    if (square[row][col] != EMPTY) continue;
                    const vector<int>& adj = included[row][col];

                    for (int i=0;i<adj.size();i++) {
                        int cur,num_of_empty;
                       
                        num_of_empty = get_attr(adj[i],cur);

                        if (num_of_empty == 1) {
                            square[row][col] = sum-cur;
                            break;
                        }
                    }
                }
            }
        }

        return  0;
    }

    for (int n=MIN_NUM;n<=MAX_NUM;n++) {
        square[MID_ROW][MID_COL] = n;
        sum = get_adj(1);

        if (square[1][1] == 0) {
            int n1,n2,s1,s2;

            s1 = get_adj(0);
            s2 = get_adj(3);

            if (!in_range(MIN_NUM,sum-s1,MAX_NUM) || (sum-s1!=sum-s2)) {
                continue;
            }

            n1 = sum-s1;

            s1 = get_adj(2);
            s2 = get_adj(5);

            if (!in_range(MIN_NUM,sum-s1,MAX_NUM) || (sum-s1!=sum-s2)) {
                continue;
            }

            n2 = sum-s1;
            
            if (n1+square[MID_ROW][MID_COL]+n2 != sum) {
                continue;
            }

            square[1][1] = n1;
            square[3][3] = n2;
            break;
        } else {
            int n1,n2,s1,s2;

            s1 = get_adj(0);
            s2 = get_adj(5);

            if (!in_range(MIN_NUM,sum-s1,MAX_NUM) || (sum-s1!=sum-s2)) {
                continue;
            }

            n1 = sum-s1;

            s1 = get_adj(2);
            s2 = get_adj(3);

            if (!in_range(MIN_NUM,sum-s1,MAX_NUM) || (sum-s1!=sum-s2)) {
                continue;
            }

            n2 = sum-s1;
            
            if (n1+square[MID_ROW][MID_COL]+n2 != sum) {
                continue;
            }

            square[1][3] = n1;
            square[3][1] = n2;
            break;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int row=1;row<=SQUARE_SIZE;row++) {
        for (int col=1;col<=SQUARE_SIZE;col++) {
            cin>>square[row][col];
        }
    }

    simulate();

    for (int row=1;row<=SQUARE_SIZE;row++) {
        for (int col=1;col<=SQUARE_SIZE;col++) {
            cout<<square[row][col]<<(col==SQUARE_SIZE?'\n':' ');
        }
    }

    return  0;
}