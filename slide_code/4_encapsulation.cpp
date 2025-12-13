/*
    please refer to exercise 1 for the first
    example of encapsulation
    ----------------------------------------------------------------
*/

#include <string>
#include <stdexcept>

// example for encapsulation with validation
class Car
{
public:
    Car(std::string model,int year_made, float original_price)
    {
        // validate input values from users:
        if(year_made < 1886)
        {
            std::invalid_argument("Cannot enter a car's year made before 1886.");
        }
        if(original_price < 0)
        {
            std::invalid_argument("Car price cannot be negative.");
        }
        
        model_ = model;
        year_made_ = year_made;
        original_price_ = original_price;
        
    }

    void SetInitialCarPrice(float value)
    {
        if(value < 0 )
        {
            throw std::invalid_argument("Car price cannot be negative.");
        }

    }

private:
std::string model_;
int year_made_;
float original_price_;

};


// Example with read only access:
class Car
{
public:
    Car(std::string model,int year_made, float original_price)
    {
        model_ = model;
        year_made_ = year_made;
        original_price_ = original_price;
        
    }

    std::string GetModel() const {return model_;}
    int GetYearMade() const {return year_made_;}
    float GetOriginalPrice() const {return original_price_;}
    
private:
std::string model_;
int year_made_;
float original_price_;

};


// example with computed properties
#include<cmath>
class Car
{
public:
    Car(std::string model,int year_made, float original_price)
    {
        model_ = model;
        year_made_ = year_made;
        original_price_ = original_price;
        
    }

    // as a user of this class I don't need to know or implement myself this 
    // buisness logic I can just use it directly
    int GetCarAge()
    {
        return 2025 - year_made_;
    }

    float GetCurrentValue()
    {
        return original_price_ * std::pow(1-depreciation_rate_,GetCarAge());
    }
    
private:
std::string model_;
int year_made_;
float original_price_;
const float depreciation_rate_ = 0.05;

};

