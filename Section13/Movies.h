#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <string>
#include "Movie.h"

class Movies
{

private:
    std::vector<Movie> movies; // delcare vector with Movie objects in the entries, name the vector as movies
public:
    Movies(); // constructor
    ~Movies(); // disctructor
    //prototypes below
    bool add_movie(std::string name,  std::string rating,  int watched); 
    bool increment_watched(std::string name); 
    void display() const; // const tell compiler that this function won't change the object

};

#endif // _MOVIES_H_
