#include <stdio.h>
#include <limits.h>

// ���������ҵ�����Ӷκ�
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

// ����������������ĺ���
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
    printf("����Ӷκ�Ϊ %d", max_sum);
    return 0;
}