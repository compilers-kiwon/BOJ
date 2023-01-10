#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    1024
#define POOLING_POS 2

int N,arr[MAX_SIZE][MAX_SIZE];

int do_pooling(int row,int col,int size)
{
    if( size == 1 )
    {
        return  arr[row][col];
    }

    vector<int> result;

    for(int r=row;r<row+size;r+=size/2)
    {
        for(int c=col;c<col+size;c+=size/2)
        {
            result.push_back(do_pooling(r,c,size/2));
        }
    }

    sort(result.begin(),result.end());

    return  result[POOLING_POS];
}

void    input(void)
{
    cin>>N;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            cin>>arr[row][col];
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    cout<<do_pooling(0,0,N)<<'\n';

    return  0;
}