#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    int N;

    cin>>N;

    for(int n=1;n<=N;n++)
    {
        int     x;
        double  sum;

        cin>>x;
        sum = 0.0;

        for(int i=1;i<=x;i++)
        {
            string  item;
            double  q,p;

            cin>>item>>q>>p;
            sum += p*q;
        }

        printf("$%.02f\n",sum);
    }

    return  0;
}