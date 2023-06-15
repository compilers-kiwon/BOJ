#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (3000+1)
#define NONE        -1

#define TRUE    1
#define FALSE   0

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

static int  N,grid[MAX_SIZE][MAX_SIZE];
static int  sum_vert[MAX_SIZE][MAX_SIZE];
static int  sum_hori[MAX_SIZE][MAX_SIZE];
static int  plant[MAX_DIR];

const static string str = "UDLR";
const static int offset[MAX_DIR] = {-1,1,-1,1};

#define grow(dir)           (plant[(dir)]+offset[(dir)])
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            int&    g = grid[row][col];
            
            cin>>g;

            sum_hori[row][col] =
                sum_hori[row][col-1]+g;
            sum_vert[row][col] =
                sum_vert[row-1][col]+g;
        }
    }

    return  0;
}

int init_plant(void)
{
    plant[UP] = plant[LEFT] = N/2;
    plant[DOWN] = plant[RIGHT] = N/2+1;

    return  0;
}

int get_new_nutrient(int d)
{
    int ret,row,col;

    switch(d)
    {
        case    UP:
        case    DOWN:
            row = grow(d);
            ret = sum_hori[row][plant[RIGHT]]
                    -sum_hori[row][plant[LEFT]-1];
            break;
        case    LEFT:
        case    RIGHT:
            col = grow(d);
            ret = sum_vert[plant[DOWN]][col]
                    -sum_vert[plant[UP]-1][col];
            break;
        default:
            // do nothing
            break;
    }

    return  ret;
}

int get_dir_to_grow(void)
{
    int ret = NONE;
    int max_nutrient = 0;

    for(int d=0;d<MAX_DIR;d++)
    {
        int new_nu;

        if( !IN_RANGE(1,grow(d),N) )
        {
            continue;
        }

        if( (new_nu=get_new_nutrient(d)) > max_nutrient )
        {
            ret = d;
            max_nutrient = new_nu;
        }
    }

    return  ret;
}

int simulate(string& result)
{
    int ret = 0;

    for(;;)
    {
        int d = get_dir_to_grow();

        if( d == NONE )
        {
            break;
        }

        result.push_back(str[d]);
        ret += get_new_nutrient(d);
        plant[d] = grow(d);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  dir_to_grow;

    input();
    init_plant();

    cout<<simulate(dir_to_grow)<<'\n';
    cout<<dir_to_grow<<'\n';

    return  0;
}