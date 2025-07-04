#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, Q;
    unordered_map<string, int> customer_num;
    unordered_map<string, string> customer_name;

    cin>>N>>Q;

    for (int i = 1; i <= N; i++) {
        string s1, s2, initials;
        
        cin>>s1>>s2;

        initials.push_back(s1.front());
        initials.push_back(s2.front());
        
        customer_num[initials]++;
        customer_name[initials] = s1 + " " + s2;
    }

    for (int i = 1; i <= Q; i++) {
        string q;

        cin>>q;

        switch(customer_num[q]) {
            case 0: cout<<"nobody\n";break;
            case 1: cout<<customer_name[q]<<'\n';break;
            default: cout<<"ambiguous\n";break;
        }
    }

    return 0;
}