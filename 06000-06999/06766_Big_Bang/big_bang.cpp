#include    <iostream>

using namespace std;

#define MAX_LEN 20

const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define get_offset(P,K) (3*(P)+(K))
#define shift(c,offset) (((int)((c)-'A')+26-(offset))%26)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     K;
    char    str[MAX_LEN+2] = {'\0',};

    cin>>K>>&str[1];

    for (int i=1;str[i]!='\0';i++) {
        cout<<letters[shift(str[i],get_offset(i,K))];
    }

    cout<<'\n';
    return  0;
}