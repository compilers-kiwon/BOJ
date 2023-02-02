#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<string,string>   translation_table;

static const string from[] = 
    {"a","i","y","l","n","ne",
        "o","r","a","t","u","v","w"};

static const string to[] =
    {"as","ios","ios","les","anes","anes","os",
                "res","as","tas","us","ves","was"};

#define get_size_of_arr(arr)    (sizeof((arr))/sizeof((arr)[0]))

#define get_tail(str,tail_len) \
            ((str).substr((str).length()-(tail_len),tail_len))

void    init(int& num_of_words)
{
    cin>>num_of_words;

    for(int i=0;i<get_size_of_arr(from);i++)
    {
        translation_table[from[i]] = to[i];
    }
}

string  trnaslate_word(const string& word)
{
    string  head = word;
    string  latin_tail = "us";
    
    map<string,string>::iterator it;

    for(it=translation_table.begin();
            it!=translation_table.end();it++)
    {
        int     tail_len = (it->first).length();
        string  word_tail = get_tail(word,tail_len);
        
        if( it->first == word_tail )
        {
            head = word.substr(0,word.length()-tail_len);
            latin_tail = it->second;
            break;
        }
    }

    return  head+latin_tail;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    init(N);

    for(int i=1;i<=N;i++)
    {
        string  word;

        cin>>word;
        cout<<trnaslate_word(word)<<'\n';
    }

    return  0;
}