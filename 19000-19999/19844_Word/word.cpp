#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define is_prefix(s,h) \
    (((s).length()>(h).length())&&((s).substr(0,(h).length())==(h)))

#define is_included(str,c)  ((str).find((c))!=string::npos)

const static vector<string> head = {
    "c'","j'","n'","m'","t'","s'","l'","d'","qu'"
};

const static string vowel = "aeiouh";

int can_be_divided(const string& str)
{
    for(int i=0;i<head.size();i++)
    {
        if( is_prefix(str,head[i]) &&
                is_included(vowel,str[head[i].length()]) )
        {
            return  1;
        }
    }

    return  0;
}

int count_num_of_words(const string& str)
{
    int             ret;
    string          s;
    vector<string>  w;

    for(int i=0;i<str.length();i++)
    {
        if( str[i]==' ' || str[i]=='-' )
        {
            w.push_back(s);
            s.clear();
        }
        else
        {
            s.push_back(str[i]);
        }
    }

    ret = w.size();

    for(int i=0;i<w.size();i++)
    {
        ret += (can_be_divided(w[i]))?1:0;
    }

    return  ret;
}

int main(void)
{
    string  str;

    getline(cin,str);
    str.push_back(' ');
    cout<<count_num_of_words(str)<<'\n';

    return  0;
}