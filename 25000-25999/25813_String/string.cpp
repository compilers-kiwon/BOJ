#include    <iostream>
#include    <string>

using namespace std;

static string   str;

#define HEAD_CHAR   'U'
#define MIDDLE_CHAR 'C'
#define TAIL_CHAR   'F'

int change_str(int from,char expected,
                    int offset,char filled)
{
    int i;

    for(i=from;str[i]!=expected;i+=offset)
    {
        str[i] = filled;
    }

    return  i;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int from,to;

    cin>>str;
    
    from = change_str(0,HEAD_CHAR,1,'-');
    to = change_str(str.length()-1,TAIL_CHAR,-1,'-');

    fill(&str[from+1],&str[to],MIDDLE_CHAR);
    cout<<str<<'\n';

    return  0;
}