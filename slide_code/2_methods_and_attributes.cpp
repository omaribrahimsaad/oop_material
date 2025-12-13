#include <string>
#include <iostream>

class Car
{
public:
    std::string GetCarModel() {return model_;}
    int GetYearMade(){return year_made_;}

private:
    std::string model_ = "model";
    int year_made_ = 2001;  

};

int main()
{
    Car new_car; // not able to intialize the data

    auto new_car_model = new_car.GetCarModel(); // returns an empty string

    int new_car_year_made = new_car.GetYearMade();; // returns garbage data if we didn't initalize

    std::cout << "The new car model is: " << new_car_model << '\n';
    std::cout << "The new car year made is: " << new_car_year_made << '\n';
    
}