#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_SIZE    8

const int score[MAX_SIZE] = {1,2,3,4,5,6,8,10};

typedef pair<string,char>   Player;

#define RED     'R'
#define BLUE    'B'

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<Player>  pq;

    for(int i=0;i<MAX_SIZE;i++)
    {
        Player  p;

        cin>>p.first>>p.second;
        pq.push(p);
    }

    int     red_score,blue_score;
    char    first_place_team;

    red_score = blue_score = 0;
    first_place_team = pq.top().second;

    for(int i=0;i<MAX_SIZE;i++,pq.pop())
    {
        if( pq.top().second == RED )
        {
            red_score += score[i];
        }
        else
        {
            blue_score += score[i];
        }
    }
    
    if( red_score == blue_score )
    {
        cout<<((first_place_team==RED)?
                        "Red":"Blue")<<'\n';
    }
    else
    {
        cout<<((red_score>blue_score)?
                        "Red":"Blue")<<'\n';
    }

    return  0;
}