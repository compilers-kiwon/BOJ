#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)

int         N,M,X;
vector<int> ahead[MAX_SIZE];
bool        visited[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;
        ahead[B].push_back(A);
    }

    cin>>X;
}

int     get_num_of_completed_jobs(int job)
{
    int             ret = 1;
    vector<int>&    j = ahead[job];

    for(int i=0;i<j.size();i++)
    {
        int&    job_idx = j[i];

        if( visited[job_idx] == false )
        {
            visited[job_idx] = true;
            ret += get_num_of_completed_jobs(job_idx);
        }
    }
    
    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_num_of_completed_jobs(X)-1<<'\n';

    return  0;
}