#include    <iostream>
#include    <string>

using namespace std;

bool    can_build_new_word(const string& str)
{
    int     cnt = 0;
    bool    table[0x100] = {false,};

    for(int i=0;i<str.length();i++)
    {
        if( table[str[i]] == false )
        {
            cnt++;
            table[str[i]] = true;
        }
    }

    return  (cnt>1);
}

bool    check_head_and_tail(const string& w1,
                                const string& w2)
{
    return  (w1.front()==w2.front())
                &&(w1.back()==w2.back());
}

bool    check_order_of_consonants(const string& w1,
                                    const string& w2)
{
    const static string vowels = "aeiou";
    
    int     count[2][0x100];
    string  vowel_removed[2];

    fill(&count[0]['a'],&count[0]['z'+1],0);
    fill(&count[1]['a'],&count[1]['z'+1],0);

    for(int i=0;i<w1.length();i++)
    {
        count[0][w1[i]]++;
        count[1][w2[i]]++;

        if( vowels.find(w1[i]) == string::npos )
        {
            vowel_removed[0].push_back(w1[i]);
        }

        if( vowels.find(w2[i]) == string::npos )
        {
            vowel_removed[1].push_back(w2[i]);
        }
    }

    if( vowel_removed[0] != vowel_removed[1] )
    {
        return  false;
    }

    for(int i='a';i<='z';i++)
    {
        if( count[0][i] != count[1][i] )
        {
            return  false;
        }
    }

    return  true;
}

bool    compare_words(string& w1,string& w2)
{
    return  (can_build_new_word(w1)
                && check_head_and_tail(w1,w2)
                && check_order_of_consonants(w1,w2));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  w1,w2;

    cin>>N>>w1>>w2;
    cout<<((compare_words(w1,w2)==true)?"YES":"NO")<<'\n';

    return  0;
}