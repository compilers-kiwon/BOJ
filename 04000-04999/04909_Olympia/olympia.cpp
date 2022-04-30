#include    <iostream>

using namespace std;

#define NUM_OF_SCORES   6

int get_score(int& max_score,int& min_score)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_SCORES;i++)
    {
        int score;

        scanf("%d",&score);
        ret += score;

        max_score = max(max_score,score);
        min_score = min(min_score,score);
    }

    return  ret;
}

int main(void)
{
    for(;;)
    {
        int max_score = 0;
        int min_score = 0x7FFFFFFF;
        int sum = get_score(max_score,min_score);

        if( sum == 0 )
        {
            break;
        }

        sum -= max_score+min_score;

        if( sum/(NUM_OF_SCORES-2)*(NUM_OF_SCORES-2) == sum )
        {
            printf("%d\n",sum/(NUM_OF_SCORES-2));
        }
        else
        {
            printf("%g\n",(float)sum/(float)(NUM_OF_SCORES-2));
        }
    }

    return  0;
}