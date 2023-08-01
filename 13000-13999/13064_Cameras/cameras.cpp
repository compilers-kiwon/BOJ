#include    <iostream>
#include    <string>

using namespace std;

#define LETTER_POS  4

bool    is_violated(const string& str)
{
    if(str[0]!=str[1] ||
        !isupper(str[LETTER_POS])) {
        return  true;
    }

    for (int i=0;i<str.length();i++) {
        if (i == LETTER_POS) {
            continue;
        }
        
        if (str[i]=='0' ||
                !isdigit(str[i])) {
            return  true;
        }
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        string  str;

        cin>>str;
        cout<<(is_violated(str)?"":str+"\n");
    }

    return  0;
}