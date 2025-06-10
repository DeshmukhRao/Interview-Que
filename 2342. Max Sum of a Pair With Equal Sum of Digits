class Solution {
private:
    int calcIndivSum(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }

        return res;
    }

public:
    int maximumSum(vector<int>& nums) {
        int maxNum = -1;
        unordered_map<int, int> digitSum;

        for (const int &num : nums) {
            int indivSum = calcIndivSum(num);

            // if it is in the map:
            if (digitSum.find(indivSum) != digitSum.end()) {
                maxNum = max(maxNum, num + digitSum[indivSum]);
                digitSum[indivSum] = max(digitSum[indivSum], num);

            // otherwise, just append the key as indivSum, and value is the number itself
            } else {
                digitSum[indivSum] = num;

            }
        }

        return maxNum;
    }
};