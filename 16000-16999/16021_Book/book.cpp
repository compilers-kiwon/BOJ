#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10000+1)
#define NOT_VISITED 0
#define INF         0x7FFFFFFF
#define FIRST_PAGE  1

int         N,visited[MAX_SIZE];
vector<int> next_page[MAX_SIZE];

#define is_last_page(n) (next_page[(n)].empty())

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int M;

        cin>>M;

        for(int j=1;j<=M;j++)
        {
            int p;

            cin>>p;
            next_page[i].push_back(p);
        }
    }
}

int     read_book(int& num_of_visited_pages)
{
    int         ret;
    queue<int>  page_q;

    visited[FIRST_PAGE] = 1;
    page_q.push(FIRST_PAGE);

    for(ret=INF,num_of_visited_pages=1;!page_q.empty();page_q.pop())
    {
        int current_page = page_q.front();

        if( is_last_page(current_page) == true )
        {
            ret = min(ret,visited[current_page]);
            continue;
        }

        for(int i=0;i<next_page[current_page].size();i++)
        {
            const int&    adj_page = next_page[current_page][i];

            if( visited[adj_page] != NOT_VISITED )
            {
                continue;
            }

            page_q.push(adj_page);
            num_of_visited_pages++;
            visited[adj_page] = visited[current_page]+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int min_path,num_of_visited_pages;

    min_path = read_book(num_of_visited_pages);

    if( num_of_visited_pages != N )
    {
        cout<<"N\n"<<min_path<<"\n";
    }
    else
    {
        cout<<"Y\n"<<min_path<<"\n";
    }

    return  0;
}