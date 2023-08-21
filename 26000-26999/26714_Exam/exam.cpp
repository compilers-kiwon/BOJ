#include    <iostream>
#include    <string>

using namespace std;

#define SOLVED      'T'
#define UNSOLVED    'N'

int get_score(const string& str,int size_of_group)
{
    int ret = 0;

    for (int i=0;i<str.length();i+=size_of_group) {
        bool    solved = true;

        for (int j=0;j<size_of_group;j++) {
            if (str[i+j] != SOLVED) {
                solved = false;
                break;
            }
        }
        
        ret += (solved?1:0);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string str;

    cin>>n>>str;
    cout<<get_score(str,n/10)<<'\n';

    return  0;
}