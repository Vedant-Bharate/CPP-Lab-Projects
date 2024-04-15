#include "fcc.h"
#include <cassert>
#include <iostream>
#include <string>

bool test(const std::string &fixme_filename, const std::string &typo_filename,
          const std::string &fixo_filename, int expected_number_of_fixes,
          const std::string expected_fixed_string) {

  std::string actual_fixed_string{""};
  int actual_number_of_fixes{0};

  actual_number_of_fixes =
      fcc(fixme_filename, typo_filename, fixo_filename, actual_fixed_string);

  if (actual_number_of_fixes != expected_number_of_fixes) {
    std::cout << "ERROR: With fixme filename of " << fixme_filename
              << ", typo filename of " << typo_filename << ", fixo filename of "
              << fixo_filename << ", I expected " << expected_number_of_fixes
              << " corrections but you made " << actual_number_of_fixes
              << " corrections.\n";
    return false;
  }

  if (actual_number_of_fixes == -1) {
    return true;
  }

  if (expected_fixed_string != actual_fixed_string) {
    std::cout << "ERROR: With fixme filename of " << fixme_filename
              << ", typo filename of " << typo_filename << ", fixo filename of "
              << fixo_filename << ", I expected the fixed string to be '"
              << expected_fixed_string << "' but you fixed it as '"
              << actual_fixed_string << "'.\n";
    return false;
  }
  return true;
}

int main() {
  bool success{true};
  success &= test("test_data/fixme.txt", "test_data/typo.txt", "test_data/fixo.txt", 2, "the good one.");
  success &= test("test_data/fixme_annie.txt", "test_data/typo_annie.txt", "test_data/fixo_annie.txt", 4, "the sun will come out tomorrow.");
  success &= test("test_data/fixme_annie.txt", "test_data/typo_annie.txt", "test_data/fixo_annie.txt", 4, "the sun will come out tomorrow.");
  success &= test("test_data/fixme_annie_fail.txt", "test_data/typo_annie_fail.txt", "test_data/fixo_annie_fail.txt", -1, "");
  success &= test("test_data/fixme_christmas.txt", "test_data/typo_christmas.txt", "test_data/fixo_christmas.txt", 2, "you'll love this lab.");

  std::cout << (success ? "All tests passed.\n" : "Some tests failed.\n");
  return 0;
}
