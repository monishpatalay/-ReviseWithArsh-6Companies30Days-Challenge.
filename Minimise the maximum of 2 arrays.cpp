#include <vector>
#define ll long long
class Solution {
public:

    int satisfy(ll div1, ll div2, ll uni1, ll uni2, ll mid){
        ll divByDiv1 = mid/div1, divByDiv2 = mid/div2;
        ll notDivByDiv1 = mid - divByDiv1, notDivByDiv2 = mid - divByDiv2;
        ll notDivByBoth = mid - mid/lcm(div1,div2);

        if(notDivByDiv1 >= uni1 and notDivByDiv2 >= uni2 and notDivByBoth >= uni1+uni2){
            return true;
        }
        return false;
    }

    int minimizeSet(ll divisor1, ll divisor2, ll uniqueCnt1, ll uniqueCnt2) {
        ll low = 1, high = INT_MAX;
            ll ans= INT_MAX;
            while(low<=high){
                ll mid = (low+high)/2;
                if(satisfy(divisor1,divisor2,uniqueCnt1,uniqueCnt2,mid)){
                    high = mid-1;
                    ans = min(ans,mid);
                } else{
                    low = mid+1;
                }
            }
            return ans;
    }
};
