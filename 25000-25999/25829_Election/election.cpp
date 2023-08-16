#include    <iostream>
#include    <cstring>

using namespace std;

#define CANDIDATE_1         0
#define CANDIDATE_2         1
#define NUM_OF_CANDIDATES   2

#define MAJORITY        0
#define ELECTORAL       1
#define KINDS_OF_VOTES  2

#define TRUE    1
#define FALSE   0

int win(int winner,int loser,int result[][KINDS_OF_VOTES])
{
    for (int i=0;i<KINDS_OF_VOTES;i++) {
        if (!(result[winner][i] > result[loser][i])) {
            return  FALSE;
        }
    }

    return  TRUE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,result[NUM_OF_CANDIDATES][KINDS_OF_VOTES];

    cin>>n;
    memset(result,0,sizeof(result));

    for (int i=1;i<=n;i++) {
        int e,v1,v2;

        cin>>e>>v1>>v2;
        result[(v1>v2)?CANDIDATE_1:CANDIDATE_2][ELECTORAL] += e;

        result[CANDIDATE_1][MAJORITY] += v1;
        result[CANDIDATE_2][MAJORITY] += v2;
    }

    if(win(CANDIDATE_1,CANDIDATE_2,result)) cout<<"1\n";
    else if(win(CANDIDATE_2,CANDIDATE_1,result)) cout<<"2\n";
    else cout<<"0\n";

    return  0;
}