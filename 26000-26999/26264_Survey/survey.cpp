#include <iostream>
#include <string>

using namespace std;

const string BIGDATA = "bigdata";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, b;
    string survey;

    cin >> N >> survey, b = 0;

    for (size_t pos = 0; pos != string::npos;) {
        size_t b_pos = survey.find(BIGDATA, pos);

        if (b_pos != string::npos) {
            pos = b_pos + BIGDATA.length(), b++;
        } else {
            pos = b_pos;
        }
    }

    if ((N - b) > b) {
        cout << "security!\n";
    } else if ((N - b) < b) {
        cout << "bigdata?\n";
    } else {
        cout << "bigdata? security!\n";
    }

    return 0;
}