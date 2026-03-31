void bubble_sort_c(const double *in_array, double *out_array, int n){

    // 先拷贝
    for(int i = 0; i < n; i++){
        out_array[i] = in_array[i];
    }

    // 执行冒泡排序
    int start_float_pointer = 0;

    while(start_float_pointer < n){
        
        int curr_float_pointer = start_float_pointer;

        while(curr_float_pointer != 0){
            
            if (out_array[curr_float_pointer] < out_array[curr_float_pointer - 1]){
                // swap
                double temp = out_array[curr_float_pointer];
                out_array[curr_float_pointer] = out_array[curr_float_pointer - 1];
                out_array[curr_float_pointer - 1] = temp;

                curr_float_pointer--;
            }
            else{
                break;
            }
        }

        start_float_pointer++;
    }
}
