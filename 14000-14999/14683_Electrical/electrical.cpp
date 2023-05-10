#include    <iostream>
#include    <cmath>

using namespace std;

#define is_odd(n)   ((n)%2!=0)

#define run_out_of_fuel(f,d)        ((f)>=(d)&&!is_odd((f)-(d)))
#define get_distance(x1,y1,x2,y2)   (abs((x1)-(x2))+abs((y1)-(y2)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b,c,d,t,dist;

    cin>>a>>b>>c>>d>>t;
    dist = get_distance(a,b,c,d);

    cout<<(run_out_of_fuel(t,dist)?'Y':'N')<<'\n';

    return  0;
}