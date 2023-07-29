#include    <iostream>
#include    <string>

using namespace std;

#define NONE    -1
#define LEFT    0
#define RIGHT   1
#define MAX_DIR 2

const string dir_chrs[MAX_DIR] = {
    "qwertasdfgzxcvb","yuiophjklnm"
};

#define get_dir(c)  ((dir_chrs[LEFT].find((c))!=string::npos)?LEFT:RIGHT)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cur_dir;
    string  str;

    cin>>str;
    cur_dir = NONE;

    for (int i=0;i<str.length();i++)
    {
        int next_dir = get_dir(str[i]);

        if (cur_dir == next_dir) {
            cout<<"no\n";
            return  0;
        }

        cur_dir = next_dir;
    }

    cout<<"yes\n";
    return  0;
}