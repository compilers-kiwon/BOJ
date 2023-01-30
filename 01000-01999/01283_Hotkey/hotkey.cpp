#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (30+1)
#define NONE        -1

int     N;
string  opt[MAX_SIZE];
bool    is_occupied[0x100];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_alphabet(c)      (IN_RANGE('a',(c),'z')||IN_RANGE('A',(c),'Z'))

void    input(void)
{
    cin>>N;getchar();

    for(int i=1;i<=N;i++)
    {
        getline(cin,opt[i]);
    }
}

int     get_hotkey(int idx)
{
    string& menu = opt[idx];
    
    for(int pos=0;pos<menu.length();)
    {
        for(;pos<menu.length()&&!is_alphabet(menu[pos]);pos++);

        if( pos == menu.length() )
        {
            break;
        }
        
        if( is_occupied[tolower(menu[pos])] == false )
        {
            is_occupied[tolower(menu[pos])] = true;
            return  pos;
        }

        for(pos++;pos<menu.length()&&is_alphabet(menu[pos]);pos++);
    }
    
    for(int pos=0;pos<menu.length();pos++)
    {
        char    c = menu[pos];

        if( !is_alphabet(c) )
        {
            continue;
        }

        if( is_occupied[tolower(c)] == false )
        {
            is_occupied[tolower(c)] = true;
            return  pos;
        }
    }

    return  NONE;
}

int     main(void)
{
    input();

    for(int i=1;i<=N;i++)
    {
        int hotkey_pos = get_hotkey(i);

        if( hotkey_pos == -1 )
        {
            cout<<opt[i]<<'\n';
        }
        else
        {
            for(int j=0;j<opt[i].length();j++)
            {
                if( j != hotkey_pos )
                {
                    cout<<opt[i][j];
                }
                else
                {
                    cout<<'['<<opt[i][j]<<']';
                }
            }

            cout<<'\n';
        }
    }

    return  0;
}