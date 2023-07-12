#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    0x100

static string   table[MAX_SIZE];

int init_table(void)
{
    int n = 1;

    for(char c='a';c<='z';c++,n++)
    {
        table[c] = to_string(n);
    }

    for(char c='A';c<='Z';c++,n++)
    {
        table[c] = to_string(n);
    }

    for(char c='0';c<='9';c++)
    {
        table[c] = "#"+string(1,c);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    init_table();
    getline(cin,str);
    
    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];
        string& enc = table[c];

        switch(enc.length())
        {
            case 0:cout<<c;break;
            case 1:cout<<"0"<<enc;break;
            case 2:cout<<enc;break;
            default:/*do nothing*/;break;
        }
    }

    return  0;
}