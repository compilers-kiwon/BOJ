#include    <iostream>

using namespace std;

#define RED     0
#define GREEN   1
#define BLUE    2

#define get_score(A,C,r,g,b) \
        ((A)*((r)*(r)+(g)*(g)+(b)*(b))+(C)*min((r),min((g),(b))))
#define add(color,cur)  ((color)==(cur)?1:0)

int solve(int A,int C,int r,int g,int b)
{
    int ret,max_score;

    max_score = 0;

    for (int i=RED;i<=BLUE;i++) {
        int cur_score = get_score(A,C,
                r+add(RED,i),g+add(GREEN,i),b+add(BLUE,i));
        
        if (cur_score > max_score) max_score=cur_score,ret=i;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for (int i=1;i<=t;i++) {
        int A,C,r,g,b,result;

        cin>>A>>C>>r>>g>>b;
        result = solve(A,C,r,g,b);

        cout<<(result==RED?"RED":
            (result==GREEN)?"GREEN":"BLUE")<<'\n';
    }

    return  0;
}