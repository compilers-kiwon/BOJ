#include    <iostream>
#include    <string>

using namespace std;

const string    lower = "abcdefghijklmnopqrstuvwxyz";
const string    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define MAX_SIZE    26

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_lower(c)         IN_RANGE('a',(c),'z')
#define is_upper(c)         IN_RANGE('A',(c),'Z')
#define is_chr(c)           (is_lower((c))||is_upper((c)))
#define get_index(c,b)      ((int)((c)-(b)))

int get_offset(char from,char to,const string& table)
{
    int ret = 0;

    for(int offset=0;offset<MAX_SIZE;offset++)
    {
        int converted;

        converted = (get_index(from,table.front())+offset)%MAX_SIZE;

        if( table[converted] == to )
        {
            ret = offset;
            break;
        }
    }

    return  ret;
}

char    reverse_cypher(char to,const string& table,int offset)
{
    char    ret;

    for(int i=0;i<MAX_SIZE;i++)
    {
        int converted = (i+offset)%MAX_SIZE;

        if( table[converted] == to )
        {
            ret = table[i];
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
        string  str;
        int     offset;

        getline(cin,str);

        if( str == "#" )
        {
            break;
        }

        offset = get_offset('A',str.back(),upper);

        for(int i=0;i<str.length()-1;i++)
        {
            if( !is_chr(str[i]) )
            {
                cout<<str[i];
                continue;
            }

            if( is_lower(str[i]) == true )
            {
                cout<<reverse_cypher(str[i],lower,offset);
            }
            else
            {
                cout<<reverse_cypher(str[i],upper,offset);
            }
        }

        cout<<'\n';
    }

    return  0;
}