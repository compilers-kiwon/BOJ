#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define BIT_LEN_PER_BYTE    8
#define PADDING             '='

map<char,string>  base32_table;

void    init_base32_table(void)
{
    base32_table['A'] = "00000";
    base32_table['B'] = "00001";
    base32_table['C'] = "00010";
    base32_table['D'] = "00011";
    base32_table['E'] = "00100";
    base32_table['F'] = "00101";
    base32_table['G'] = "00110";
    base32_table['H'] = "00111";
    base32_table['I'] = "01000";
    base32_table['J'] = "01001";
    base32_table['K'] = "01010";
    base32_table['L'] = "01011";
    base32_table['M'] = "01100";
    base32_table['N'] = "01101";
    base32_table['O'] = "01110";
    base32_table['P'] = "01111";
    base32_table['Q'] = "10000";
    base32_table['R'] = "10001";
    base32_table['S'] = "10010";
    base32_table['T'] = "10011";
    base32_table['U'] = "10100";
    base32_table['V'] = "10101";
    base32_table['W'] = "10110";
    base32_table['X'] = "10111";
    base32_table['Y'] = "11000";
    base32_table['Z'] = "11001";
    base32_table['2'] = "11010";
    base32_table['3'] = "11011";
    base32_table['4'] = "11100";
    base32_table['5'] = "11101";
    base32_table['6'] = "11110";
    base32_table['7'] = "11111";
}

void    base32_to_ascii(const string& base32,string& ascii_str)
{
    for(int i=0;i<base32.length()&&base32[i]!=PADDING;i++)
    {
        ascii_str += base32_table[base32[i]];
    }

    if( ascii_str.length()%BIT_LEN_PER_BYTE != 0 )
    {
        ascii_str.erase((ascii_str.length()/BIT_LEN_PER_BYTE)*BIT_LEN_PER_BYTE,ascii_str.length()%BIT_LEN_PER_BYTE);
    }
}

char    get_char(const string& str,int ptr)
{
    char    ret = 0;

    for(int i=0;i<BIT_LEN_PER_BYTE;i++)
    {
        ret = (ret<<1)+(str[ptr+i]=='0'?0:1);
    }

    return  ret;
}

void    print_ascii(const string& ascii_str)
{
    for(int i=0;i<ascii_str.length();i+=BIT_LEN_PER_BYTE)
    {
        cout<<get_char(ascii_str,i);
    }
    cout<<"\n";
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  base32,ascii;

    cin>>base32;
    init_base32_table();
    
    base32_to_ascii(base32,ascii);
    print_ascii(ascii);

    return  0;
}