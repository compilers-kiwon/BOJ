#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const string favorite = "SciComLove";
    string in;
    int cnt = 0;

    cin>>in;

    for (size_t i = 0; i < in.length(); i++) {
        cnt += (favorite[i]!=in[i])?1:0;
    }

    cout<<cnt<<'\n';

    return 0;
}