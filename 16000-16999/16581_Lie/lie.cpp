#include    <iostream>
#include    <string>

using namespace std;

#define TRUTH       0
#define LIE         1
#define MAX_STATE   2
#define STATE(n)    ((n)%MAX_STATE)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cur;

    cin>>n;
    cur = TRUTH;

    for (int i=1;i<=n;i++) {
        string  s;

        cin>>s;
        cur = STATE(cur+(s=="LIE"?LIE:TRUTH));
    }

    cout<<(cur==TRUTH?"TRUTH":"LIE")<<'\n';
    return  0;
}