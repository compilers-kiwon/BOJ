#include    <iostream>

using namespace std;

typedef long long int   int64;

const static int MAX_SIZE = 100000+1;

static int n,m;
static int64 T[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>T[i];

    int64   max_salary,cur_salary;

    cur_salary = 0;

    for (int i=1;i<=m;i++) {
        cur_salary += T[i];
    }

    max_salary = cur_salary;

    for (int i=m+1,j=1;i<=n;i++,j++) {
        cur_salary += T[i]-T[j];
        max_salary = max(max_salary,cur_salary);
    }

    cout<<max_salary<<'\n';
    return  0;
}