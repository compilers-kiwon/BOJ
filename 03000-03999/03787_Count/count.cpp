#include    <iostream>

using namespace std;

#define MAX_NUM (10000000)

typedef pair<int,int>   Term;

static Term t[MAX_NUM+1];

int init(void)
{
    for (int sum=2,cnt=1;cnt<=MAX_NUM;sum++) {
        int row,col;

        if (sum%2 == 1) {
            row=1,col=sum-1;
        } else {
            row=sum-1,col=1;
        }

        for (int i=1;cnt<=MAX_NUM&&i<sum;i++,cnt++) {
            t[cnt] = {row,col};
            if (sum%2 == 1) row++,col--;
            else row--,col++;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    
    for (int n;scanf("%d",&n)==1;
            cout<<"TERM "<<n<<" IS "<<
            t[n].first<<'/'<<t[n].second<<'\n');

    return  0;
}