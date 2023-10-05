#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define LOST        (-1)

static int  N,M,Q,A[MAX_SIZE][MAX_SIZE],B[MAX_SIZE];

bool    compare(int row)
{
    for (int col=1;col<=M;col++) {
        if (B[col]!=LOST && B[col]!=A[row][col]) {
            return  false;
        }
    }

    return  true;
}

int     check_query(void)
{
    int ret = 0;

    for (int row=1;row<=N;row++) {
        compare(row)?ret++:ret;
    }

    return  ret;
}

int read_query(void)
{
    for (int i=1;i<=M;i++) {
        cin>>B[i];
    }

    return  0;
}

int read_database(void)
{
    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            cin>>A[row][col];
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    read_database();

    cin>>Q;

    for (int i=1;i<=Q;i++) {
        read_query();
        cout<<check_query()<<'\n';
    }

    return  0;
}