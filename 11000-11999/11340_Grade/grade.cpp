#include    <iostream>

using namespace std;

#define get_total_score(s1,s2,s3,s4)    (((s1)*15+(s2)*20+(s3)*25+(s4)*40)/100)

int get_final_score(int project,int paper,int midterm)
{
    int ret = -1;

    for(int final=0;final<=100;final++)
    {
        if( get_total_score(project,paper,midterm,final) >= 90 )
        {
            ret = final;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int project,paper,midterm,final;

        cin>>project>>paper>>midterm;
        final = get_final_score(project,paper,midterm);

        if( final != -1 )
        {
            cout<<final<<'\n';
        }
        else
        {
            cout<<"impossible\n";
        }
    }

    return  0;
}