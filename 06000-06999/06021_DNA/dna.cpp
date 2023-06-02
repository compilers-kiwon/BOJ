#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (20+1)
#define DNA_LEN     25

static int      M,F,num_of_children[MAX_SIZE][MAX_SIZE];
static string   bull[MAX_SIZE],cow[MAX_SIZE];

#define read(pool,size) \
        {for(int i=1;i<=(size);i++)cin>>(pool)[i];}

bool    is_children(int b,int c,const string& child)
{
    for(int i=0;i<DNA_LEN;i++)
    {
        if( bull[b][i]!=child[i] && cow[c][i]!=child[i] )
        {
            return  false;
        }
    }

    return  true;
}

int input(void)
{
    cin>>M>>F;
    read(bull,M);read(cow,F);

    return  0;
}

int get_child(string pool[],int size,
                    int b,int c,int me)
{
    for(int i=1;i<=size;i++)
    {
        num_of_children[b][c] +=
            (i==me)?0:is_children(b,c,pool[i]);
    }

    return  0;
}

int get_num_of_children(void)
{
    for(int b=1;b<=M;b++)
    {
        for(int c=1;c<=F;c++)
        {
            get_child(bull,M,b,c,b);
            get_child(cow,F,b,c,c);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_num_of_children();

    for(int row=1;row<=M;row++)
    {
        for(int col=1;col<=F;col++)
        {
            cout<<num_of_children[row][col]
                        <<((col==F)?'\n':' ');
        }
    }

    return  0;
}