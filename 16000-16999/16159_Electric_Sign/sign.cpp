#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define NUM_WIDTH   6
#define NUM_HEIGHT  7
#define MAX_NUM     9
#define MAX_NUMBER  10000000000

typedef long long int   int64;

char    numbers[NUM_HEIGHT][NUM_WIDTH*(MAX_NUM+1)+1] =
{
    "000000000000000000000000000000000000000000000000000000011110",
    "001100000100011110011100000100011110010000011110011110010010",
    "010010001100000010000010001100010000010000000010010010010010",
    "010010000100011110000100010100011100011110000100011110011110",
    "010010000100010000000010111110000010010010000100010010000010",
    "001100000100011110011100000100010010011110000100011110000010",
    "000000000000000000000000000000001100000000000000000000000010"
};

char    input[NUM_HEIGHT][NUM_WIDTH*(MAX_NUM+1)+1];

void    read_sign(void)
{
    for(int row=0;row<NUM_HEIGHT;row++)
    {
        cin>>&input[row][0];
    }
}

bool    compare_sign(int input_col,int number_col)
{
    for(int row=0;row<NUM_HEIGHT;row++)
    {
        for(int col=0;col<NUM_WIDTH;col++)
        {
            if( input[row][input_col+col] != numbers[row][number_col+col] )
            {
                return  false;
            }
        }
    }

    return  true;
}

int     get_number(int s_col)
{
    int ret;

    for(int i=0;i<=MAX_NUM;i++)
    {
        if( compare_sign(s_col,i*NUM_WIDTH) == true )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int64   read_numbers(vector<int>& nums)
{
    int64   ret = 0;

    for(int col=0;input[0][col]!='\0';col+=NUM_WIDTH)
    {
        int n = get_number(col);

        ret = ret*10+n;
        nums.push_back(n);
    }

    return  ret;
}

int64   vector2int64(vector<int>& v)
{
    int64   ret = 0;

    for(int i=0;i<v.size();i++)
    {
        ret = ret*10+(int64)v[i];
    }

    return  ret;
}

void    print_number(vector<int>& nums)
{
    string  buffer[NUM_HEIGHT];

    for(int i=0;i<nums.size();i++)
    {
        for(int row=0;row<NUM_HEIGHT;row++)
        {
            for(int col=0;col<NUM_WIDTH;col++)
            {
                buffer[row].push_back(numbers[row][nums[i]*NUM_WIDTH+col]);
            }
        }
    }

    for(int row=0;row<NUM_HEIGHT;row++)
    {
        cout<<buffer[row]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64       input_number;
    vector<int> digits;

    read_sign();
    input_number = read_numbers(digits);

    sort(digits.begin(),digits.end());

    int64       next_number = MAX_NUMBER;
    vector<int> next_digits;

    do{
        int64   current_number;

        current_number = vector2int64(digits);

        if( input_number<current_number && current_number<next_number )
        {
            next_number = current_number;
            next_digits = digits;
        }
    }while(next_permutation(digits.begin(),digits.end()));

    if( next_number == MAX_NUMBER )
    {
        cout<<"The End\n";
    }
    else
    {
        print_number(next_digits);
    }

    return  0;
}