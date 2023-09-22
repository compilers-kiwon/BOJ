#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define NUM_OF_WORDS    3
#define read_str(str)   (getline(cin,(str)))
#define read_num(n)     {string str;read_str(str);(n)=stoi(str);}
#define read_words(v,n) {for(int i=0;i<(n);i++)\
                            {string str;read_str(str);(v).push_back(str);}\
                        }

int build_sentence(vector<string> words[],
                        int cur_word,string s)
{
    if (cur_word == NUM_OF_WORDS) {
        s.pop_back();
        cout<<s<<".\n";
        return  0;
    }

    for (int i=0;i<words[cur_word].size();i++) {
        build_sentence(words,cur_word+1,
                        s+words[cur_word][i]+" ");
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_data_sets;
    read_num(num_of_data_sets);

    for (int i=1;i<=num_of_data_sets;i++) {
        vector<int>     n;
        vector<string>  w[NUM_OF_WORDS];

        for (int j=0;j<NUM_OF_WORDS;j++) {
            int num_of_words;

            read_num(num_of_words);
            n.push_back(num_of_words);
        }

        for (int j=0;j<NUM_OF_WORDS;j++) {
            read_words(w[j],n[j]);
        }

        build_sentence(w,0,"");
        cout<<'\n';
    }

    return  0;
}