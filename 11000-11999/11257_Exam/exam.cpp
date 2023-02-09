#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    3
#define LEAST       30
#define TOTAL_SCORE 55

#define score_at_least(s,t,p)   ((s)*100>=(t)*(p))

const int section_score[MAX_SIZE] = {35,25,40};

bool    pass_exam(int score[],int& sum)
{
    int cnt = 0;
    
    for(int i=0;i<MAX_SIZE;i++)
    {
        if( score_at_least(score[i],section_score[i],LEAST) )
        {
            cnt++;
        }

        sum += score[i];
    }

    return  (cnt==MAX_SIZE&&(sum>=TOTAL_SCORE));
}

void    input(string& num,int score[])
{
    cin>>num;

    for(int i=0;i<MAX_SIZE;i++)
    {
        cin>>score[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int     sum,score[MAX_SIZE];
        string  num;
        bool    pass;

        input(num,score);sum=0;
        pass = pass_exam(score,sum);

        cout<<num<<' '<<sum<<' '<<(pass?"PASS":"FAIL")<<'\n';
    }

    return  0;
}