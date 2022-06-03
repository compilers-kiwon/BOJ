#include    <iostream>

using namespace std;

#define NUM_OF_CONDITIONS   11
#define MIN_DISTANCE        -1
#define MAX_DISTANCE        0x7FFFFFFF

#define IN_RANGE(MIN,n,MAX) ((MIN)<(n)&&(n)<=(MAX))
#define get_distance(x,y)   ((x)*(x)+(y)*(y))

const struct{int lower,upper,score;} condition_table[NUM_OF_CONDITIONS] =
    {
        {MIN_DISTANCE,10*10,10},{10*10,30*30,9},{30*30,50*50,8},
        {50*50,70*70,7},{70*70,90*90,6},{90*90,110*110,5},
        {110*110,130*130,4},{130*130,150*150,3},{150*150,170*170,2},
        {170*170,190*190,1},{190*190,MAX_DISTANCE,0}
    };

int get_score(int distance)
{
    int ret;

    for(int i=0;i<NUM_OF_CONDITIONS;i++)
    {
        if( IN_RANGE(condition_table[i].lower,distance,condition_table[i].upper) == true )
        {
            ret = condition_table[i].score;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,total_score;

    cin>>N;
    total_score = 0;

    for(int i=1;i<=N;i++)
    {
        int x,y;

        cin>>x>>y;
        total_score += get_score(get_distance(x,y));
    }

    cout<<total_score<<'\n';

    return  0;
}