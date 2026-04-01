#include <vector>
#include <deque>
#include <cstdlib>


using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    
        int len = nums.size();

        int not_pos_pt = 0;
        int pos_pt = len - 1;

        deque<int> result_nums; // 
        
        while (nums[not_pos_pt] <= 0 && nums[pos_pt] > 0){

            int not_pos_val_abs = abs(nums[not_pos_pt]);
            int pos_val_abs = nums[pos_pt];
            
            if (not_pos_val_abs > pos_val_abs){
                result_nums.push_front(nums[not_pos_pt]);
                not_pos_pt++;
            }
            else{   // pos_val_abs >= not_pos_val_abs
                result_nums.push_front(pos_val_abs);
                pos_pt--;
            }
        }

        if (nums[not_pos_pt] > 0){
            while(pos_pt >= 0 && nums[pos_pt] > 0){                     // 这里得先检查是否越界，再检查是否 > 0，否则直接崩溃
                result_nums.push_front(nums[pos_pt]);
                pos_pt--;
            }
        }
        else{   // nums[pos_pt] <= 0
            while (not_pos_pt <= len - 1 && nums[not_pos_pt] <= 0 ){    // 同理，先检查越界
                result_nums.push_front(nums[not_pos_pt]);
                not_pos_pt++;
            }
        }

        vector<int>answer = vector<int>(result_nums.begin(), result_nums.end());

        for (auto& n : answer) {
            n = n * n;
        }

        return answer;
    }
};
