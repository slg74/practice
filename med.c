#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

double find_median_sorted_arrays(int* nums1, int nums1_size, int* nums2, int nums2_size) {
    if (nums1_size > nums2_size) {
        return find_median_sorted_arrays(nums2, nums2_size, nums1, nums1_size);
    }
    
    int low_index = 0;
    int high_index = nums1_size;
    int partition_x, partition_y;
    int max_left_x, max_left_y, min_right_x, min_right_y;
    
    while (low_index <= high_index) {
        partition_x = (low_index + high_index) / 2;
        partition_y = (nums1_size + nums2_size + 1) / 2 - partition_x;
        
        max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
        min_right_x = (partition_x == nums1_size) ? INT_MAX : nums1[partition_x];
        
        max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];
        min_right_y = (partition_y == nums2_size) ? INT_MAX : nums2[partition_y];
        
        if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
            if ((nums1_size + nums2_size) % 2 == 0) {
                return ((double)fmax(max_left_x, max_left_y) + fmin(min_right_x, min_right_y)) / 2;
            } else {
                return (double)fmax(max_left_x, max_left_y);
            }
        } else if (max_left_x > min_right_y) {
            high_index = partition_x - 1;
        } else {
            low_index = partition_x + 1;
        }
    }
    
    return -1;
}

int main() {
    int nums1[] = {1, 3, 8, 9, 15};
    int nums2[] = {7, 11, 18, 19, 21, 25};
    int nums1_size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2_size = sizeof(nums2) / sizeof(nums2[0]);
    
    double median_value = find_median_sorted_arrays(nums1, nums1_size, nums2, nums2_size);
    printf("Median: %.2f\n", median_value);
    
    return 0;
}
