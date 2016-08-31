#include <stdio.h>

void swap(int *nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void reverse(int *nums, int start, int numsSize) {
	int i = start, j = numsSize - 1;
	while (i < j) {
		swap(nums, i, j);
		i++;
		j--;
	}
}

void nextPermutation(int *nums, int numsSize) {
	int i = numsSize - 2;
	while (i >= 0 && nums[i+1] <= nums[i])
		i--;
	if (i >= 0) {
		int j = numsSize - 1;
		while (j >= 0 && nums[j] <= nums[i])
			j--;
		swap(nums, i, j);
	}
	reverse(nums, i + 1, numsSize);
}

int main() {
	int nums[3] = {1, 2, 3};
	nextPermutation(nums, 3);
	for (int i = 0; i < 3; ++i)
		printf("%d ", nums[i]);
}
