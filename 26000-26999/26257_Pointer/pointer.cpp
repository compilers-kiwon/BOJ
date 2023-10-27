#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

const static int MAX_SIZE = 200000+1;

static int N,M,Q;
static int num_of_pointers_to_object[MAX_SIZE];
static int pointer[MAX_SIZE];

static inline void assign_pointer(int x,int y) {
    num_of_pointers_to_object[pointer[x]]--;
    pointer[x] = pointer[y];
    num_of_pointers_to_object[pointer[x]]++;
}

static inline void reset_pointer(int x) {
    num_of_pointers_to_object[pointer[x]]--;
    pointer[x] = 0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>Q;

    for (int i=1;i<=M;i++) {
        int& e = pointer[i];
        cin>>e;
        num_of_pointers_to_object[e]++;
    }

    for (int i=1;i<=Q;i++) {
        string  s;
        int     x,y;

        cin>>s;

        if (s == "assign") {
            cin>>x>>y;
            assign_pointer(x,y);
        } else if (s == "swap") {
            cin>>x>>y;
            swap(pointer[x],pointer[y]);
        } else {
            cin>>x;
            reset_pointer(x);
        }
    }

    vector<int> available;

    for (int i=1;i<=N;i++) {
        if (num_of_pointers_to_object[i] > 0) {
            available.push_back(i);
        }
    }

    cout<<available.size()<<'\n';

    for (int i=0;i<available.size();i++) {
        cout<<available[i]<<'\n';
    }

    return  0;
}