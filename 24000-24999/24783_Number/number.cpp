#include    <iostream>

using namespace std;

#define is_possible(a,b,c) \
    (produce((a),(b),(c))||produce((b),(a),(c)))

int produce(int a,int b,int c)
{
    return  ((a+b==c)||(a-b==c)
                ||(a/b==c&&a%b==0)||(a*b==c));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        cout<<(is_possible(a,b,c)?
            "Possible\n":"Impossible\n");
    }

    return  0;
}