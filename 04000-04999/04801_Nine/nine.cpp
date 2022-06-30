#include    <iostream>
#include    <cmath>
#include    <vector>

using namespace std;

#define get_diff(a,b)   (abs(a-b))

int     get_num_of_nines(int n)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        ret += ((n%10==9)?1:0);
    }

    return  ret;
}

bool    in_range(int desired,int specified)
{
    return  (10*abs(desired-specified)<specified);
}

int     get_microwave_time(int specified)
{
    int     ret,num_of_nines,sec;
    bool    over_flag = false;

    ret = num_of_nines = sec = 0;

    for(int t=0;t<=9999;t++)
    {
        int converted_sec = (t/100)*60+(t%100);

        if( in_range(converted_sec,specified) == false )
        {
            if( over_flag == true )
            {
                break;
            }

            continue;
        }
        
        over_flag = true;
        
        vector<int> inputs;

        inputs.push_back(t);

        int min_t,sec_t;

        min_t = converted_sec/60;
        sec_t = converted_sec%60;

        inputs.push_back(min_t*100+sec_t);

        for(int i=0;i<inputs.size();i++)
        {
            int n = inputs[i];
            int nines = get_num_of_nines(n);
            
            if( nines == 0 )
            {
                continue;
            }

            if( nines>num_of_nines 
                || ((nines==num_of_nines)&&(get_diff(converted_sec,specified)<get_diff(sec,specified)))
                || ((nines==num_of_nines)&&(get_diff(converted_sec,specified)==get_diff(sec,specified))&&(n<ret)) )
            {
                num_of_nines = nines;
                ret = n;
                sec = converted_sec;
            }
        }
    }

    return  (ret==0?specified:ret);
}

int     main(void)
{
    for(;;)
    {
        int MM,SS,t,n;

        scanf("%d:%d",&MM,&SS);
        t = MM*60+SS;
        
        if( t == 0 )
        {
            break;
        }

        n = get_microwave_time(t);
        printf("%02d:%02d\n",n/100,n%100);
    }

    return  0;
}