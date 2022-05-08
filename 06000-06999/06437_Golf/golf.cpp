#include    <iostream>
#include    <string>

using namespace std;

string  get_score(int par,int num_of_strokes)
{
    if( num_of_strokes== 1 )
    {
        return  "Hole-in-one";
    }

    string  ret;

    switch(par-num_of_strokes)
    {
        case    0:
            ret = "Par";
            break;
        case    1:
            ret = "Birdie";
            break;
        case    2:
            ret = "Eagle";
            break;
        case    3:
            ret = "Double eagle";
            break;
        case    -1:
            ret = "Bogey";
            break;
        default:
            ret = "Double Bogey";
            break;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;;i++)
    {
        int p,s;

        cin>>p>>s;
        
        if( p==0 && s==0 )
        {
            break;
        }

        cout<<"Hole #"<<i<<'\n'<<get_score(p,s)<<".\n\n";
    }

    return  0;
}