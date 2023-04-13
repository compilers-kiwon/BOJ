#include    <iostream>

using namespace std;

#define MAX_DEGREE  180
#define MAX_MINUTE  720
#define EACH_DEGREE 6

static bool visited[MAX_DEGREE+1];

int init(void)
{
    for(int i=0;i<MAX_MINUTE;i++)
    {
        int m = (i*EACH_DEGREE)%360;
        int h = (i/12)*EACH_DEGREE;
        int diff = max(h,m)-min(h,m);
        
        diff = (diff>MAX_DEGREE)?360-diff:diff;
        visited[diff] = true;
    }

    return  0;
}

int main(void)
{
    int A;

    init();

    for(;scanf("%d",&A)==1;)
        puts(visited[A]?"Y":"N");
    
    return  0;
}