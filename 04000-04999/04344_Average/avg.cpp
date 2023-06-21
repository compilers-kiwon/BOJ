#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N,score[MAX_SIZE];

int input(void)
{
    int ret = 0;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        scanf("%d",&score[i]);
        ret += score[i];
    }

    return  ret;
}

int get_num_of_sudents_to_exceed_avg(int sum)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += (score[i]*N>sum)?1:0;
    }

    return  ret;
}

int main(void)
{
    int C;

    scanf("%d",&C);

    for(int i=1;i<=C;i++)
    {
        int sum,result,num_of_good_students;
        
        sum = input();
        num_of_good_students = get_num_of_sudents_to_exceed_avg(sum);

        result = ((num_of_good_students*1000000)/N+5)/10;
        printf("%d.%03d%%\n",result/1000,result%1000);
    }

    return  0;
}