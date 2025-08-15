// Fenwick tree usage in lc problem:
// https://leetcode.com/problems/queue-reconstruction-by-height/submissions/734189696/?envType=problem-list-v2&envId=xcewnh4d

class Solution {
public:
    vector<int>BIT;

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        BIT = vector<int>(n + 1, 0);

        for(int i = 2; i <= n; ++ i) update(i, 1);
        vector<vector<int>>ans(n);
        sort(people.begin(), people.end(), cmp);

        for(auto &p: people){

            int lo = 1, hi = n, mid, res;
            while(lo <= hi){
                mid = lo + (hi - lo) / 2;

                if(prefSum(mid) >= p[1]){
                    res = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            update(res, -1);
            ans[res - 1] = p;
        }


        return ans;
    }


    static bool cmp(const vector<int> &a, const vector<int> &b){
        return (a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]));
    }

    void update(int idx, int delta){
        for(int i = idx; i < BIT.size(); i += (i&-i)){
            BIT[i] += delta;
        }
    }

    int prefSum(int idx){
        int sum = 0;
        for(int i = idx; i > 0; i -= (i&-i)){
            sum += BIT[i];
        }
        return sum;
    }



};