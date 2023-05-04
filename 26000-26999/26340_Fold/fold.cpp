#include    <iostream>

using namespace std;

#define fold_paper(p)   ((p)/=2)

#define swap_if_changed(big,small) \
        {if((big)<(small))swap((big),(small));}

int fold(int& n1,int& n2,int t)
{
    int big = max(n1,n2);
    int small = min(n1,n2);

    for(int i=1;i<=t&&big!=0;i++)
    {
        fold_paper(big);
        swap_if_changed(big,small);
    }

    n1 = big;
    n2 = small;

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int l1,l2,f;

        cin>>l1>>l2>>f;
        cout<<"Data set: "<<l1<<' '<<l2<<' '<<f<<'\n';

        fold(l1,l2,f);
        cout<<l1<<' '<<l2<<"\n\n";
    }

    return  0;
}