#include    <iostream>

using namespace std;

#define MAX_NUM_OF_DAYS     (31+1)
#define MAX_NUM_OF_PERSONS  (1000+1)

static int  M,N,P,max_num_of_steps[MAX_NUM_OF_DAYS];
static int  S[MAX_NUM_OF_PERSONS][MAX_NUM_OF_DAYS];

int input(void)
{
    cin>>M>>N>>P;
    fill(&max_num_of_steps[1],&max_num_of_steps[N+1],0);

    for (int i=1;i<=M;i++) {
        for (int j=1;j<=N;j++) {
            cin>>S[i][j];
            max_num_of_steps[j] =
                max(max_num_of_steps[j],S[i][j]);
        }
    }

    return  0;
}

int get_num_of_required_steps(void)
{
    int ret = 0;

    for (int i=1;i<=N;i++) {
        ret += max_num_of_steps[i]-S[P][i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        input();
        cout<<"Case #"<<t<<": "<<
            get_num_of_required_steps()<<'\n';
    }

    return  0;
}