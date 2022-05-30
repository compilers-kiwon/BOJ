#include    <iostream>
#include    <cmath>
#include    <cfloat>

using namespace std;

#define get_distance(x,y)   ((x)*(x)+(y)*(y))

int main(void)
{
    for(;;)
    {
        int     D;
        double  E,cost,min_cost;

        scanf("%d %lf",&D,&E);

        if( D==0 && E==0.0 )
        {
            break;
        }

        min_cost = DBL_MAX;

        for(int x=0,y=D;x<=D;x++,y--)
        {           
            cost = sqrt(get_distance(x,y));
            min_cost = min(min_cost,abs(cost-E));
        }

        printf("%0.3f\n",min_cost);
    }

    return  0;
}