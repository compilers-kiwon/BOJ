#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define MAX_NUM_OF_FILES    (100+1)
#define END_OF_FILE         (-1)

static int  N;
static vector<int>  file[MAX_NUM_OF_FILES];

int input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        for (;;) {
            int n;
            cin>>n;

            if (n == END_OF_FILE) break;
            file[i].push_back(n);
        }
    }

    return  0;
}

int get_sub_file(int file_idx,int sub_size,
                        vector<int>& sub_file)
{
    const vector<int>&  f = file[file_idx];

    for (int i=0;i<min(sub_size,(int)f.size());i++) {
        sub_file.push_back(f[i]);
    }

    return  0;
}

int get_num_of_files(int size)
{
    set<vector<int>>    s;

    for (int i=1;i<=N;i++) {
        vector<int> sub;

        get_sub_file(i,size,sub);
        s.insert(sub);
    }

    return  s.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int K=1;;K++) {
        if (get_num_of_files(K) == N) {
            cout<<K<<'\n';
            break;
        }
    }

    return  0;
}