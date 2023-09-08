#include    <iostream>
#include    <string>

using namespace std;

#define INF             0x7FFFFFFF
#define NUM_OF_WORDS    2

string  mix_words(string w[],int len)
{
    string  ret;

    for (int i=0;i<len;i++) {
        ret.push_back(w[i%2][i]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     min_length = INF;
    string  w[NUM_OF_WORDS];

    for (int i=0;i<NUM_OF_WORDS;i++) {
        cin>>w[i];
        min_length = min(min_length,(int)w[i].length());
    }

    cout<<mix_words(w,min_length)<<'\n';

    return  0;
}