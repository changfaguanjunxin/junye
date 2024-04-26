#include <stdio.h>
#include <limits.h>

// 函数用于找到最大子段和
int maxSubArraySum(int a[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

// 主函数来测试上面的函数
int main() {
    int a[10000];
    int m;
    scanf("%d", &m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d", &a[i]);
    }
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    printf("最大子段和为 %d", max_sum);
    return 0;
}
