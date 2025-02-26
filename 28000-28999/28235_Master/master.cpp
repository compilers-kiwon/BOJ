#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    unordered_map<string,string> table = {
        {"SONGDO", "HIGHSCHOOL"}, {"CODE", "MASTER"},
        {"2023", "0611"}, {"ALGORITHM", "CONTEST"}
    };

    cin>>s;
    cout<<table[s]<<'\n';

    return 0;
}