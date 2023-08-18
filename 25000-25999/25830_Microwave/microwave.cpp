#include    <iostream>

using namespace std;

#define get_seconds(h,m,s)  ((h)*60*60+(m)*60+(s))

int convert_seconds_to_time(int num_of_seconds,
                                int& h,int& m,int& s)
{
    h = num_of_seconds/(60*60);
    m = (num_of_seconds%(60*60))/60;
    s = (num_of_seconds%(60*60))%60;

    return  0;
}

int main(void)
{
    int h,m,s,t1,t2;

    scanf("%d:%d",&m,&s);

    t1 = get_seconds(m,s,0);
    t2 = get_seconds(0,m,s);

    convert_seconds_to_time(t1-t2,h,m,s);
    printf("%02d:%02d:%02d\n",h,m,s);

    return  0;
}