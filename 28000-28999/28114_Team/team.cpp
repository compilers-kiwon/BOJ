#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_LEN 5

static priority_queue<int>  pq1;
static priority_queue<pair<int,string>> pq2;

#define break_if_empty_string(str)  if((str).empty())break;
#define get_first_letter(pq)        ((pq).top().second.front())

int get_team_name(priority_queue<int>& pq)
{
    int ret = 0;
    
    for(;!pq.empty();pq.pop())
    {
        ret = ret*100+(-pq.top());
    }

    return  ret;
}

string  get_team_name(priority_queue<pair<int,string>>& pq)
{
    string  ret;

    for(;!pq.empty();pq.pop())
    {
        ret.push_back(get_first_letter(pq));
    }

    return  ret;
}

int input(void)
{
    string  str;
    char    name[MAX_LEN+1];
    int     score,num;

    for(;;)
    {
        getline(cin,str);
        break_if_empty_string(str);
        
        sscanf(str.c_str(),"%d %d %s",&score,&num,name);

        pq1.push(-(num%100));
        pq2.push({score,string(name)});
    }

    return  0;
}

int main(void)
{
    input();

    cout<<get_team_name(pq1)<<'\n';
    cout<<get_team_name(pq2)<<'\n';

    return  0;
}