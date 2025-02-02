#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;

    getline(cin, S);
    
    if (S.length() > 2 && S.front() == '\"' && S.back() == '\"') {
        cout<<S.substr(1, S.length()-2)<<'\n';
    } else {
        cout<<"CE\n";
    }

    return 0;
}