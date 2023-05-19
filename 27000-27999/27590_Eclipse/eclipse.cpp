#include    <iostream>

using namespace std;

#define is_right_position(current,period)   ((current)%(period)==0)

int simulate(int ds,int ys,int dm,int ym)
{
    int ret;

    for(ret=1;;ret++)
    {
        if( is_right_position(ds+ret,ys)
                && is_right_position(dm+ret,ym) )
        {
            break;
        }
    }

    return  ret;
}

int main(void)
{
    int ds,ys,dm,ym;

    cin>>ds>>ys>>dm>>ym;
    cout<<simulate(ds,ys,dm,ym)<<'\n';

    return  0;
}