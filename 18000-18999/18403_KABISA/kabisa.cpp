#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define is_leap_year(y) (((y)%4)==0)

void    get_year_num(string& str,vector<int>& year)
{
    int n = 0;

    str.push_back(',');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        switch(c)
        {
            case    ' ':
                break;
            case    ',':
                year.push_back(n);
                n = 0;
                break;
            default:    // 0~9
                n = n*10+(int)(c-'0');
                break;
        }
    }
}

int     main(void)
{
    int T;

    cin>>T;getchar();

    for(int t=1;t<=T;t++)
    {
        string      str;
        vector<int> year;

        getline(cin,str);
        get_year_num(str,year);

        for(int i=0;i<year.size();i++)
        {
            if( is_leap_year(year[i]) == true )
            {
                cout<<year[i]<<' ';
            }
        }

        cout<<'\n';
    }

    return  0;
}