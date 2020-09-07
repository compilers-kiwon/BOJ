#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef unsigned int uint32;

map<char,uint32> table;

void init_table(void)
{
    for(char c='0';c<='9';c++)
    {
        table[c] = (uint32)(c-'0');
    }
    
    for(char c='A';c<='Z';c++)
    {
        table[c] = (uint32)(c-'A')+10;
    }
}

int main(void)
{
    string str;
    uint32 N,value;
    
    cin>>str>>N;
    value = 0;
    
    init_table();
    
    for(int i=0;i<str.length();i++)
    {
        value = value*N+table[str[i]];
    }
    cout<<value<<endl;
    
    return 0;
}
