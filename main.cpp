/*
 * CTRR - HK242
 * file : main.cpp
 * SRC template
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 25.02.2024
 */

#include "main.hpp"
#include "unit_test.hpp"

string TEST_CASE = "Bellman";
int main(int argc, char *argv[])
{
  cout << "-------------------------------------------------------------"
       << endl;
  cout << GREEN << BOLD << TEST_CASE << " - CTRR - HK242 - VO TIEN" << endl;
  cout << CYAN << BOLD << "Vo Tien : https://www.facebook.com/Shiba.Vo.Tien" << endl
       << endl;
  if (argc < 1)
  {
    printTestCase();
    return 1;
  }

  handleTestUnit(argc, argv);
  cout << "-------------------------------------------------------------"
       << endl;
}

void handleTestUnit(int argc, char *argv[])
{
  UNIT_TEST unitTest;

  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "all"))
  {
    std::cout << GREEN << BOLD << "Running unit_test " << TEST_CASE << RESET << "\n";
    unitTest.runAllTests();
  }
  else if (argc == 2)
  {
    std::cout << GREEN << BOLD << "Running unit_test " << TEST_CASE << RESET << "\n";
    unitTest.runTest(argv[1]);
  }
  else
  {
    printTestCase();
  }
}
