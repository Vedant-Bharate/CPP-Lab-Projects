#include <iostream>
#include <sstream>
#include <iomanip>
#include <assert.h>

int get_int() {
  int gotten{0};
  std::cin >> gotten;
  return gotten;
}

double calculate_per_capita_gdp_estimate(int quarters_from_epoch) {
  const double COEFFICIENT{532.453594414277};
  const double INTERCEPT{ 9341.51866436077 };
  return quarters_from_epoch * COEFFICIENT + INTERCEPT;
}

std::string format_money(double money) {
  std::ostringstream money_stream{};
  money_stream << std::fixed << std::setprecision(2) << money;
  return money_stream.str();
}

std::string quarter_to_ordinal(int quarter) {
  switch (quarter) {
    case 1:
      return "first";
    case 2:
      return "second";
    case 3:
      return "third";
    case 4:
      return "fourth";
  }
  assert(("Failure: You gave me an invalid quarter!", false));
}