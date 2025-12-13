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


// we set the members as protected so that the derived class can access
protected:
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

    float CalculateFuelCarPrice(int year)
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

    float CalculateElectricCarPrice(int year)
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
    // We can use the derived class like a normal class:
    float original_price = 20000;
    ElectricCar electric_car("BYD",2003,original_price);

    int year_to_calculate = 2020;
    std::cout << "The car will be worth " << electric_car.CalculateElectricCarPrice(2020);
    std::cout << " in " << year_to_calculate;

    float original_price = 30000;
    FuelCar fuel_car("Honda",2003,original_price);

    year_to_calculate = 2020;
    std::cout << "The car will be worth " << fuel_car.CalculateFuelCarPrice(2020);
    std::cout << " in " << year_to_calculate;

    // but now if I need to make many fuel cars and many electric cars I need call 2 different functions
    // this will become hard to maintain eventually when add more type. this is why we should use
    // polymorphism.
}