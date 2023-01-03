#include    <iostream>
#include    <stack>

using namespace std;

#define MAX_SIZE            (1000+1)
#define MAX_NUM_OF_PAPERS   (100+1)

typedef struct{int s_row,e_row,s_col,e_col;} State;

int     visible_size[MAX_NUM_OF_PAPERS];
bool    visited[MAX_SIZE][MAX_SIZE];
State   grid[MAX_SIZE][MAX_SIZE];

void    input(stack<State>& st,int& num_of_papers)
{
    cin>>num_of_papers;

    for(int i=1;i<=num_of_papers;i++)
    {
        int     row,col,width,height;
        State   s;

        cin>>col>>row>>width>>height;

        s.s_row = row;
        s.s_col = col;
        s.e_row = row+height-1;
        s.e_col = col+width-1;

        st.push(s);
    }
}

void    place_paper(stack<State>& st,
                        const int& num_of_papers)
{
    for(int idx=num_of_papers;!st.empty();idx--,st.pop())
    {
        int     current_size = 0;
        State   s = st.top();

        for(int row=s.s_row;row<=s.e_row;row++)
        {
            for(int col=s.s_col;col<=s.e_col;col++)
            {
                if( visited[row][col] == false )
                {
                    visited[row][col] = true;
                    grid[row][col] = s;
                    current_size++;
                }
                else
                {
                    col = grid[row][col].e_col;
                }
            }
        }

        visible_size[idx] = current_size;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N;
    stack<State>    st;

    input(st,N);
    place_paper(st,N);

    for(int i=1;i<=N;i++)
    {
        cout<<visible_size[i]<<'\n';
    }

    return  0;
}