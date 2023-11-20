#include    <iostream>
#include    <cstring>

using namespace std;

const static int MAX_SIZE = 300+1;
const static int MAX_NUM = 10;

static int N,Q,cnt_in_row[MAX_SIZE][MAX_SIZE][MAX_NUM+1];

static inline void count_number(int row,int col,int num) {
    memcpy(&cnt_in_row[row][col][0],
            &cnt_in_row[row][col-1][0],
            sizeof(int)*(MAX_NUM+1));
    cnt_in_row[row][col][num]++;
}

static inline void get_cnt_of_numbers(int bottom,int right,int result[]) {
    for (int row=1;row<=bottom;row++) {
        for (int i=0;i<=MAX_NUM;i++) {
            result[i] += cnt_in_row[row][right][i];
        }
    }
}

void input(void)
{
    cin>>N;

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=N;col++) {
            int A;
            cin>>A;
            count_number(row,col,A);
        }
    }
}

int simulate(int top,int left,int bottom,int right)
{
    int big[MAX_NUM+1] = {0,};
    int upside[MAX_NUM+1] = {0,};
    int leftside[MAX_NUM+1] = {0,};
    int duplicated[MAX_NUM+1] = {0,};
    
    get_cnt_of_numbers(bottom,right,big);
    get_cnt_of_numbers(top-1,right,upside);
    get_cnt_of_numbers(bottom,left-1,leftside);    
    get_cnt_of_numbers(top-1,left-1,duplicated);
    
    int ret = 0;

    for (int i=0;i<=MAX_NUM;i++) {
        int cnt_of_number =
            big[i]-upside[i]-leftside[i]+duplicated[i];
        ret += ((cnt_of_number!=0)?1:0);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cin>>Q;

    for (int i=1;i<=Q;i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<simulate(x1,y1,x2,y2)<<'\n';
    }

    return  0;
}