#include    <iostream>

using namespace std;

#define HEISEI_YEAR 31
#define IS_LATER(a,b)   {if((a)!=(b))if((a)<(b))return true;else return false;}

const struct {int y,m,d;} last = {HEISEI_YEAR,4,30};

bool    is_later(int year,int month,int day)
{
    IS_LATER(last.y,year);
    IS_LATER(last.m,month);
    IS_LATER(last.d,day);

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  str;
        int     y,m,d;
        
        cin>>str;

        if( str == "#" )
        {
            break;
        }

        cin>>y>>m>>d;

        if( is_later(y,m,d) == true )
        {
            cout<<"? "<<y-HEISEI_YEAR+1<<' '<<m<<' '<<d<<'\n';
        }
        else
        {
            cout<<"HEISEI "<<y<<' '<<m<<' '<<d<<'\n';
        }
    }

    return  0;     
}