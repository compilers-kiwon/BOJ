#include <iostream>
#include <string>

using namespace std;

int get_total_minutes(const string& s) {
    size_t d_pos = s.find(':');
    string h = s.substr(0, d_pos);
    string m = s.substr(d_pos + 1);
    
    return ((stoi(h) * 60) + stoi(m)); 
}

#define consider(s,v,f) (((s)=="1")?(v)*(f):(v))

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string hill_name, time, day, weather, snowed, holiday;

    getline(cin, hill_name);

    cin >> time >> day >> weather
        >> snowed >> holiday;

    int total_minutes = get_total_minutes(time);

    day = (day=="sat"||day=="sun")?"1":"0";

    total_minutes = consider(day, total_minutes, 2);
    total_minutes = consider(weather, total_minutes, 2);
    total_minutes = consider(snowed, total_minutes, 3);
    total_minutes = consider(holiday, total_minutes, 3);

    cout << total_minutes / 60 << ':' <<
            ((total_minutes%60<10)?"0":"") << total_minutes % 60 << '\n';
    
    return 0;
}