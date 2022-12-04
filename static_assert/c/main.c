// requires /std:c11 or higher
#include <assert.h>

enum Items { A, B, C, LENGTH };

int main() {
  // _Static_assert is a C11 keyword
  _Static_assert(LENGTH == 3, "Expected Items enum to have three elements");

  // Preferred: static_assert maps to _Static_assert and is compatible with C++
  static_assert(sizeof(int) == 4, "Expecting 32 bit integers");

  return 0;
}
