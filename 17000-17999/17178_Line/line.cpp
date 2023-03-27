#include    <iostream>
#include    <string>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define WIDTH   5

typedef pair<char,int>  Ticket;

static int  N;
static queue<Ticket>    q;
static vector<Ticket>   waiting;
static vector<Ticket>   sorted;

#define TRUE    1
#define FALSE   0

int input(void)
{
    cin>>N;

    for(int i=1;i<=N*WIDTH;i++)
    {
        string  str;
        Ticket  t;

        cin>>str;
        sscanf(str.c_str(),"%c-%d",&t.first,&t.second);
        
        q.push(t);
        sorted.push_back(t);
    }

    sort(sorted.begin(),sorted.end());
    return  0;
}

int simulate(void)
{
    for(int i=0;i<sorted.size();)
    {
        Ticket& expected = sorted[i];

        if( !q.empty() && q.front()==expected )
        {
            q.pop();i++;
            continue;
        }

        if( !waiting.empty() && waiting.back()==expected )
        {
            waiting.pop_back();i++;
            continue;
        }

        if( !q.empty() )
        {
            waiting.push_back(q.front());
            q.pop();
            continue;
        }

        return  FALSE;
    }

    return  TRUE;
}

int main(void)
{
    input();
    cout<<((simulate()==TRUE)?"GOOD":"BAD")<<'\n';

    return  0;
}