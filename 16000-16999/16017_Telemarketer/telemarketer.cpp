#include    <iostream>

using namespace std;

#define MAX_SIZE    4

bool    check_number(const char* num)
{
    if( !(num[0]=='8' || num[0]=='9') )
    {
        return  false;
    }

    if( num[1] != num[2] )
    {
        return  false;
    }

    if( !(num[3]=='8' || num[3]=='9') )
    {
        return  false;
    }

    return  true;
}

int     main(void)
{
    char    num[MAX_SIZE];

    cin>>num[0]>>num[1]>>num[2]>>num[3];

    if( check_number(num) == true )
    {
        cout<<"ignore\n";
    }
    else
    {
        cout<<"answer\n";
    }

    return  0;
}