#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int k = 0;
        int len = nums.size();

        std::deque<int> waiting_switch_index_deque;

        for (int i = 0; i < len; i++){
            if (nums[i] == val){
                k += 1;
                waiting_switch_index_deque.push_back(i);
            }
        }

        int switch_end_index = len - k - 1;

        int switch_pointer = len - 1;

        while (switch_pointer > switch_end_index){
            if (nums[switch_pointer] != val){
                swap(nums, switch_pointer, waiting_switch_index_deque);
            }
            else{
                waiting_switch_index_deque.pop_back();
            }
            switch_pointer--;
        }

        return len - k;
    }

    void swap(vector<int>& nums, int switch_pointer, deque<int>& waiting_switch_index_deque){

        int waiting_switch_index = waiting_switch_index_deque.front();
        waiting_switch_index_deque.pop_front();

        int temp;

        temp = nums[switch_pointer];
        nums[switch_pointer] = nums[waiting_switch_index];
        nums[waiting_switch_index] = temp;
    }
};