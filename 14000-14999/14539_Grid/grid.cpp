#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000)

static char grid[MAX_SIZE][MAX_SIZE];

#define get_grid_size(num_of_patterns,size_of_patterns) \
    (((size_of_patterns)+1)*num_of_patterns+1)

#define CROSS_BORDER    '+'
#define VERT_BORDER     '|'
#define HORI_BORDER     '-'
#define EMPTY           '*'

int print_grid(int row_size)
{
    for (int row=0;row<row_size;row++) {
        cout<<&grid[row][0]<<'\n';
    }
    return  0;
}

int draw_grid(int row_size,int col_size,int height,int width)
{
    for (int row=0;row<get_grid_size(row_size,height);row++) {
        for (int col=0;col<get_grid_size(col_size,width);col++) {
            if (row%(height+1) == 0) {
                if (col%(width+1) == 0) {
                    grid[row][col] = CROSS_BORDER;
                } else {
                    grid[row][col] = HORI_BORDER;
                }
            } else {
                if (col%(width+1) == 0) {
                    grid[row][col] = VERT_BORDER;
                } else {
                    grid[row][col] = EMPTY;
                }
            }
        }
        grid[row][get_grid_size(col_size,width)] = '\0';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for (int i=1;i<=N;i++) {
        int r,c,w,h;

        cin>>r>>c>>w>>h;
        cout<<"Case #"<<i<<":\n";

        draw_grid(r,c,h,w);
        print_grid(get_grid_size(r,h));
    }

    return  0;
}