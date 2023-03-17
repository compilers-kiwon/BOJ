#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,min_sum,r,c;

    cin>>N;
    min_sum = 0x7FFFFFFF;

    for(int row=1;row<=N;row++)
    {
        int col = N/row;

        col += (row*col==N)?0:1;

        if( row+col < min_sum )
        {
            r = row;
            c = col;
            min_sum = row+col;
        }
    }

    cout<<r<<' '<<c<<'\n';

    return  0;
}