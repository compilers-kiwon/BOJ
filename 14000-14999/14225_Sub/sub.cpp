#include    <iostream>

using namespace std;

const static int MAX_SIZE = 20;
const static int MAX_SUM = 2000000+1;

static int N,S[MAX_SIZE];
static bool sum_table[MAX_SUM];

static inline int get_sum(int used) {
    int ret = 0;
    for (int j=0;j<N;j++) {
        if ((used&(1<<j)) != 0) ret+=S[j];
    }
    return  ret;
}

void input(void)
{
    cin>>N;

    for (int i=0;i<N;i++) {
        cin>>S[i];
    }
}

void simulate(void)
{
    for (int i=1;i<(1<<N);i++) {
        sum_table[get_sum(i)] = true;
    }
}

int find_min_number(void)
{
    int ret;

    for (ret=1;;ret++) {
        if (!sum_table[ret]) break;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    cout<<find_min_number()<<'\n';

    return  0;
}