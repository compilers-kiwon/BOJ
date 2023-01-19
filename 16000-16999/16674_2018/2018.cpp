#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define is_available(m,c)   ((m)[(c)]!=0)
#define get_num(m,c)        ((m)[(c)])

#define NONE    0
#define RELATED 1
#define CLOSE   2
#define TIED    8

bool    input(map<char,int>& digits)
{
    string  num;

    cin>>num;

    for(int i=0;i<num.length();i++)
    {
        char&   c = num[i];

        if( c=='2' || c=='0' || c=='1' || c=='8' )
        {
            digits[c]++;
        }
        else
        {
            return  false;
        }
    }

    return  true;
}

int     determine_attribute(map<char,int>& digits)
{
    int ret = RELATED;

    if( is_available(digits,'2') && is_available(digits,'0')
            && is_available(digits,'1') && is_available(digits,'8') )
    {
        ret = CLOSE;
    }

    if( get_num(digits,'2')==get_num(digits,'0')
        && get_num(digits,'0')==get_num(digits,'1')
        && get_num(digits,'1')==get_num(digits,'8') )
    {
        ret = TIED;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int attr;
    map<char,int>   table;

    attr = input(table)?determine_attribute(table):NONE;
    cout<<attr<<'\n';
    
    return  0;
}