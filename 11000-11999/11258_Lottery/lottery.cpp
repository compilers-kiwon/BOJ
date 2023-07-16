#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define NUM_OF_WINS 6

static struct{
    int     pos,prize;
    string  number;
} lottery[NUM_OF_WINS];

static vector<string>   numbers;

#define get_info(idx,s) \
    {lottery[(idx)].pos=(s);cin>>lottery[(idx)].number>>lottery[(idx)].prize;}

const int   start_pos[NUM_OF_WINS] = {0,0,0,3,3,4};

int input(void)
{
    for(int i=0;i<NUM_OF_WINS;i++)
    {
        get_info(i,start_pos[i]);
    }
    
    for(;;)
    {
        string  s;

        cin>>s;
        if (s=="-1") break;

        numbers.push_back(s);
    }

    return  0;
}

int calculate_prize(const string& num)
{
    int ret = 0;

    for(int i=0;i<NUM_OF_WINS;i++)
    {
        int&    start_pos = lottery[i].pos;
        string& n = lottery[i].number;

        if( n == num.substr(start_pos,n.length()) )
        {
            ret += lottery[i].prize;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<numbers.size();i++)
    {
        cout<<calculate_prize(numbers[i])<<'\n';
    }

    return  0;
}