#include    <iostream>
#include    <string>

using namespace std;

const static int score[] = {0,200,400,600,1000};
const static string judgement[] = {
    "miss","bad","cool","great","perfect"
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int lv;
    string j;

    cin>>lv>>j;

    for (int i=0;;i++) {
        if (j == judgement[i]) {
            cout<<lv*score[i]<<'\n';
            break;
        }
    }

    return  0;
}