#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

#define get_distance(x1,y1,x2,y2)   (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

int     N;
float   d,x[MAX_SIZE],y[MAX_SIZE];

bool    input(void)
{
    cin>>d>>N;

    if( d==0.0 && N==0 )
    {
        return  false;
    }

    for(int i=1;i<=N;i++)
    {
        cin>>x[i]>>y[i];
    }

    return  true;
}

bool    fight(int n)
{
    bool    ret = false;

    for(int i=1;i<=N;i++)
    {
        if( i == n )
        {
            continue;
        }

        if( get_distance(x[n],y[n],x[i],y[i]) <= d*d )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        if( input() == false )
        {
            break;
        }

        int sour,sweet;

        sour = sweet = 0;

        for(int i=1;i<=N;i++)
        {
            if( fight(i) == true )
            {
                sour++;
            }
            else
            {
                sweet++;
            }
        }

        cout<<sour<<" sour, "<<sweet<<" sweet\n";
    }

    return  0;
}