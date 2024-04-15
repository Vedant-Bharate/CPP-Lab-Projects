#include <iostream>

/*Purpose of main () function: It is responsible for orchestrating the overall flow oof the program.
It prompts the user for input, performs calculation, and outputs the result. it also concludes the program by returning 0,
indicating successful execution*/

int main() {

    // Defining variables
    int year1, year2, P1, P2;
    const double ccppr = 1008.97;
    double charity_year1, charity_year2, percent;

    // Getting input for Year 1
    std::cout << "Enter the first year: ";
    std::cin >> year1;

    // Getting input for Patients of Year 1
    std::cout << "Enter the number of patients we saw that year: ";
    std::cin >> P1;

    // Getting input for Year 2
    std::cout << "Enter the second year: ";
    std::cin >> year2;

    // Getting input for Patients of Year 2
    std::cout << "Enter the number of patients we saw that year: ";
    std::cin >> P2;

    // Calculating percent increase
    percent = ((float)(P2 - P1) / (float)P1) * 100;

    // Calculating Charity charges for all patient for Year 1
    charity_year1 = P1 * ccppr;

    // Calculating Charity charges for all patient for year 2
    charity_year2 = P2 * ccppr;

    // Outputting the result:
    std::cout << "In year " << year1 << ", our hospital issued " << charity_year1 << " dollars of charity charges.\n";
    std::cout << "In year " << year2 << ", our hospital issued " << charity_year2 << " dollars of charity charges.\n";
    std::cout << "Between " << year1 << " and " << year2 << ", there was a " << percent << "%" << " increase in patients seen at our hospital.\n";

    return 0;
}
