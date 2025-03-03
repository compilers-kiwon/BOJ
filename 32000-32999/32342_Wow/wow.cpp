#include <iostream>
#include <string>

using namespace std;

int count_sub_str(const string& super, const string& sub) {
    int ret = 0;

    for (size_t pos = 0; pos <= super.length() - sub.length(); ret++) {
        size_t result = super.find(sub, pos);

        if (result == string::npos) {
            break;
        } else {
            pos = result + 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;
    const string sub = "WOW";

    cin>>Q;

    for (int i = 1; i <= Q; i++) {
        string S;
        cin>>S;
        cout<<count_sub_str(S, sub)<<'\n';
    }

    return 0;
}