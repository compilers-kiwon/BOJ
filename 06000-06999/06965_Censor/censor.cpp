#include    <iostream>
#include    <string>

using namespace std;

#define NONE        -1
#define SEPARATOR   ' '
#define REMOVED     '*'

#define LENGTH_OF_REMOVED_WORD  4

int remove_words(string& str,int length)
{
    int s_pos,cnt;

    s_pos = NONE;
    str.push_back(SEPARATOR);

    for(int i=0;i<str.length();i++)
    {
        if( str[i] != SEPARATOR )
        {
            if(s_pos==NONE) s_pos=i,cnt=1;
            else cnt++;
        }
        else
        {
            if(cnt==length)
                fill(&str[s_pos],&str[s_pos+length],REMOVED);
            s_pos=NONE,cnt=0;
        }
    }

    return  0;
}

int main(void)
{
    int n;

    cin>>n;getchar();

    for(int i=1;i<=n;i++)
    {
        string  str;

        getline(cin,str);
        remove_words(str,LENGTH_OF_REMOVED_WORD);
        cout<<str<<"\n\n";
    }

    return  0;
}