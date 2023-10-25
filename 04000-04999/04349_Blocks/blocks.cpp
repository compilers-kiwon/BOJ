#include    <iostream>

using namespace std;

const static int INF = 0x7FFFFFFF;

int simulate(int num_of_blocks)
{
    int ret = INF;

    for (int a=1;a<=num_of_blocks;a++) {
        for (int b=1;a*b<=num_of_blocks;b++) {
            int c = num_of_blocks/(a*b);
            if (a*b*c == num_of_blocks) {
                ret = min(ret,2*(a*b+b*c+c*a));
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int C;

    cin>>C;

    for (int i=1;i<=C;i++) {
        int N;

        cin>>N;
        cout<<simulate(N)<<'\n';
    }

    return  0;
}