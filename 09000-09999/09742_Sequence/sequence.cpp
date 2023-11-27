#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

static inline bool simulate(string& str,int pos)
{
    int i;

    for (i=1;i<pos;i++) {
        if (!next_permutation(str.begin(),str.end())) {
            break;
        }
    }

    return  (i==pos);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int pos;
        string str;
        
        cin>>str>>pos;
        if (str.empty()) break;

        cout<<str<<' '<<pos<<" = ";
        cout<<(simulate(str,pos)?str:"No permutation")<<'\n';
    }

    return  0;
}