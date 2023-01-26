#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    3
#define is_odd(n)   (((n)%2)==1)

int     get_taste(const vector<int>& src)
{
    int ret = 1;

    for(int i=0;i<src.size();i++)
    {
        ret *= src[i];
    }

    return  ret;
}

void    simulate(vector<int>& selected,int ptr,
                const int* src,int& max_taste)
{
    if( ptr == MAX_SIZE )
    {
        if( !selected.empty() )
        {
            int current_taste = get_taste(selected);
            
            if( is_odd(current_taste) != is_odd(max_taste) )
            {
                if( is_odd(current_taste) )
                {
                    max_taste = current_taste;
                }
            }
            else
            {
                max_taste = max(max_taste,current_taste);
            }
        }

        return;
    }

    selected.push_back(src[ptr]);
    simulate(selected,ptr+1,src,max_taste);

    selected.pop_back();
    simulate(selected,ptr+1,src,max_taste);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int src[MAX_SIZE],max_taste;

    for(int i=0;i<MAX_SIZE;i++)
    {
        cin>>src[i];
    }

    vector<int> selected;

    max_taste = 0;
    simulate(selected,0,src,max_taste);

    cout<<max_taste<<'\n';

    return  0;         
}