#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

int input(vector<string>& p)
{
    int ret = 0;

    for (;;) {
        string  s;

        getline(cin,s);
        if (s.empty()) break;

        p.push_back(s);
        ret = max(ret,(int)s.length());
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  paragraph;
    int max_len = input(paragraph);
    int sum_of_panalties = 0;
    
    for (int i=0;i<paragraph.size()-1;i++) {
        int p = max_len-paragraph[i].length();
        sum_of_panalties += p*p;
    }

    cout<<sum_of_panalties<<'\n';
    return  0;
}