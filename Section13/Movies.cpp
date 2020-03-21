#include "Movies.h"
#include <iostream>
#include <vector>

Movies::Movies(){
    std::cout << "Constructor for Movies" << std::endl;
}

Movies::~Movies(){
    std::cout << "Distructor for Movies" << std::endl;
}

// member methods

// 
// move out find loops
Movie * find_movie(std::string name, std::vector<Movie> *movies){
    for (Movie &m:*movies){ // doesn't want to change m, so use const
        if (m.get_name() == name){
            return &m;
        }
    }
//    int * null_ptr {nullptr};
    return nullptr;
}

bool Movies::add_movie(std::string name,  std::string rating,  int watched){
    if (find_movie(name, &movies)==nullptr){
        Movie temp {name, rating, watched};
        movies.push_back(temp);
        return true;
    } else{
        return false;
    }
}

bool Movies::increment_watched(std::string name){
    Movie * m_ptr {find_movie(name, &movies)};
    if (m_ptr==nullptr){
        return false;
    } else{
        (*m_ptr).increment_watched();
        return true;
    }
}



//    // repeat find loops
//bool Movies::add_movie(std::string name,  std::string rating,  int watched){
//    for (const auto m:movies){ // doesn't want to change m, so use const
//        if (m.get_name() == name){
//            return false;
//        }
//    }
//    
//    Movie temp {name, rating, watched};
//    movies.push_back(temp);
//    return true;
//}
//
//bool Movies::increment_watched(std::string name){
//    for (auto &m:movies){ // want to upate the result so pass by reference
//        if (m.get_name() == name){
//            m.increment_watched();
//            return true;
//        }
//    }
//    return false;
//}




void Movies::display() const{
    if (movies.size()==0){
        std::cout << "movie list is empty" << std::endl;
    } else{
        std::cout << "======================" << std::endl;
        for (const auto &m:movies){
            m.display();
        }
        std::cout << "======================" << std::endl;
    }
}