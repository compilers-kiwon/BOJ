#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (1000+1)

int     dp[MAX_SIZE][MAX_SIZE];
string  A,B;    // A:row,B:col

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b;

    cin>>A>>B;
    
    a = A.length();
    b = B.length();
    
    A.insert(A.begin(),' ');
    B.insert(B.begin(),' ');

    for(int row=1;row<=a;row++)
    {
        for(int col=1;col<=b;col++)
        {
            dp[row][col] = max(max(dp[row-1][col],dp[row][col-1]),
                                dp[row-1][col-1]+(A[row]==B[col]?1:0));
        }
    }

    cout<<a+b-dp[a][b]<<'\n';

    return  0;
}