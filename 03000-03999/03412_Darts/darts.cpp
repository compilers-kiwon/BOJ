#include    <iostream>

using namespace std;

#define MAX_POINTS  10

const static int r[MAX_POINTS+1] = {
    -1,20*20,40*40,60*60,80*80,100*100,120*120,140*140,160*160,180*180,200*200
};

#define GET_POINT(n)    (11-(n))

int get_points(int num_of_throws)
{
    int ret = 0;

    for(int i=1;i<=num_of_throws;i++)
    {
        int x,y,d,p;

        cin>>x>>y;
        d = x*x+y*y;

        for(p=1;p<=MAX_POINTS&&d>r[p];p++);
        ret += (p>MAX_POINTS)?0:GET_POINT(p);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {

        int n;

        cin>>n;
        cout<<get_points(n)<<'\n';
    }

    return  0;
}