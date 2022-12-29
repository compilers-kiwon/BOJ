#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    100
#define INF         0x7FFFFFFF

int         N,num_of_votes,score[MAX_SIZE+1];
int         displayed_time[MAX_SIZE+1],t;
set<int>    displayed;

#define vote(s)     (score[(s)]++)
#define display(s)  {displayed.insert((s));displayed_time[(s)]=t++;}

void    remove_one_of_displayed(void)
{
    int s,min_score;

    min_score = INF;

    for(set<int>::iterator it=displayed.begin();it!=displayed.end();it++)
    {
        int current_cadidate = *it;

        if( (score[current_cadidate]<min_score) ||
                (score[current_cadidate]==min_score &&
                    displayed_time[current_cadidate]<displayed_time[s] ))
        {
            s = current_cadidate;
            min_score = score[current_cadidate];
        }
    }

    score[s] = 0;
    displayed.erase(s);
    
}

void    simulate(int selected)
{
    vote(selected);

    if( displayed.find(selected) != displayed.end() )
    {
        return;
    }

    if( displayed.size() < N )
    {
        display(selected);
        return;
    }

    remove_one_of_displayed();
    display(selected);
}

void    print_displayed(void)
{
    for(set<int>::iterator it=displayed.begin();it!=displayed.end();it++)
    {
        cout<<*it<<' ';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>num_of_votes;

    for(int i=1;i<=num_of_votes;i++)
    {
        int v;

        cin>>v;
        simulate(v);
    }

    print_displayed();cout<<'\n';

    return  0;
}