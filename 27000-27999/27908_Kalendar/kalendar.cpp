#include    <iostream>
#include    <string>

using namespace std;

const static int length_of_week = 21;
const static string border = "+---------------------+";
const static int TWO_DIGIT_NUM = 10;

void    simulate(string& kalendar,
            int num_of_days,int start)
{
    for (int d=1;d<start;d++) kalendar+="...";
    for (int d=1;d<=num_of_days;d++)
        kalendar += ((d<TWO_DIGIT_NUM)?"..":".")+to_string(d);
    for (;kalendar.length()%length_of_week!=0;kalendar+="...");
}

void    print(const string& kalendar)
{
    cout<<border<<'\n';

    for (int p=0;p<kalendar.length();p+=length_of_week) {
        cout<<'|'<<kalendar.substr(p,length_of_week)<<'|'<<'\n';
    }

    cout<<border<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,d;
    string  k;

    cin>>n>>d;
    simulate(k,n,d);
    print(k);

    return  0;
}