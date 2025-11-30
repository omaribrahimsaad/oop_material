#include <iostream>
#include <vector>
#include <string>

struct Car {
    std::string model;
    int year_made;
    float initial_value;
};

struct Truck {
    std::string model;
    int year_made;
    float initial_value;
    float cargo_capacity;
};

struct Motorcycle {
    std::string model;
    int year_made;
    float initial_value;
    int engine_cc;
};

// TODO: Implement these functions
float CalculateCarDepreciation(const Car& car, int current_year) {
    // Cars depreciate at 5% per year
    // YOUR CODE HERE
}

float CalculateTruckDepreciation(const Truck& truck, int current_year) {
    // Trucks depreciate at 7% per year
    // YOUR CODE HERE
}

float CalculateMotorcycleDepreciation(const Motorcycle& motorcycle, int current_year) {
    // Motorcycles depreciate at 10% per year
    // YOUR CODE HERE
}

int main() {
    // Create a fleet
    std::vector<Car> cars = {
        {"Toyota Camry", 2020, 25000},
        {"Honda Civic", 2019, 22000}
    };
    
    std::vector<Truck> trucks = {
        {"Ford F-150", 2021, 45000, 2.5}
    };
    
    std::vector<Motorcycle> motorcycles = {
        {"Harley Davidson", 2018, 18000, 1200}
    };
    
    // TODO: Calculate total fleet value for year 2024
    // This is painful! You need separate loops for each type...
    float total_value = 0;
    
    // YOUR CODE HERE - calculate total for all vehicles
    
    std::cout << "Total fleet value: $" << total_value << std::endl;
    
    return 0;
}