#include    <iostream>
#include    <string>

using namespace std;

#define UPPER_OFFSET        32
#define get_upper(c)        (c-UPPER_OFFSET)
#define to_be_hidden(t,c)   (t[c])

void    init_hidden_table(bool table[],char lower1,char lower2)
{
    fill(&table[0],&table[0x100],false);

    table[lower1] = table[get_upper(lower1)] = true;
    table[lower2] = table[get_upper(lower2)] = true;
}

void    hide_letters(string& str,char lower1,char lower2)
{
    bool    hidden_table[0x100];

    init_hidden_table(hidden_table,lower1,lower2);

    for(int i=0;i<str.length();i++)
    {
        if( to_be_hidden(hidden_table,str[i]) == true )
        {
            str[i] = '_';
        }
    }
}

int     main(void)
{
    for(int i=1;;i++)
    {
        char    c1,c2;
        int     n;

        cin>>c1>>c2;getchar();

        if( c1=='#' && c2=='#' )
        {
            break;
        }

        cin>>n;getchar();
        cout<<"Case "<<i<<'\n';

        for(int j=1;j<=n;j++)
        {
            string  str;

            getline(cin,str);
            hide_letters(str,c1,c2);

            cout<<str<<'\n';
        }

        cout<<'\n';
    }

    return  0;
}