#include    <iostream>

using namespace std;

#define MAX_SIZE    (20+1)

static int  A[MAX_SIZE][MAX_SIZE],
            B[MAX_SIZE][MAX_SIZE],
            C[MAX_SIZE][MAX_SIZE];
static int  M,N,P,Q;

int read_matrix(int row_size,int col_size,int m[][MAX_SIZE])
{
    for (int row=1;row<=row_size;row++)
        for (int col=1;col<=col_size;col++)
            cin>>m[row][col];

    return  0;
}

int multiply_matrix(void)
{
    for (int row=1;row<=M;row++) {
        for (int col=1;col<=Q;col++) {
            C[row][col] = 0;
            for (int offset=1;offset<=N;offset++) {
                C[row][col] += A[row][offset]*B[offset][col];
            }
        }
    }

    return  0;
}

int print_matrix(int row_size,int col_size,int m[][MAX_SIZE])
{
    for (int row=1;row<=row_size;row++) {
        cout<<"| ";
        for (int col=1;col<=col_size;col++) cout<<m[row][col]<<' ';
        cout<<"|\n";
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i=1;;i++) {
        cin>>M>>N>>P>>Q;
        if (M+N+P+Q == 0) break;

        cout<<"Case #"<<i<<":\n";
        read_matrix(M,N,A);read_matrix(P,Q,B);

        if (N != P) {
            cout<<"undefined\n";
            continue;
        }

        multiply_matrix();
        print_matrix(M,Q,C);
    }

    return  0;
}