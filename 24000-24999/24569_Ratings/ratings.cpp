#include    <iostream>

using namespace std;

#define STARS_FOR_POINT 5
#define STARS_FOR_FOUL  -3
#define MINIMUM_RATING  40

#define get_star(s,f)   ((s)*STARS_FOR_POINT+(f)*STARS_FOR_FOUL)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;

    cin>>N;
    M = 0;

    for(int i=1;i<=N;i++)
    {
        int s,f;

        cin>>s>>f;
        M += ((get_star(s,f)>MINIMUM_RATING)?1:0);
    }

    cout<<M<<(N==M?"+\n":"\n");
    return  0;
}