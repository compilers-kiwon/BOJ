#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

static vector<int> used;
static int  cnt_of_W[0x100],cnt_of_S[0x100];
static string   W,S;

void input(void)
{
    int n1,n2;

    cin>>n1>>n2>>W>>S;

    for (int i=0;i<W.length();i++) {
        if (++cnt_of_W[W[i]] == 1) used.push_back(W[i]);
    }
}

bool compare_counts(void) {
    for (int i=0;i<used.size();i++) {
        if (cnt_of_W[used[i]] != cnt_of_S[used[i]]) {
            return  false;
        }
    }

    return  true;
}

static inline void get_one_letter(int arr[],int letter) {
    ++arr[letter];
}

static inline void remove_one_letter(int arr[],int letter) {
    --arr[letter];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;

    input();

    for (int i=0;i<W.length()-1;i++) {
        cnt_of_S[S[i]]++;
    }

    for (int h=0,t=W.length()-1;t<S.length();h++,t++) {
        get_one_letter(cnt_of_S,S[t]);
        if (compare_counts()) cnt++;
        remove_one_letter(cnt_of_S,S[h]);
    }

    cout<<cnt<<'\n';
    return  0;
}