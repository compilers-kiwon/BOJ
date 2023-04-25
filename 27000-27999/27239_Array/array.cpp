#include    <iostream>

using namespace std;

#define MAX_NUM 64
#define MAX_ROW 8
#define MAX_COL 'h'

typedef pair<char,int>  Pos;

static Pos  p[MAX_NUM+1];

int init(void)
{
    int num = 1;

    for(int row=1;row<=MAX_ROW;row++)
    {
        for(char col='a';col<=MAX_COL;col++)
        {
            p[num++] = make_pair(col,row);
        }
    }

    return  0;
}

int main(void)
{
    int n;

    init();cin>>n;
    cout<<p[n].first<<p[n].second<<'\n';

    return  0;
}