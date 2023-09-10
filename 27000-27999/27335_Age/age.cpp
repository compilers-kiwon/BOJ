#include    <iostream>
#include    <vector>
#include    <set>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (250000+1)

static int  N,A[MAX_SIZE];
static vector<int>  sorted;

#define get_diff(a1,a2) (abs((a1)-(a2)))

int input(void)
{
    set<int> ages;
    set<int>::iterator it;

    cin>>N;

    for (int i=1;i<=N;i++) {
        cin>>A[i];
        ages.insert(A[i]);
    }

    for (it=ages.begin();it!=ages.end();it++) {
        sorted.push_back(*it);
    }

    return  0;
}

int get_min_age(int my_age)
{
    for (int i=0;i<sorted.size();i++) {
        if (sorted[i] != my_age) {
            return  sorted[i]; 
        }
    }

    return  my_age;
}

int get_max_age(int my_age)
{
    for (int i=sorted.size()-1;i>=0;i--) {
        if (sorted[i] != my_age) {
            return  sorted[i]; 
        }
    }

    return  my_age;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int i=1;i<=N;i++) {
        int min_age = get_min_age(A[i]);
        int max_age = get_max_age(A[i]);

        cout<<max(get_diff(A[i],min_age),
                    get_diff(A[i],max_age))<<'\n';
    }

    return  0;
}