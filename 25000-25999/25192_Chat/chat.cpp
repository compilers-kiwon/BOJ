#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

const static string NEW_USER = "ENTER";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,sum;
    set<string> user;

    cin>>N;
    sum = 0;

    for (int i=1;i<=N;i++) {
        string  str;

        cin>>str;

        if (str == NEW_USER) {
            sum += user.size();
            user.clear();
        } else {
            user.insert(str);
        }
    }

    cout<<sum+user.size()<<'\n';
    return  0;
}