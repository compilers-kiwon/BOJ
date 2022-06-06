#include    <iostream>
#include    <vector>

using namespace std;

#define NUM_OF_GNOMES   3
#define LOWER_LEN       0
#define UPPER_LEN       100

bool    is_descending(const vector<int>& beard)
{
    int     prev = UPPER_LEN;
    bool    ret = true;

    for(int i=0;i<beard.size();i++)
    {
        int current = beard[i];

        if( prev < current )
        {
            ret = false;
            break;
        }

        prev = current;
    }

    return  ret;
}

bool    is_ascending(const vector<int>& beard)
{
    int     prev = LOWER_LEN;
    bool    ret = true;

    for(int i=0;i<beard.size();i++)
    {
        int current = beard[i];

        if( prev > current )
        {
            ret = false;
            break;
        }

        prev = current;
    }

    return  ret;
}

bool    is_ordered(const vector<int>& beard)
{
    return  (is_ascending(beard)||is_descending(beard));
}

void    input(vector<int>& beard)
{
    for(int i=1;i<=NUM_OF_GNOMES;i++)
    {
        int len;

        cin>>len;
        beard.push_back(len);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    cout<<"Gnomes:\n";

    for(int i=1;i<=N;i++)
    {
        vector<int> beard;

        input(beard);

        if( is_ordered(beard) == true )
        {
            cout<<"Ordered\n";
        }
        else
        {
            cout<<"Unordered\n";
        }
    }

    return  0;
}