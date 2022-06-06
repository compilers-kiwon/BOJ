#include    <iostream>
#include    <cmath>

using namespace std;

double              r,length[3];
pair<double,double> pos[3];

double  get_length(int p1,int p2)
{
    double  dx = pos[p1].first-pos[p2].first;
    double  dy = pos[p1].second-pos[p2].second;

    return  sqrt(dx*dx+dy*dy);
}

double  get_area(void)
{
   double&  a = length[0];
   double&  b = length[1];
   double&  c = length[2];

   return   sqrt(4.0*a*a*b*b-(a*a+b*b-c*c)*(a*a+b*b-c*c))/4.0;
}

double  get_radius(double A)
{
   double&  a = length[0];
   double&  b = length[1];
   double&  c = length[2];

   return   (2*A)/(a+b+c);
}

double  get_difference(double measured,double computed)
{
    if( measured == computed )
    {
        return  0.0;
    }

    double  ret;

    if( measured > computed )
    {
        ret = (measured-computed)/measured*-100.0;
    }
    else
    {
        ret = (computed-measured)/measured*100.0;
    }

    return  ret;
}

void    input(void)
{
    for(int i=0;i<3;i++)
    {
        cin>>pos[i].first>>pos[i].second;
    }

    cin>>r;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<3;i++)
    {
        length[i] = get_length(i,(i+1)%3);
    }

    double  A = get_area();
    double  computed_radius = get_radius(A);

    cout.setf(ios::fixed);cout.precision(3);
    cout<<get_difference(r,computed_radius)<<'\n';

    return  0;
}