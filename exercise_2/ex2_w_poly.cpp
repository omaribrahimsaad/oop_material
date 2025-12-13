#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>

// TODO: Create a base Vehicle class with:
// - Constructor taking model, year_made, initial_value
// - Pure virtual function: CalculateCurrentValue(int current_year)
// - Virtual destructor
// - Method to get model name

class Vehicle {
public:
    Vehicle(std::string model, int year_made, float initial_value)
    {
        
    }

    // YOUR CODE HERE
};

// TODO: Implement Car class
// - Inherits from Vehicle
// - Depreciates at 5% per year

class Car : public Vehicle {
public:
    Car(std::string model, int year_made, float initial_value)
        :Vehicle(model,year_made,initial_value)
    {
        
    }

    // YOUR CODE HERE
};

// TODO: Implement Truck class
// - Inherits from Vehicle
// - Depreciates at 7% per year
// - Has cargo_capacity member

class Truck : public Vehicle {
public:
    Truck(std::string model, int year_made, float initial_value,int cargo_capacity)
    :Vehicle(model,year_made,initial_value)
    {}
    // YOUR CODE HERE
};

// TODO: Implement Motorcycle class
// - Inherits from Vehicle
// - Depreciates at 10% per year
// - Has engine_cc member

class Motorcycle : public Vehicle {
public:
    Motorcycle(std::string model, int year_made, float initial_value,int cargo_capacity)
    :Vehicle(model,year_made,initial_value)
    {}

    // YOUR CODE HERE
};

int main() {
    // Now we can store ALL vehicles in ONE container!
    std::vector<std::shared_ptr<Vehicle>> fleet;
    
    fleet.push_back(std::make_shared<Car>("Toyota Camry", 2020, 25000));
    fleet.push_back(std::make_shared<Car>("Honda Civic", 2019, 22000));
    fleet.push_back(std::make_shared<Truck>("Ford F-150", 2021, 45000, 2.5));
    fleet.push_back(std::make_shared<Motorcycle>("Harley Davidson", 2018, 18000, 1200));
    
    int current_year = 2024;
    
    // TODO: Calculate total fleet value using a SINGLE loop
    float total_value = 0;
    // YOUR CODE HERE
    
    std::cout << "Total fleet value: $" << total_value << std::endl;
    
    // BONUS TODO: Sort vehicles by current value (highest to lowest)
    // Hint: use std::sort with a lambda
    
    // BONUS TODO: Print all vehicles with their current values
    
    return 0;
}