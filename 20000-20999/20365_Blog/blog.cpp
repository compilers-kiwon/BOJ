#include    <iostream>
#include    <string>

using namespace std;

const static char BLUE = 'B';
const static char RED = 'R';

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt_of_red,cnt_of_blue;
    string  str;

    cin>>N>>str;
    cnt_of_blue = cnt_of_red = 0;
    str.insert(0," ");

    for (int i=1;i<=N;i++) {
        if (str[i] != str[i-1]) {
            (str[i]==BLUE)?cnt_of_blue++:cnt_of_red++;
        }
    }

    cout<<min(cnt_of_red,cnt_of_blue)+1<<'\n';
    return  0;
}