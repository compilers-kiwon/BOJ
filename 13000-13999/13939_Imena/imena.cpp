#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    get_words(const string& str,vector<string>& words)
{
    string  w;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == ' ' )
        {
            words.push_back(w);
            w.clear();
        }
        else
        {
            w.push_back(str[i]);
        }
    }
}

bool    is_name(const string& str)
{
    if( !IN_RANGE('A',str.front(),'Z') )
    {
        return  false;
    }

    for(int i=1;i<str.length();i++)
    {
        if( !IN_RANGE('a',str[i],'z') )
        {
            return  false;
        }
    }

    return  true;
}

void    get_sentences(const string& str,vector<string>& sentences)
{
    string  s;

    for(int i=0;i<str.length();i++)
    {
        if( str[i]=='.' || str[i]=='?' || str[i]=='!' )
        {
            s.push_back(' ');
            sentences.push_back(s);
            s.clear();
        }
        else
        {
            s.push_back(str[i]);
        }
    }
}

int     main(void)
{
    int             N;
    string          str;
    vector<string>  sentences;

    cin>>N;getchar();
    getline(cin,str);

    get_sentences(str,sentences);

    for(int i=0;i<sentences.size();i++)
    {
        int             cnt = 0;
        vector<string>  words;

        get_words(sentences[i],words);

        for(int j=0;j<words.size();j++)
        {
            if( is_name(words[j]) == true )
            {
                cnt++;
            }
        }

        cout<<cnt<<'\n';
    }

    return  0;
}