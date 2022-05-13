int findUnsortedSubarray(int* nums, int numsSize) {
    int ret = 0;
    int i, j, k, last_index=numsSize-1;
    int unsorted_begin, unsorted_end;
    int first_part_max;
    int second_part_min, second_part_max;
    int third_part_min;

    first_part_max = nums[0];
    for (i=0, unsorted_begin=-1; i<last_index; i++) {
        if (nums[i] > nums[i+1]) {  // unsorted begin
            unsorted_begin = i;
            third_part_min = nums[last_index];
            for (j=last_index-1; j>=i; j--) {
                if (nums[j] > nums[j+1]) {
                    unsorted_end = j+1;
                    second_part_min = second_part_max = nums[unsorted_begin];
                    for (k=unsorted_begin; k<=unsorted_end; k++) {
                        second_part_min = (second_part_min < nums[k]) ? second_part_min : nums[k];
                        second_part_max = (second_part_max > nums[k]) ? second_part_max : nums[k];
                    }
                    break;
                } else {
                    third_part_min = (third_part_min < nums[j+1]) ? third_part_min : nums[j+1];
                }
            }
            break;
        } else {
            first_part_max = (first_part_max > nums[i]) ? first_part_max : nums[i];
        }
    }
    if (unsorted_begin != -1) { 
        for (i=unsorted_begin-1; i>=0; i--) {
            if (nums[i] > second_part_min || nums[i] > third_part_min) {
                unsorted_begin--;
            }
        }
        
        for (i=unsorted_end+1; i<=last_index; i++) {
            if (nums[i] < first_part_max || nums[i] < second_part_max) {
                unsorted_end++;
            }
        }
        ret = unsorted_end-unsorted_begin+1;
    }

    return ret;
}
