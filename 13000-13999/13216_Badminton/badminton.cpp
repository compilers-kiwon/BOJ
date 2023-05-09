#include    <iostream>
#include    <string>

using namespace std;

int simulate(string& rec)
{
    int A_win,B_win;

    for(A_win=B_win=0;A_win!=2&&B_win!=2;)
    {
        int A_score,B_score,i;

        for(A_score=B_score=i=0;A_score!=21&&B_score!=21;i++)
        {
            (rec[i]=='A')?A_score++:B_score++;
        }

        cout<<A_score<<'-'<<B_score<<'\n';
        (A_score==21)?A_win++:B_win++;
        rec.erase(0,i);
    }

    return  (A_win==2)?'A':'B';
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  r;

    cin>>r;
    cout<<(char)simulate(r)<<'\n';

    return  0;
}