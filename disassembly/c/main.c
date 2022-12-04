#define ARR_SIZE 4
const int arr_size = 4;

int global_arr0[ARR_SIZE];
int global_arr1[ARR_SIZE] = {0, 1, 2, 3};

int main() {
  int local_num;

  int local_arr0[ARR_SIZE];
  int local_arr1[ARR_SIZE + 1] = {4, 5, 6, 7};
  int local_arr2[sizeof(int)] = {8, 9, 10, 11};

  local_num = global_arr1[2];
  int local_arr4[local_num];

  static int *static_pointer0 = &global_arr0[0];
  static int (*static_pointer1)() = &main;

  int *local_pointer0 = &local_num;

  return local_num;
}
