#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

const static int MBTI_LEN = 4;
const static int DIFF_SIZE = 3;
const static int INF = 0x7FFFFFFF;

static inline int get_diff(const string& s1, const string& s2) {
    int ret = 0;
    for (int i=0;i<MBTI_LEN;i++) ret+=((s1[i]!=s2[i])?1:0);
    return  ret;
}

void input(vector<string>& mbti)
{
    int N;
    map<string,int> cnt;

    cin>>N;

    for (int i=1;i<=N;i++) {
        string  str;
        cin>>str;
        cnt[str]++;
    }

    map<string,int>::iterator   it;

    for (it=cnt.begin();it!=cnt.end();it++) {
        for (int i=1;i<=min(it->second,DIFF_SIZE);i++) {
            mbti.push_back(it->first);
        }
    }
}

int get_min_diff(const vector<string>& mbti)
{
    int ret = INF;

    for (int i=0;i<mbti.size();i++) {
        for (int j=i+1;j<mbti.size();j++) {
            for (int k=j+1;k<mbti.size();k++) {
                const string&   A = mbti[i];
                const string&   B = mbti[j];
                const string&   C = mbti[k];
                int d = get_diff(A,B)+get_diff(B,C)+get_diff(A,C);

                ret = min(ret,d);
                if (ret == 0) return 0; 
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin>>T;T>0;T--) {
        vector<string>  mbti;

        input(mbti);
        cout<<get_min_diff(mbti)<<'\n';
    }

    return  0;
}