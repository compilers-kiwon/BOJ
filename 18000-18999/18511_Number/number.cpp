#include    <iostream>
#include    <string>

using namespace std;

static string N,K;

const static string NONE = "0";

void build_max_number(string& cur,int len,string& max_num)
{
    if (cur.length() == len) {
        if (stoi(cur)<=stoi(N)
                && stoi(cur)>stoi(max_num)) {
            max_num = cur;
        }
        return;
    }

    for (int i=0;i<K.length();i++) {
        cur.push_back(K[i]);
        build_max_number(cur,len,max_num);
        cur.pop_back();
    }
}

void input(void)
{
    int size;

    cin>>N>>size;
    for (int i=1;i<=size;i++) {
        char n;
        cin>>n;
        K.push_back(n);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string max_num;

    input();

    for (int i=N.length();i>=1;i--) {
        string  cur;

        max_num = NONE;
        build_max_number(cur,i,max_num);
        if (max_num != NONE) break;
    }

    cout<<max_num<<'\n';
    return  0;
}