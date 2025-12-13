#include <string>
#include <cmath>
#include <iostream>

class Vehicle
{
public:
    Vehicle(std::string model,int year_made,float original_price)
    {
        model_ = model;
        year_made_ = year_made;
        original_price_ = original_price;
    }

    virtual float CalculateVehiclePrice(int year) = 0;


// we set the members as protected so that the derived class can access
    std::string model_;
    int year_made_;
    float original_price_;
};

class FuelCar : public Vehicle
{
public:
    FuelCar(std::string model,int year_made,float original_price)
    // for inherited classes we must initilalize the base class in the initilizer list
    : Vehicle(model, year_made, original_price) 
    {
    }

    float CalculateVehiclePrice(int year)
    {
        return original_price_*std::pow(0.95,year-year_made_);
    }

    std::string GetVehicleType()
    {
        return "FuelCar";
    }

};

class ElectricCar : public Vehicle
{
public:
    ElectricCar(std::string model,int year_made,float original_price)
        : Vehicle(model,year_made,original_price)
    {

    }

    float CalculateVehiclePrice(int year)
    {
        float age = year - year_made_;
        float battery_factor = 1 - (age* 0.02);
        return original_price_*std::pow(0.92,age) * battery_factor;
    }

    std::string GetVehicleType()
    {
        return "ElectricCar";
    }
    
};


int main()
{
    // non-polymorphic approach
    std::cout << "=== Non-Polymorphic Approach ===\n";
    FuelCar fuel_car("Toyota Camry", 2020, 30000.0f);
    ElectricCar electric_car("Tesla Model 3", 2020, 45000.0f);
    
    // Need to handle each type separately - repetitive!
    std::cout << fuel_car.GetVehicleType() << " (" << fuel_car.model_ << ")\n";
    std::cout << "2024 Price: RM " << fuel_car.CalculateVehiclePrice(2024) << "\n\n";
    
    std::cout << electric_car.GetVehicleType() << " (" << electric_car.model_ << ")\n";
    std::cout << "2024 Price: RM " << electric_car.CalculateVehiclePrice(2024) << "\n\n";
    
    
    // polymorphic approach (need to make less calls)
    std::cout << "=== Polymorphic Approach ===\n";
    // Store different vehicle types in a single array using base class pointers
    Vehicle* vehicles[] = {
        new FuelCar("Honda Civic", 2020, 25000.0f),
        new ElectricCar("Nissan Leaf", 2020, 35000.0f),
        new FuelCar("BMW 320i", 2019, 50000.0f),
        new ElectricCar("BYD Atto 3", 2021, 40000.0f)
    };
    
    // Single loop handles ALL vehicle types - much cleaner!
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Vehicle " << (i+1) << ":\n";
        std::cout << "  2024 Price: RM " << vehicles[i]->CalculateVehiclePrice(2024) << "\n";
        std::cout << "  2025 Price: RM " << vehicles[i]->CalculateVehiclePrice(2025) << "\n\n";
    }
    
    // Clean up memory
    for (int i = 0; i < 4; i++)
    {
        delete vehicles[i];
    }
    
    /* Key Benefits Students Should Notice:
     * 1. One loop processes different vehicle types (FuelCar & ElectricCar)
     * 2. Each calls the CORRECT CalculateVehiclePrice() automatically
     * 3. Easy to add new vehicle types (e.g., HybridCar) without changing the loop
     * 4. Real-world use: Plugin systems, game entities, UI components, etc.
     */
    
    return 0;
}