#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

bool    is_correct(const string& str)
{
    if (str.find("BBB")!=string::npos
            || str.find("WWW")!=string::npos) {
        return  false;
    }

    int num_of_blacks,num_of_whites;

    num_of_blacks = num_of_whites = 0;

    for (int i=0;i<str.length();i++) {
        if (str[i] == 'B') num_of_blacks++;
        else num_of_whites++;
    }

    return  (num_of_blacks==num_of_whites);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    vector<string>  grid;

    cin>>n;

    for (int i=0;i<n;i++) {
        string  str;
        cin>>str;
        grid.push_back(str);
    }

    for (int i=0;i<n;i++) {
        if (!is_correct(grid[i])) {
            cout<<"0\n";
            return  0;
        }
    }

    for (int i=0;i<n;i++) {
        string  str;

        for (int row=0;row<n;row++) {
            str.push_back(grid[row][i]);
        }

        if (!is_correct(str)) {
            cout<<"0\n";
            return  0;
        }
    }

    cout<<"1\n";
    return  0;
}