#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L,x,cur,denied;

    cin>>L>>x;
    cur = denied = 0;

    for (int i=1;i<=x;i++) {
        int     p;
        string  str;

        cin>>str>>p;

        if (str == "enter") {
            if ((cur+=p) > L) {
                cur -= p;
                denied++;
            } 
        } else {
            cur -= p;
        }
    }

    cout<<denied<<'\n';
    return  0;
}