#include    <iostream>
#include    <vector>

using namespace std;

// first: start_time(min), second: end_time(min)
typedef pair<int,int>   Schedule;   

#define MINUTES_PER_DAY     (60*24)
#define get_minutes(hh,mm)  ((hh)*60+(mm))

int main(void)
{
    for(;;) {
        int N;
        
        scanf("%d",&N);
        if(N == 0) break;

        bool conflict = false;
        bool occupied[MINUTES_PER_DAY] = {false,};
        
        vector<Schedule> s;

        for (int i=1;i<=N;i++) {
            int hh1,mm1,hh2,mm2;

            scanf("%d:%d-%d:%d",&hh1,&mm1,&hh2,&mm2);
            s.push_back({get_minutes(hh1,mm1),get_minutes(hh2,mm2)}); 
        }

        for (int i=0;i<s.size()&&conflict!=true;i++) {
            int start = s[i].first;
            int end = s[i].second;

            for (int m=start;m<end;m++) {
                if (occupied[m] == true) {
                    conflict = true;
                    break;
                }
                occupied[m] = true;
            }
        }

        printf("%sconflict\n",(conflict)?"":"no ");
    }

    return  0;
}