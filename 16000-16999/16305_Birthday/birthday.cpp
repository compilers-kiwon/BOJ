#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <cmath>

using namespace std;

#define MAX_LEN_OF_NAME         (20)
#define NUM_OF_DAYS_PER_YEAR    (365)
#define END_DAY_OF_YEAR         (NUM_OF_DAYS_PER_YEAR)

#define START_MONTH (10)
#define START_DAY   (28)

const static int    days_of_month[12+1] = {
    0,31,28,31,30,31,30,31,31,30,31,30,31
};

int get_num_of_days(int month,int day)
{
    int ret = 0;

    for (int m=1;m<month;m++) {
        ret += days_of_month[m];
    }

    return  ret+day;
}

int input(vector<int>& birthdays)
{
    int     n;
    char    colleage[MAX_LEN_OF_NAME];

    scanf("%d",&n);

    for (int i=1;i<=n;i++) {
        int mm,dd;

        scanf("%s %d-%d",colleage,&mm,&dd);
        birthdays.push_back(get_num_of_days(mm,dd));
    }

    sort(birthdays.begin(),birthdays.end());
    return  0;
}

int main(void)
{
    vector<int> birthdays;

    int max_diff = 0;
    vector<int> candidates;

    input(birthdays);
    birthdays.insert(birthdays.begin(),birthdays.back());
    
    for (int i=1;i<birthdays.size();i++) {
        birthdays[i]+= NUM_OF_DAYS_PER_YEAR;
    }

    for (int i=1;i<birthdays.size();i++) {
        if (max_diff <= abs(birthdays[i]-birthdays[i-1])) {
            if (max_diff < abs(birthdays[i]-birthdays[i-1])) {
                candidates.clear();
            }

            candidates.push_back((birthdays[i]-NUM_OF_DAYS_PER_YEAR)-1);
            max_diff = abs(birthdays[i]-birthdays[i-1]);
        }
    }

    sort(candidates.begin(),candidates.end());

    if (candidates.front() == 0) {
        candidates.erase(candidates.begin());
        candidates.push_back(END_DAY_OF_YEAR);
    }

    int today = get_num_of_days(START_MONTH,START_DAY);
    vector<int>::iterator it =
        lower_bound(candidates.begin(),candidates.end(),today);
    
    if (it == candidates.end()) {
        it = candidates.begin();
    }
    
    for (int m=1;m<=12;m++) {
        for (int d=1;d<=days_of_month[m];d++) {
            if (get_num_of_days(m,d) == (*it)) {
                printf("%02d-%02d\n",m,d);
                return  0;
            }
        }
    }

    return  0;
}