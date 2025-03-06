#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

#define MOD(n) ((n)%1000000007)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string dna;
    uint64_t cnt[0x100], total, L;

    cin>>L>>dna;
    total = 1;
    fill(cnt, cnt + 0x100, 0);

    for (size_t i = 0; i < dna.length(); i++) {
        cnt[dna[i]]++;
    }

    const string required = "ACGT";

    for (size_t i = 0; i < required.length(); i++) {
        total = MOD(total*cnt[required[i]]);
    }

    cout<<total<<'\n';
    return 0;
}