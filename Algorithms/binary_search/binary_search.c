int search(int* nums, int numsSize, int target) {
    // nums 原数组  
    // numsSize 原数组大小
    // target 目标值

    // 设定初始scope，初始scope由 定义
    int scope_start_pointer = 0; 
    int scope_end_pointer = numsSize - 1;

    // 进入某种循环
    while(scope_end_pointer >= scope_start_pointer){
        
        int mid_index = (scope_end_pointer + scope_start_pointer) / 2;  // integer division

        if (nums[mid_index] == target)
            return mid_index;    // 程序终止出口1：找到了
        
        // 没退出，继续搜索
        if (nums[mid_index] < target){
            scope_start_pointer = mid_index + 1;
        }
        else if (nums[mid_index] > target){
            scope_end_pointer = mid_index - 1;
        }

    }

    return -1;  // 程序终止出口2：没找到
}