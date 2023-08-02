#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    5
#define CRITERION   127
#define get_idx(c)  ((int)((c)-'A'))

int input(vector<vector<int>>& data)
{
    int N;

    cin>>N;

    for (int i=1;i<=N;i++) {
        vector<int> m;

        for (int j=1;j<=MAX_SIZE;j++) {
            int r;

            cin>>r;
            m.push_back(r);
        }

        data.push_back(m);
    }

    return  0;
}

int read_and_print(const vector<vector<int>>& data)
{
    for (int i=0;i<data.size();i++) {
        string  result;
        const vector<int>&  cur = data[i];

        for (char c='A';c<='E';c++)
            if (cur[get_idx(c)] <= CRITERION) result.push_back(c);

        cout<<(result.length()==1?result:"*")<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;) {
        vector<vector<int>> data;

        input(data);
        if (data.size() == 0) break;
        read_and_print(data);
    }

    return  0;
}