#include <iostream>
#include <string>

using namespace std;

int get_score(const string& problem) {
    const int UPPER_POINTS = 4;
    const int SPACE_POINTS = 1;
    const int LOWER_NUMBER_POINTS = 2;

    int ret = 0;

    for (int i = 0; i < problem.length(); i++) {
        const char& c = problem[i];
        
        ret += (isupper(c))?UPPER_POINTS:
                (c==' ')?SPACE_POINTS:LOWER_NUMBER_POINTS;
    }

    return ret;
}

int main(void) {
    int J, N, cnt;

    cnt = 0;
    cin>>J>>N;
    getchar();

    for (int i = 1; i <= N; i++) {
        string str;
        getline(cin, str);
        cnt += (get_score(str)<=J)?1:0;
    }

    cout<<cnt<<'\n';

    return 0;
}