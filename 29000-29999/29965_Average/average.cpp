#include    <iostream>

using namespace std;

typedef long long int   int64;

const static char TIE = 'V';
const static char MARI = 'M';
const static char JURI = 'J';

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    int64   M_score,M_cnt;
    int64   J_score,J_cnt;

    cin>>N;
    M_score = M_cnt = J_score = J_cnt = 0;

    for (int i=1;i<=N;i++) {
        char    c;
        int64   s;

        cin>>c>>s;
        
        if (c == 'M') {
            M_cnt++,M_score+=s;
        } else {
            J_cnt++,J_score+=s;
        }
    }

    M_score *= max(1LL,J_cnt);
    J_score *= max(1LL,M_cnt);

    cout<<((M_score==J_score)?TIE:
        (M_score>J_score)?MARI:JURI)<<'\n';
    return  0;
}