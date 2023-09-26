#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

int get_numbers(int size,vector<int>& nums)
{
    for (int i=0;i<size;i++) {
        int n;
        cin>>n;
        nums.push_back(n);
    }

    return  0;
}

int input(vector<int>& a,vector<int>& b)
{
    int n,m;

    cin>>n>>m;

    get_numbers(n,a);
    get_numbers(m,b);

    return  0;
}

int simulate(const vector<int>& a,
                const vector<int>& b,int cnt[])
{
    string  result;

    for (int i=0;i<a.size();i++) {
        for (int j=0;j<b.size();j++) {
            result += to_string(a[i]*b[j]);
        }
    }

    for (int i=0;i<result.length();i++) {
        cnt[result[i]]++;
    }

    return  0;
}

int print(int cnt[])
{
    for (char c='0';c<='9';c++) {
        cout<<cnt[c]<<(c=='9'?'\n':' ');
    }
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        vector<int> a,b;
        int cnt[0x100] = {0,};

        input(a,b);
        if (a.empty() || b.empty()) break;

        simulate(a,b,cnt);
        print(cnt);
    }

    return  0;
}