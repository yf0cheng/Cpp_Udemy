// Section 19
// Challenge 1
// Formatting output
/*
Section 19 
Challenge 1 

Formatting output
===========================================================
I have provided you with the starter source code for this challenge.
In this challenge you are to display the provided data in a nicely formatted table.
Your table does not have to match mine, but practice with the format manipulators
so you become comfortable with them.

There are 3 structures provided. Yes, these could also be classes with public data, 
but it's common to use structures when we simply want to model only data and not 
operations as we would with classes.

The structures work together to create a Tours structure that will contain
information about Tours to South America.
The Tours include Countries, Cities within those countries along with population and cost data for 
each city tour.
I know, population? Huh? I just wanted a big number so that you can format it, OK :)

Please watch the Challenge video for the expected output. It won't look right if I put it in this
editor because of the font style.

In the provided source code I'm giving you some code that displays the data from the structures 
and the vectors within the structures. This code uses tabs to format the data and it looks pretty ugly.

Have fun!! Create functions if you like, use constants, whatever you think makes sense!

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;

    // Unformatted display so you can see how to access the vector elements
    std::cout << std::setw(21) << std::left << tours.title << std::endl;
    std::cout << "------------------------------------------------------------------------------------------" <<std::endl;
    for(auto country : tours.countries) {   // loop through the countries
        for(size_t i = 0; i< country.cities.size(); i++) {       // loop through the cities for each country
                std::cout << std::setw(20) << std::left<< (i==0? country.name : "");
                std::cout << std::setw(20)  << std::left  << country.cities.at(i).name 
                                << std::setw(15) << std::right << country.cities.at(i).population 
                                << std::setw(15) << std::right << std::setprecision(2) << std::fixed << country.cities.at(i).cost 
                                << std::endl;
        }
    }
    
    std::cout << std::endl << std::endl;
    return 0;
}