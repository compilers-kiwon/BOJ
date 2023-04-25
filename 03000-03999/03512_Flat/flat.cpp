#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static int  n,c;
static map<string,int>  rooms;

int input(void)
{
    int ret = 0;

    cin>>n>>c;

    for(int i=1;i<=n;i++)
    {
        int     a;
        string  t;

        cin>>a>>t;

        ret += a;
        rooms[t] += a;
    }

    return  ret;
}

int main(void)
{
    int total_area = input();

    printf("%d\n%d\n%.6f\n",total_area,rooms["bedroom"],
                ((double)total_area-(double)rooms["balcony"]/2.0)*(double)c);
    
    return  0;
}