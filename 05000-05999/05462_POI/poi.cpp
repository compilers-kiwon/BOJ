#include    <iostream>

using namespace std;

#define MAX_SIZE    (2000+1)

static struct{int score,solved,id;} participant[MAX_SIZE];
static int  N,T,P,scored[MAX_SIZE],solved_list[MAX_SIZE][MAX_SIZE];

int input(void)
{
    cin>>N>>T>>P;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=T;j++)
        {
            cin>>solved_list[i][j];
            scored[j] += (solved_list[i][j])?0:1;
        }

        participant[i].id = i;
    }

    return  0;
}

int get_score(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=T;j++)
        {
            participant[i].solved += solved_list[i][j];
            participant[i].score += scored[j]*solved_list[i][j];
        }
    }

    return  0;
}

int get_rank(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        if( participant[i].score > participant[P].score )
        {
            ret++;
        }
    }

    for(int i=1;i<=N;i++)
    {
        if( participant[i].score==participant[P].score 
                && participant[i].solved>participant[P].solved )
        {
            ret++;
        }
    }

    for(int i=1;i<=N;i++)
    {
        if( participant[i].score==participant[P].score 
                && participant[i].solved==participant[P].solved 
                && participant[i].id<participant[P].id )
        {
            ret++;
        }
    }
    return  ret+1;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_score();

    cout<<participant[P].score<<' '<<get_rank()<<'\n';

    return  0;
}