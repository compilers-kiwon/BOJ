#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_NUM_OF_PERSONS  (1000+1)
#define get_score(S,A,T,M)  ((S)*(1.0+1.0/(A))*(1.0+(M)/(T))/4.0)

#define UPPER_POS_AS_PERCENT    15
#define get_upper_pos(size)     (((size)+1)*UPPER_POS_AS_PERCENT/100)

static int      N,P;
static double   yh_score,other_score[MAX_NUM_OF_PERSONS];

bool    is_greater(const double& a,const double& b)
{
    return  a>b;
}

int get_my_score(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        double  S,A,T,M;

        cin>>S>>A>>T>>M;
        yh_score += get_score(S,A,T,M);
    }

    return  0;
}

int read_other_score(void)
{
    cin>>P;

    for(int i=1;i<=P;i++)
    {
        cin>>other_score[i];
    }

    sort(&other_score[1],&other_score[P+1],is_greater);
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    get_my_score();
    read_other_score();

    cout<<fixed;cout.precision(2);
    cout<<"The total score of Younghoon"
        <<(yh_score>other_score[get_upper_pos(P+1)]?" \"The God\"":"")
        <<" is "<<yh_score<<".\n";

    return  0;
}