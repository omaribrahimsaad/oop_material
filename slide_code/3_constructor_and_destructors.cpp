#include <string>
#include <iostream>

class Car
{
public:
    // constructors are special methods that help us to 
    // initialize our classes using any data.
    Car(std::string model,int year_made)
    {
        model_ = model;
        year_made_ = year_made;
    }
    
    // destructor is also a special method that runs when an instance
    // of this class is destoyed. it is used mainly to clean up resources.
    ~Car()
    {
        
    }

    std::string GetCarModel(){return model_;}
    int GetYearMade() {return year_made_;}
    
private:
    std::string model_;
    int year_made_;

};


int main()
{
    // if we defined a constructor in the class we cannot 
    // just construct and empty object like this:
    /*
        Car new_car; 
    */

    Car new_car("toyota",2001); 
    auto new_car_model = new_car.GetCarModel(); // returns an empty string

    int new_car_year_made = new_car.GetYearMade();; // returns garbage data if we didn't initalize

    std::cout << "The new car model is: " << new_car_model << '\n';
    std::cout << "The new car year made is: " << new_car_year_made << '\n';
    
}
