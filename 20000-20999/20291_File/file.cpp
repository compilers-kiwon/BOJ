#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static inline string get_ext(const string& file_name) {
    int delimiter_pos = file_name.find('.');
    return  file_name.substr(delimiter_pos+1);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    map<string,int> cnt;

    cin>>N;

    for (int i=1;i<=N;i++) {
        string  str;
        cin>>str;
        cnt[get_ext(str)]++;
    }

    map<string,int>::iterator it;

    for (it=cnt.begin();it!=cnt.end();it++) {
        cout<<it->first<<' '<<it->second<<'\n';
    }

    return  0;
}