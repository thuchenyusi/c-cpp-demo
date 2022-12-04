#define ARR_SIZE 4
const int arr_size = 4;

int global_arr0[ARR_SIZE];
int global_arr1[ARR_SIZE] = {0, 1, 2, 3};

// 不合法，静态数组在上电时分配内存，其大小需要在编译期计算
// int global_arr2[arr_size];
// int global_arr3[arr_size] = {0, 1, 2, 3};

int main() {
  int local_num;

  // 合法，编译时能确定数组大小
  int local_arr0[ARR_SIZE];
  int local_arr1[ARR_SIZE + 1] = {0, 1, 2, 3};
  int local_arr2[sizeof(int)] = {0, 1, 2, 3};
  static int staitc_arr[sizeof(local_num++)] = {0, 1, 2, 3};

  local_num = 2;
  // C11以后合法，非静态和线程存储期的数组在运行main函数时才会初始化，在此之前arr_size被求值即可
  int local_arr3[arr_size];
  int local_arr4[local_num];

  // 不合法，编译时需要保存{0, 1, 2, 3}
  // int local_arr5[arr_size] = {0, 1, 2, 3};

  // 合法，&global_arr0[0]为地址常量，函数名退化为函数指针
  static int *static_pointer0 = &global_arr0[0];
  static int (*static_pointer1)() = main;

  // 合法，非静态和线程存储期，在运行main函数时能求值即可
  int *local_pointer0 = &local_num;

  return 0;
}
