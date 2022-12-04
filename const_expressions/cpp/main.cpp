#define ARR_SIZE 4
const int arr_size = 4;

constexpr int constexpr_func(int arg) { return arg++; }

int global_arr0[ARR_SIZE];
int global_arr1[ARR_SIZE] = {0, 1, 2, 3};
int global_arr2[arr_size];
int global_arr3[arr_size] = {0, 1, 2, 3};

int main() {
  int local_num;

  int local_arr0[ARR_SIZE];
  int local_arr1[ARR_SIZE + 1] = {0, 1, 2, 3};
  int local_arr2[sizeof(int)] = {0, 1, 2, 3};

  local_num = 2;
  int local_arr3[arr_size];
  int local_arr4[local_num];
  int local_arr5[arr_size] = {0, 1, 2, 3};
  int local_arr6[constexpr_func(arr_size)];

  return 0;
}
