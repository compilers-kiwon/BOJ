#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

void    get_score(int* arr,int size)
{
    for(int i=1;i<=size;i++)
    {
        cin>>arr[i];
    }
}

int     get_points_for_win(int* score1,int* score2,int size)
{
    int ret = 0;

    for(int i=1;i<=size;i++)
    {
        int&    s1 = score1[i];
        int&    s2 = score2[i];

        ret += ((s1>s2)?3:(s1==s2)?1:0);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],B[MAX_SIZE];

    cin>>N;
    get_score(A,N);
    get_score(B,N);

    cout<<get_points_for_win(A,B,N)<<'\n';

    return  0;
}