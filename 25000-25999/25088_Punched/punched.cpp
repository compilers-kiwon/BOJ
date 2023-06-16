#include    <iostream>
#include    <string>

using namespace std;

const static string full_card[] = {
    "..+-+-+-+-+-+-+-+-+-+",
    "..|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+",
    "|.|.|.|.|.|.|.|.|.|.|",
    "+-+-+-+-+-+-+-+-+-+-+"
};

int print_card(int row_size,int col_size)
{
    for(int row=0;row<2*row_size+1;row++)
    {
        for(int col=0;col<2*col_size+1;col++)
        {
            cout<<full_card[row][col];
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int R,C;

        cin>>R>>C;

        cout<<"Case #"<<t<<":\n";
        print_card(R,C);
    }

    return  0;
}