#include <iostream>
#include <string>

using namespace std;

int main(void) {
    const string complete = "UAPC";
    string remained, removed;

    cin>>remained;

    for (size_t i = 0; i < complete.length(); i++) {
        if (remained.find(complete[i]) == string::npos) {
            removed.push_back(complete[i]);
        }
    }

    cout<<removed<<'\n';
    return 0;
}