#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

#define MAX_ROW 3

const string keboard[MAX_ROW] = 
    {"qwertyuiop","asdfghjkl","zxcvbnm"};

const string left_hand = "qwertasdfgzxcv";
const string right_hand = "yuiophjklbnm";

typedef pair<int,int>   Pos;

#define use_left_hand(c) \
    (left_hand.find((c))!=string::npos)

#define get_distance(p1,p2) \
    (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

Pos get_pos(char c)
{
    Pos ret;

    for(int row=0;row<MAX_ROW;row++)
    {
        size_t  col = keboard[row].find(c);

        if( col != string::npos )
        {
            ret = make_pair(row,(int)col);
            break;
        }
    }

    return  ret;
}

int simulate(Pos left_pos,Pos right_pos,
                    const string& input_str)
{
    int ret = input_str.length();

    for(int i=0;i<input_str.length();i++)
    {
        Pos current_pos = get_pos(input_str[i]);

        if( left_hand.find(input_str[i]) != string::npos )
        {
            ret += get_distance(left_pos,current_pos);
            left_pos = current_pos;
        }
        else
        {
            ret += get_distance(right_pos,current_pos);
            right_pos = current_pos;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char    S_L,S_R;
    string  S;

    cin>>S_L>>S_R>>S;
    cout<<simulate(get_pos(S_L),get_pos(S_R),S)<<'\n';

    return  0;
}