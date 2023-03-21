#include    <iostream>
#include    <string>

using namespace std;

const string translation_table = "yhesocvxduiglbkrztnwjpfmaq";

#define get_idx(c)      ((c)-'a')
#define translate(c)    ((c)==' '?' ':translation_table[get_idx((c))])

int main(void)
{
    int T;

    cin>>T;getchar();

    for(int i=1;i<=T;i++)
    {
        string  G,S;

        getline(cin,G);

        for(int j=0;j<G.length();j++)
        {
            S.push_back(translate(G[j]));
        }

        cout<<"Case #"<<i<<": "<<S<<'\n';
    }

    return  0;
}