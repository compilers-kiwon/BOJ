#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define NONE    -1

#define NUM_OF_SEPARATORS   7

const string separator[NUM_OF_SEPARATORS] = {
    "<",">","&&","||","(",")"," "
};

#define ADD_NEW_TOKEN(t)        ((t).push_back(""))
#define ADD_NEW_SEPARATOR(t,s)  {(t).push_back(separator[(s)]);(t).push_back("");}
#define REMOVE_SEPARATOR(t,s)   ((t).erase((t).length()-separator[(s)].length()))
#define GET_SEPARATOR(t,s)      ((t).substr((t).length()-separator[(s)].length()))

#define is_empty(s) ((s).empty()||(s)==" ")

int is_separator(const string& str)
{
    for(int i=0;i<NUM_OF_SEPARATORS;i++)
    {
        if( str.length() >= separator[i].length() && 
                    GET_SEPARATOR(str,i) == separator[i] )
        {
            return  i;
        }
    }

    return  NONE;
}

int tokenize(string& str,vector<string>& tokens)
{
    str.push_back(' ');
    ADD_NEW_TOKEN(tokens);

    for(int i=0;i<str.length();i++)
    {
        int     n;
        string& current = tokens.back();
        
        current.push_back(str[i]);

        if( (n=is_separator(current)) == NONE )
        {
            continue;
        }

        REMOVE_SEPARATOR(current,n);
        ADD_NEW_SEPARATOR(tokens,n);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string          str;
    vector<string>  t;

    getline(cin,str);
    tokenize(str,t);

    for(int i=0;i<t.size();i++)
    {
        if(is_empty(t[i]))continue;
        cout<<t[i]<<((i==t.size()-1)?'\n':' ');
    }

    return  0;
}