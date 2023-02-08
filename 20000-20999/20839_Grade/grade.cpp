#include    <iostream>

using namespace std;

#define meet_fully(t,s) ((t)==(s))
#define meet_half(t,s)  ((t)<=2*(s))

int get_grade(int arr1[],int arr2[])
{
    int ret;

    if(meet_fully(arr1[2],arr2[2])) ret = 'E';
    else return ret;

    if(meet_half(arr1[1],arr2[1])) ret = 'D';
    else return ret;

    if(meet_fully(arr1[1],arr2[1])) ret = 'C';
    else return ret;

    if(meet_half(arr1[0],arr2[0])) ret = 'B';
    else return ret;

    if(meet_fully(arr1[0],arr2[0])) ret = 'A';
    else return ret;

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int target[3],score[3];

    for(int i=0;i<3;i++) cin>>target[i];
    for(int i=0;i<3;i++) cin>>score[i];

    cout<<(char)get_grade(target,score)<<'\n';

    return  0;
}