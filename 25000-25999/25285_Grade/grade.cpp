#include    <iostream>

using namespace std;

#define get_bmi(w,h)    ((w)/((h)*(h)))
#define cm2m(n)         ((n)/100.0)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

int get_grade(double weight,double height)
{
    double  bmi = get_bmi(weight,cm2m(height));

    if(IN_RANGE(0.0,height,140.1)) return 6;
    if(IN_RANGE(140.1,height,146.0)) return 5;
    if(IN_RANGE(146.0,height,159.0)) return 4;
    if(IN_RANGE(159.0,height,161.0))
        if(IN_RANGE(16.0,bmi,35.0)) return 3;
        else return 4;
    if(IN_RANGE(161.0,height,204.0))
        if(IN_RANGE(20.0,bmi,25.0)) return 1;
        else if(IN_RANGE(18.5,bmi,20.0)||IN_RANGE(25.0,bmi,30.0)) return 2;
        else if(IN_RANGE(16.0,bmi,18.5)||IN_RANGE(30.0,bmi,35.0)) return 3;
        else return 4;
    return 4;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        double  h,w;

        cin>>h>>w;
        cout<<get_grade(w,h)<<'\n';
    }

    return  0;
}