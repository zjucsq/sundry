#include <iostream>
using namespace std;

// partition 方法
int partition(int* arr, int l, int r) {
  int j = l + 1;
  for (int i = j; i <= r; i++) {
    if (arr[i] < arr[l]) {
      swap(arr[i], arr[j]);  // 交换后的 arr[j] 为当前最后一个小于主轴元素的元素
      j++;
    }
  }
  swap(arr[l], arr[j - 1]);  // 主轴元素归位
  return j - 1;
}

// 单轴快排递归方法：首位为轴
void quickSortSimple(int* arr, int l, int r) {
  if (l < r) {  // 若left == right，表示此时 arr
                // 只有一个元素，即为基准情形，完成递归
    int p = partition(arr, l, r);
    quickSortSimple(arr, l, p - 1);

    quickSortSimple(arr, p + 1, r);
  }
}

int main() {
  int nums[9] = {1, 4, 5, 7, 9, 8, 2, 3, 6};
  quickSortSimple(nums, 0, 9);
  for (int i = 0; i < 9; ++i) cout << nums[i] << ' ';
  cout << endl;
}