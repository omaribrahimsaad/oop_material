#include <string>
#include <iostream>
#include <cmath>

// exercise objective: To make a car class that can calculate the 
// value of a car given a year. The depreciation rate is 5%.

// step 1: define class
class Car
{
public:
    // step 3: we define a constructor to initalize our values
    Car(std::string model,int year_made,float initial_price)
    {
        model_ = model;
        year_made_ = year_made;
        initial_price_ = initial_price;
    }

    // step 4: we add a method that calculates the price of a car 
    // in a given year.
    float CalculatePrice(int year)
    {
        return initial_price_ * std::pow(1-0.05,year- year_made_);
    }

// step 2: we define the required attributes 
private:
    std::string model_;
    int year_made_;
    float initial_price_;

};


// step 5: Use main to test our code 
int main()
{

    // step 5.1: get the initial value of the car:
    std::cout << "Enter the model of the car: ";
    std::string car_model;
    std::cin >> car_model;

    std::cout << "Enter the year the car was made: ";
    int car_year_made;
    std::cin >> car_year_made;

    std::cout << "Enter the intial price of the car: ";
    float initial_price;
    std::cin >> initial_price;

    // step 5.2: create an instance of the car using the input values
    Car new_car(car_model,car_year_made,initial_price);

    // step 5.3: prompt user what year they would like to check the price
    while(true)
    {
        std::cout << "Calculate the price of the car.\nEnter the year to calculate:";

        int year_to_calculate;
        std::cin >> year_to_calculate;

        // step 5.4: try to calculate the price using the user input value.
        std::cout << "The calculated car value for this year is: ";
        std::cout << new_car.CalculatePrice(year_to_calculate);
        
        std::cin.ignore();
        std::cin.get();
        
    }


}
