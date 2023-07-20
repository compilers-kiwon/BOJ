#include    <iostream>

using namespace std;

int simulate(int n1,int n2)
{
    int A = max(n1,n2);
    int B = min(n1,n2);
    int ret = 0;

    for(;B!=0&&A!=B;ret++)
    {
        int max_num = max(A,B);
        int min_num = min(A,B);

        A = max_num-min_num;
        B = min_num;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B;

    cin>>A>>B;
    cout<<simulate(A,B)<<'\n';

    return  0;
}