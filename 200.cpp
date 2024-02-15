https://leetcode.com/submissions/detail/1175178465/
class Solution {
public:
int fnc(int nums){
    int cnt = 0;
    while (nums % 3 != 0 && nums > 0) {
        nums = nums - 2;
        cnt++;
    }
    if (nums == 0) return cnt;
    if (nums % 3 == 0) return (cnt + nums / 3);
    return -1; 
}

    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int cnt = 0;
        for (auto i : mp) {
            if (fnc(i.second) == -1)
                return -1;
            cnt += fnc(i.second);
        }
        return cnt;
    }
};