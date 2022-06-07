#include    <iostream>
#include    <string>

using namespace std;

typedef enum {
    TEMPERATURE,
    OXYGEN,
    OCEAN,
    MAX_PARAM
} Param;

#define determine_parameter(s)  ((s)=="temperature"?TEMPERATURE:(s)=="oxygen"?OXYGEN:OCEAN)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,ocean,oxygen,celsius;

    cin>>N;

    ocean = oxygen = 0;
    celsius = -30;

    for(int i=1;i<=N;i++)
    {
        string  str;
        int     change;
        Param   p;

        cin>>str>>change;
        p = determine_parameter(str);

        switch(p)
        {
            case    TEMPERATURE :
                celsius += change;
                break;
            case    OXYGEN :
                oxygen += change;
                break;
            case    OCEAN :
                ocean += change;
                break;
            default :
                // do nothing
                break;
        }
    }

    if( ocean>=9 && oxygen>=14 && celsius>=8 )
    {
        cout<<"liveable\n";
    }
    else
    {
        cout<<"not liveable\n";
    }

    return  0;
}