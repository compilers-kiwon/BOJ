#include    <string>
#include    <iostream>
#include    <vector>

using namespace std;

void    get_words_from_sentence(string& sentence,vector<string>& words)
{
    string  w;

    sentence.push_back(' ');

    for(int i=0;i<sentence.length();i++)
    {
        char&   c = sentence[i];

        if( c == ' ' )
        {
            words.push_back(w);
            w.clear();
        }
        else
        {
            w.push_back(c);
        }
    }
}

int     get_num_of_words_to_include_ae(const vector<string>& words)
{
    int ret = 0;

    for(int i=0;i<words.size();i++)
    {
        if( words[i].find("ae") != string::npos )
        {
            ret++;
        }
    }
    
    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string          str;
    vector<string>  w;
    int             n1,n2;

    getline(cin,str);
    get_words_from_sentence(str,w);

    n1 = w.size();
    n2 = get_num_of_words_to_include_ae(w);

    if( (n2*100)/n1 >= 40 )
    {
        cout<<"dae ae ju traeligt va\n";
    }
    else
    {
        cout<<"haer talar vi rikssvenska\n";
    }

    return  0;
}