#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define REQUIRED_STR_LEN    5
#define REQUIRED_BASE32_LEN 8
#define PADDING             '='

map<string,char>  base32_table;

void    init_base32_table(void)
{
    base32_table["00000"] = 'A';
    base32_table["00001"] = 'B';
    base32_table["00010"] = 'C';
    base32_table["00011"] = 'D';
    base32_table["00100"] = 'E';
    base32_table["00101"] = 'F';
    base32_table["00110"] = 'G';
    base32_table["00111"] = 'H';
    base32_table["01000"] = 'I';
    base32_table["01001"] = 'J';
    base32_table["01010"] = 'K';
    base32_table["01011"] = 'L';
    base32_table["01100"] = 'M';
    base32_table["01101"] = 'N';
    base32_table["01110"] = 'O';
    base32_table["01111"] = 'P';
    base32_table["10000"] = 'Q';
    base32_table["10001"] = 'R';
    base32_table["10010"] = 'S';
    base32_table["10011"] = 'T';
    base32_table["10100"] = 'U';
    base32_table["10101"] = 'V';
    base32_table["10110"] = 'W';
    base32_table["10111"] = 'X';
    base32_table["11000"] = 'Y';
    base32_table["11001"] = 'Z';
    base32_table["11010"] = '2';
    base32_table["11011"] = '3';
    base32_table["11100"] = '4';
    base32_table["11101"] = '5';
    base32_table["11110"] = '6';
    base32_table["11111"] = '7';
}

void    hex2str(const char& c,string& str)
{
    for(int i=7;i>=0;i--)
    {
        if( (c&(1<<i)) == 0 )
        {
            str.push_back('0');
        }
        else
        {
            str.push_back('1');
        }
    }
}

void    str2base32(string& str,string& base32)
{
    for(;(str.length()%REQUIRED_STR_LEN)!=0;str.push_back('0'));

    for(int i=0;i<str.length();i+=REQUIRED_STR_LEN)
    {
        base32.push_back(base32_table[str.substr(i,REQUIRED_STR_LEN)]);
    }

    for(;(base32.length()%REQUIRED_BASE32_LEN)!=0;base32.push_back(PADDING));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  input,intermediate,output;

    cin>>input;
    init_base32_table();

    for(int i=0;i<input.length();i++)
    {
        string  tmp;

        hex2str(input[i],tmp);
        intermediate += tmp;
    }

    str2base32(intermediate,output);
    cout<<output<<'\n';

    return  0;
}