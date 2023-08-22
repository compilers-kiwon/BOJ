#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (3000+1)

typedef pair<int,int>   Pos;    // first: row, second: col
typedef long long int   int64;

static vector<Pos>  jewel_pos;
static vector<int>  orb_pos_in_row[MAX_SIZE],ingot_pos_in_col[MAX_SIZE];

#define get_num_of_behinds(v,n) \
    (int64)((v).size()-(lower_bound((v).begin(),(v).end(),(n))-(v).begin()))

int input(void)
{
    int H,W;

    cin>>H>>W;

    for (int row=0;row<H;row++)
    {
        string  str;

        cin>>str;

        for (int col=0;col<W;col++) {
            switch (str[col]) {
                case 'J':jewel_pos.push_back({row,col});break;
                case 'O':orb_pos_in_row[row].push_back(col);break;
                case 'I':ingot_pos_in_col[col].push_back(row);break;
                default:/*do nothing*/;break;
            }
        }
    }

    return  0;
}

int64   find_square(void)
{
    int64   ret = 0;

    for (int i=0;i<jewel_pos.size();i++) {
        int row = jewel_pos[i].first;
        int col = jewel_pos[i].second;

        ret += get_num_of_behinds(orb_pos_in_row[row],col)
                *get_num_of_behinds(ingot_pos_in_col[col],row);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<find_square()<<'\n';

    return  0;
}