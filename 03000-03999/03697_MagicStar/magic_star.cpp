#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_ROW 5
#define MAX_COL 9
#define MAX_NUM 12

#define MAGIC_NUMBER    26

char    grid[MAX_ROW+1][MAX_COL+1];

#define GET_NUMBER(c)   ((int)((c)-'A')+1)

#define get_sum(arr,a,b,c,d) \
    ((arr)[(a)]+(arr)[(b)]+(arr)[(c)]+(arr)[(d)])

void    input(void)
{
    for(int row=1;row<=MAX_ROW;row++)
    {
        cin>>&grid[row][1];
    }
}

void    parse_grid(vector<int>& unused_num,
                    vector<int>& unused_pos,int* arr)
{
    int     pos = -1;
    bool    used[MAX_NUM+1];

    fill(&used[1],&used[MAX_NUM+1],false);

    for(int row=1;row<=MAX_ROW;row++)
    {
        for(int col=1;col<=MAX_COL;col++)
        {
            if( grid[row][col] == '.' )
            {
                continue;
            }

            pos++;

            if( grid[row][col] == 'x' )
            {
                unused_pos.push_back(pos);
            }
            else
            {
                arr[pos] = GET_NUMBER(grid[row][col]);
                used[GET_NUMBER(grid[row][col])] = true;
            }
        }
    }

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( used[i] == false )
        {
            unused_num.push_back(i);
        }
    }
}

bool    is_magic_star(int* arr)
{
    return  (get_sum(arr,0,2,5,7)==MAGIC_NUMBER
                && get_sum(arr,1,2,3,4)==MAGIC_NUMBER
                && get_sum(arr,7,8,9,10)==MAGIC_NUMBER
                && get_sum(arr,0,3,6,10)==MAGIC_NUMBER
                && get_sum(arr,1,5,8,11)==MAGIC_NUMBER
                && get_sum(arr,4,6,9,11)==MAGIC_NUMBER);
}

void    complete_grid(vector<int>& num)
{
    int ptr = 0;
    const string str = " ABCDEFGHIJKL";

    for(int row=1;row<=MAX_ROW;row++)
    {
        for(int col=1;col<=MAX_COL;col++)
        {
            if( grid[row][col] == 'x' )
            {
                grid[row][col] = str[num[ptr]];
                ptr++;
            }
        }
    }
}

void    simulate(vector<int>& unused_num,
                    vector<int>& unused_pos,int* arr)
{
    do{
        for(int i=0;i<unused_num.size();i++)
        {
            arr[unused_pos[i]] = unused_num[i];
        }

        if( is_magic_star(arr) == true )
        {
            complete_grid(unused_num);
            break;
        }
    }while(next_permutation(unused_num.begin(),unused_num.end()));
}

void    print_grid(void)
{
    for(int row=1;row<=MAX_ROW;row++)
    {
        cout<<&grid[row][1]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int arr[MAX_NUM];
    vector<int> unused_num,unused_pos;

    input();
    parse_grid(unused_num,unused_pos,arr);

    simulate(unused_num,unused_pos,arr);
    print_grid();

    return  0;
}