#include    <iostream>

using namespace std;

#define MIN_DIFF_FOR_WIN    2

int simulate(int final_score,int me,int other)
{
    int s1 = max(final_score-me,0);
    int s2 = max(other+MIN_DIFF_FOR_WIN-(me+s1),0);

    return  s1+s2;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for (int i=1;i<=t;i++) {
        int k,x,y;

        cin>>k>>x>>y;
        cout<<min(simulate(k,x,y),simulate(k,y,x))<<'\n';
    }

    return  0;
}