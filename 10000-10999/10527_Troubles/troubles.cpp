#include    <iostream>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

#define INF 0x7FFFFFFF

enum {
    DOM = 0,
    KATTIS = 1,
    MAX_NUM_OF_JUDGES = 2
};

static map<string,int>  judge[MAX_NUM_OF_JUDGES];
static set<string>      judge_result;

int get_result(int who,int size)
{
    for(int i=1;i<=size;i++)
    {
        string  str;

        cin>>str;

        judge[who][str]++;
        judge_result.insert(str);
    }

    return  0;
}

int input(void)
{
    int n;

    cin>>n;

    for(int i=DOM;i<MAX_NUM_OF_JUDGES;i++)
    {
        get_result(i,n);
    }

    return  0;
}

int get_min_num_of_judge(string j)
{
    int ret = INF;

    for(int i=DOM;i<MAX_NUM_OF_JUDGES;i++)
    {
        ret = min(ret,judge[i][j]);
    }

    return  ret;
}

int compare_result(void)
{
    int ret = 0;
    set<string>::iterator   it;

    for(it=judge_result.begin();it!=judge_result.end();it++)
    {
        ret += get_min_num_of_judge(*it);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<compare_result()<<'\n';

    return  0;
}