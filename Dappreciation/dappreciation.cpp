
#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
    int model_year{ 0 };
    std::cout << "What is the model year of the car? ";
    std::cin >> model_year;
    return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
    int accidents{ 0 };
    std::cout << "How many accidents has the car been in? ";
    std::cin >> accidents;
    return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
    double msrp{ 0.0 };
    std::cout << "How much did you pay for the car? ";
    std::cin >> msrp;
    return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
    std::string has_options_string{ "" };
    std::cout << "Does your car have premium options (yes/no)? ";
    std::cin >> has_options_string;
    if (has_options_string == "yes") {
        return true;
    }
    else {
        return false;
    }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
    std::cout << std::fixed << std::setprecision(2)
        << "dappreciation will list your car for $" << resale_price
        << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
    std::cout << "Unfortunately your car is ineligible for the dappreciation "
        "platform.\n";
}

/*Purpose of main () function: It is responsible for orchestrating the overall flow oof the program.
It prompts the user for input, performs calculation, and outputs the result. it also concludes the program by returning 0,
indicating successful execution*/

int main() {
    // Prompt the user to enter the values using the functions defined above.
    int model_year = car_model_year();
    int accidents = car_accidents();
    bool has_premium_options = car_has_premium_options();
    double msrp = car_msrp();
    double resale_price = 0.0;

    //Declaring the constants.
    const int current_model = 2023;
    const double age_tier1 = 85;
    const double age_tier2 = 63;
    const double age_tier3 = 45;

    const double acc_nos_0 = -0;
    const double acc_nos_1 = -2;
    const double acc_nos_2 = -10;
    const double acc_nos_3 = -20;

    const double premium_false = 0;
    const double premium_true = 5;

    // Calculating the resale price of the car.

    int car_age = current_model - model_year;
    double percentage = 0.0;
    if ((car_age <= 10) && (accidents <= 3)) {

        // Computing Calculation:

        if ((car_age >= 0) && (car_age <= 4)) {
            percentage = age_tier1;
        }
        else if ((car_age >= 5) && (car_age <= 8)) {
            percentage = age_tier2;
        }
        else {
            percentage = age_tier3;
        }

        // Calculating Accidental Coverage:

        if (accidents == 1) {
            percentage = percentage + acc_nos_1;
        }
        else if (accidents == 2) {
            percentage = percentage + acc_nos_2;
        }
        else if (accidents == 3) {
            percentage = percentage + acc_nos_3;
        }
        else {
            percentage = percentage + 0;
        }

        // Calculating Premium:

        if (has_premium_options == true) {
            percentage = percentage + premium_true;
        }

        resale_price = ((percentage / 100) * msrp);

        print_eligible_message(resale_price);
    }
    else
    {
        print_ineligible_message();
    }

}