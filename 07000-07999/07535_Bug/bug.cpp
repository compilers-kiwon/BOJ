#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (2000+1)

#define TBD         -1
#define MALE        0
#define FEMALE      1
#define MAX_GENDER  2

#define determin_opposite_gender(g) (((g)+1)%MAX_GENDER)

int         num_of_bugs,num_of_interactions,gender[MAX_SIZE];
vector<int> interactions[MAX_SIZE];

bool    check_gender(int current)
{
    for(int i=0;i<interactions[current].size();i++)
    {
        int&    adj = interactions[current][i];

        if( gender[current] != gender[adj] )
        {
            if( gender[adj] == TBD )
            {
                gender[adj] = determin_opposite_gender(gender[current]);

                if( check_gender(adj) == false )
                {
                    return  false;
                }
            }
        }
        else
        {
            return  false;
        }
    }

    return  true;
}

void    init_bugs(int num_of_bugs)
{
    for(int i=1;i<=num_of_bugs;i++)
    {
        gender[i] = TBD;
        interactions[i].clear();
    }
}

void    input(void)
{
    cin>>num_of_bugs>>
        num_of_interactions;
    init_bugs(num_of_bugs);

    for(int i=1;i<=num_of_interactions;i++)
    {
        int u,v;

        cin>>u>>v;

        interactions[u].push_back(v);
        interactions[v].push_back(u);
    }
}

bool    simulate(void)
{
    for(int i=1;i<=num_of_bugs;i++)
    {
        if( gender[i] == TBD )
        {
            gender[i] = MALE;

            if( check_gender(i) == false )
            {
                return  false;
            }
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<"Scenario #"<<t<<":\n"<<
            (simulate()?"No suspicious ":"Suspicious ")<<"bugs found!\n\n";
    }

    return  0;
}