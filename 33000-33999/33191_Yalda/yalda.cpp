#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_ITEMS (3)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int b, price[NUM_OF_ITEMS];
    string s[NUM_OF_ITEMS] = {"Watermelon", "Pomegranates", "Nuts"};
    string ans = "Nothing";

    cin>>b;

    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        cin>>price[i];
    }

    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        if (price[i] <= b) {
            ans = s[i];
            break;
        }
    }

    cout<<ans<<'\n';

    return 0;
}