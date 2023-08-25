#include    <iostream>

using namespace std;

#define MAX_DIFFICULTY  (10)
#define NONE            (0)

int get_total_beauty(int beauty[])
{
    int ret = 0;

    for (int d=1;d<=MAX_DIFFICULTY;d++) {
        if (beauty[d] == NONE) return NONE;
        ret += beauty[d];
    }

    return  ret;
}

int input(int beauty[])
{
    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        int b,d;

        cin>>b>>d;
        beauty[d] = max(beauty[d],b);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for (int i=1;i<=t;i++) {
        int total_beauty;
        int beauty[MAX_DIFFICULTY+1] = {NONE,};

        input(beauty);
        
        if ((total_beauty=get_total_beauty(beauty)) == NONE) cout<<"MOREPROBLEMS\n";
        else cout<<total_beauty<<'\n';
    }

    return  0;
}