#include    <iostream>
#include    <string>

using namespace std;

const static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static inline char  get_shifted_letter(int idx,int offset)
{
    return  letters[(idx+offset)%letters.length()];
}

static inline int   get_idx(char c)
{
    return  letters.find(c);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin>>t;t>0;t--) {
        int     i,j;
        string  keyword,plaintext;

        cin>>keyword>>plaintext;
        cout<<"Ciphertext: ";

        for (i=j=0;i<plaintext.length();
                i++,j=(j+1)%keyword.length()) {
            cout<<get_shifted_letter(get_idx(plaintext[i]),get_idx(keyword[j]));
        }

        cout<<'\n';
    }

    return  0;
}