#include    <iostream>
#include    <vector>

using namespace std;

#define ELECTION_YEAR   2007
#define ELECTION_MONTH  2
#define ELECTION_DAY    27
#define VOTING_AGE      18

typedef struct{int y,m,d;} Birthday;

#define return_if_not_equal(a,b) \
    {if((a)<(b))return true;if((a)>(b))return false;}

int input(vector<Birthday>& b)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        Birthday    in;

        cin>>in.y>>in.m>>in.d;
        b.push_back(in);
    }

    return  0;
}

bool    is_eligible_to_vote(const Birthday& b)
{
    return_if_not_equal(b.y+VOTING_AGE,ELECTION_YEAR);
    return_if_not_equal(b.m,ELECTION_MONTH);
    return_if_not_equal(b.d,ELECTION_DAY);
    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Birthday>    b;

    input(b);

    for(int i=0;i<b.size();i++)
    {
        cout<<(is_eligible_to_vote(b[i])?"Yes":"No")<<'\n';
    }

    return  0;
}