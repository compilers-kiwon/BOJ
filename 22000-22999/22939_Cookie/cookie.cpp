#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <string>
#include    <cmath>

using namespace std;

typedef pair<int,int>   Pos;    // first: row, second:col

const string task = "JCBW";
static vector<Pos>  p[0x100];

#define INF             0x7FFFFFFF
#define sort_pos(pos)   (sort((pos).begin(),(pos).end()))

#define get_distance(p1,p2) \
    (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

string  get_task_name(char c)
{
    string  ret;

    switch(c) {
        case 'J':ret="Assassin";break;
        case 'C':ret="Healer";break;
        case 'B':ret="Mage";break;
        case 'W':ret="Tanker";break;
        default:/*do nothing*/;break;
    }

    return  ret;
}

int input(void)
{
    int N;

    cin>>N;

    for (int row=0;row<N;row++) {
        string  s;

        cin>>s;

        for (int col=0;col<N;col++) {
            if (s[col] == 'X') continue;
            p[s[col]].push_back({row,col});
        }
    }

    for (int i=0;i<task.length();i++) sort_pos(p[task[i]]);
    return  0;
}

int get_min_distance(char c)
{
    int ret = INF;
    vector<Pos>& cur_topping = p[c];

    do{
        int cur_distance = 0;
        Pos cur_pos = p['H'].front();

        for (int i=0;i<cur_topping.size();i++) {
            cur_distance += get_distance(cur_pos,cur_topping[i]);
            cur_pos = cur_topping[i]; 
        }

        cur_distance += get_distance(cur_pos,p['#'].front());
        ret = min(ret,cur_distance);
    }while(next_permutation(cur_topping.begin(),cur_topping.end()));

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<pair<int,string>> task_list;

    input();

    for (int i=0;i<task.length();i++) {
        char    cur = task[i];
        task_list.push_back({
            get_min_distance(cur),get_task_name(cur)});
    }

    sort(task_list.begin(),task_list.end());
    cout<<task_list.front().second<<'\n';

    return  0;
}