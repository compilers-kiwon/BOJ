#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

typedef pair<int,char>  Card;

#define TRUE    1
#define FALSE   0

#define NUM_OF_CHOICE   4

#define is_consecutive(n1,n2)   ((n1)+1==(n2))
#define is_triple(c1,c2,c3)     ((c1)==(c2)&&(c2)==(c3))
#define is_paired(c1,c2,c3,c4)  ((c1)==(c2)&&(c3)==(c4))

int is_sorted(const vector<Card>& c)
{
    if( !is_consecutive(c[0].first,c[1].first)
            || !is_consecutive(c[1].first,c[2].first) )
    {
        return  FALSE;
    }

    if( c[0].second!=c[1].second
            || c[1].second!=c[2].second )
    {
        return  FALSE;
    }

    return  TRUE;
}

int is_day_off(vector<Card>& c)
{
    do{
        if( is_sorted(c)
            || is_triple(c[0],c[1],c[2])
            || is_paired(c[0],c[1],c[2],c[3]) )
        {
            return  TRUE;
        }
    }while(next_permutation(c.begin(),c.end()));

    return  FALSE;
}

int main(void)
{
    int T;
    
    scanf("%d",&T);

    for(int t=1;t<=T;t++)
    {
        vector<Card>    c;

        for(int i=1;i<=NUM_OF_CHOICE;i++)
        {
            Card    choice;

            scanf("%1d%c",&choice.first,&choice.second);
            c.push_back(choice);
        }

        sort(c.begin(),c.end());
        cout<<(is_day_off(c)?":)":":(")<<'\n';
    }

    return  0;
}