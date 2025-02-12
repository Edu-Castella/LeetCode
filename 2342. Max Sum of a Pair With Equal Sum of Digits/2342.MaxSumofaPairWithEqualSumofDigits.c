/*

2342. Max Sum of a Pair With Equal Sum of Digits

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, 
and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.


Example 1:
    Input: nums = [18,43,36,13,7]
    Output: 54
    Explanation: The pairs (i, j) that satisfy the conditions are:
    - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    So the maximum sum that we can obtain is 54.

Example 2:
    Input: nums = [10,12,19,14]
    Output: -1
    Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 
Constraints:
    - 1 <= nums.length <= 105
    - 1 <= nums[i] <= 109

*/



int sumDigits(int num){
    int digSum = 0;
    digSum = 0;
    while(num != 0){
        digSum += num % 10;
        num /= 10;
    }
    return digSum;
}

int maximumSum(int* nums, int numsSize) {
    int maxSum = -1;
    int digSum = 0;
     
    int* array = calloc(90, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        digSum = sumDigits(nums[i]);
        
        if(array[digSum] == 0){
            array[digSum] = nums[i];
            continue;
        }
        if((array[digSum] + nums[i]) > maxSum) maxSum = (array[digSum] + nums[i]); 
        if(array[digSum] < nums[i]) array[digSum] = nums[i];
        
    }
    free(array);
    return maxSum;
}