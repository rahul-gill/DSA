#include<cp_debug.h>

void rotate(int nums[], int n, int k) {
    if ((n == 0) || (k <= 0) || (k % n == 0)) {
        return;
    }

    k = k % n;
    // Rotation to the right by k steps is equivalent to swapping
    // the two subarrays nums[0,...,n - k - 1] and nums[n - k,...,n - 1].
    int start = 0;
    int tmp = 0;
    while (k > 0) {
        if (n - k >= k) {
            // The left subarray with size n - k is longer than
            // the right subarray with size k. Exchange
            // nums[n - 2*k,...,n - k - 1] with nums[n - k,...,n - 1].
            for (int i = 0; i < k; i++)
                swap(nums[start + n - 2 * k + i], nums[start + n - k + i]);
            // nums[n - 2*k,...,n - k - 1] are in their correct positions now.
            // Need to rotate the elements of nums[0,...,n - k - 1] to the right
            // by k%n steps.
            n = n - k;
            k = k % n;
        } else {
            // The left subarray with size n - k is shorter than
            // the right subarray with size k. Exchange
            // nums[0,...,n - k - 1] with nums[n - k,...,2*(n - k) - 1].
            for (int i = 0; i < n - k; i++)
                swap(nums[start + i], nums[start + n - k + i]);
            // nums[n - k,...,2*(n - k) - 1] are in their correct positions now.
            // Need to rotate the elements of nums[n - k,...,n - 1] to the right
            // by k - (n - k) steps.
            tmp = n - k;
            n = k;
            k -= tmp;
            start += tmp;
        }
    }
}

int main() {
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    debug(a);
    rotate(a, 3);
    debug(a);
}
