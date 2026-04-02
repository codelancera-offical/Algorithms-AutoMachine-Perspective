#include <vector>
using namespace std;

// 双指针，滑动窗口，前进后跟刷新最小满足条件的窗口
// 时间复杂度: O(n)
// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/714664139/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int min_len = n;

        int left_pointer = 0;
        int right_pointer = 0;

        int sum = nums[left_pointer];

        // 先找到最小right_start
        while (sum < target){
            right_pointer++;
            if (right_pointer <= n-1)
                sum = sum + nums[right_pointer];
            else
                return 0;   // 全加上也小于target，返回0
        }

        min_len = right_pointer - left_pointer + 1;

        while(1){

            // left_pointer 前进到最小长度数组
            while (1){
                if (sum - nums[left_pointer] >= target){
                    sum = sum - nums[left_pointer];
                    left_pointer++;
                    int elements_nums = right_pointer - left_pointer + 1;

                    if (elements_nums < min_len)
                        min_len = elements_nums;
                }
                else{
                    break;
                }
            }

            // right_pointer 前进一步
            right_pointer++;
            if (right_pointer <= n-1)
                sum = sum + nums[right_pointer];
            else                                        // 出界结束之
                return min_len;
        }

        return min_len;

    }
};

// 感悟：当你觉得这里应该有个循环展开，但是你还不太明确终止条件的时候，不妨直接 while(1)展开，之后写着写着终止条件就出来了