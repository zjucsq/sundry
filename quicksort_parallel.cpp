#include <iostream>
#include <thread>
using namespace std;

// constexpr int N = 100000;

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
void quickSortParallel(int* arr, int l, int r) {
  if (l < r) {  // 若left == right，表示此时 arr
                // 只有一个元素，即为基准情形，完成递归
    int p = partition(arr, l, r);
    thread t_left(quickSortParallel, arr, l, p - 1);
    thread t_right(quickSortParallel, arr, p + 1, r);
    // t_left.join();
    // t_right.join();
    t_left.detach();
    t_right.detach();
  }
}

void quickSortSimple(int* arr, int l, int r) {
  if (l < r) {  // 若left == right，表示此时 arr
                // 只有一个元素，即为基准情形，完成递归
    int p = partition(arr, l, r);
    quickSortSimple(arr, l, p - 1);
    quickSortSimple(arr, p + 1, r);
  }
}

int main() {
  int N;
  cin >> N;

  int* nums1 = new int[N];
  int* nums2 = new int[N];
  for (int i = 0; i < N; ++i) {
    int tmp = rand();
    nums1[i] = tmp;
    nums2[i] = tmp;
  }

  clock_t start, end;
  start = clock();
  quickSortParallel(nums1, 0, N - 1);
  end = clock();
  cout << "Run time 1: " << (double)(end - start) / CLOCKS_PER_SEC << "S"
       << endl;

  start = clock();
  quickSortSimple(nums2, 0, N - 1);
  end = clock();
  cout << "Run time 2: " << (double)(end - start) / CLOCKS_PER_SEC << "S"
       << endl;

  for (int i = 0; i < N; ++i) {
    if (nums1[i] != nums2[i])
      cout << "error" << endl;
  }

  cout << endl;
}