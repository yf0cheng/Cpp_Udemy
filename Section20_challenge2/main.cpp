/*
Section 20
Challenge 2
Using std::list

In this challenge you will create a menu driven application that
will simulate a user playing songs from a playlist of songs.

We will use a list to simulate the user selecting the the first song in the playlist and
then selecting next and previous to play forward of backwards through the 
playlist.

Please refer to the video demo run.

We will also allow users to add new song to the playlist and they
will be added prior to the currently playing song.
The menu looks as follows:

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
========================
Enter a selection (Q to quit):

And the available playlist is modeled as a std::list<Song>
I will provide the Song class. Following are the songs in the playlist.
I grabbed these from the pop charts, you can use them or change 
them to any songs you wish.

God's Plan                  Drake                                       5
Never Be The Same   Camila Cabello                         5
Pray For Me               The Weekend and K. Lamar      4
The Middle                Zedd, Maren Morris & Grey     5
Wait                           Maroone 5                                4
Whatever It Takes      Imagine Dragons                      3

I have provided the starting project.
Have fun!

Note:
If you have trouble reading input, you can clear std::cin and 
ignore everything in the buffer with:

std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

Make sure you #include <limits> to use it.

*/
// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Current playing: \n" << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (auto s: playlist)
        std::cout << s << std::endl;
    play_current_song(current_song);
}
void optionA( std::list<Song> &playlist, const Song &current_song){
    std::string name, artist;
    int rating;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Enter song name:" ;
    std::getline(std::cin , name);
    std::cout << "Enter the artist:";
    std::getline(std::cin , artist);
    std::cout << "Enter the rating:";
    std::cin >> rating;
    auto current_itr = std::find(playlist.begin(),playlist.end(), current_song);
    playlist.insert(current_itr, Song{name,artist,rating});
//    play_current_song(*current_itr);
    current_itr--;
    play_current_song(*current_itr);
}
int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
//    play_current_song(*current_song);
//    display_playlist(playlist, *current_song);
    std::cout << "To be implemented" << std::endl;
    // Your program logic goes here
    char choice;
    do {
        display_menu();
        std::cin >> choice;
        choice = toupper(choice);
        switch(choice){
            case 'F': 
                current_song = playlist.begin(); 
                play_current_song(*current_song);
                break;
            case 'N': 
                if (current_song == --playlist.end())
                    current_song = playlist.begin();
                else
                    current_song++;
                play_current_song(*current_song);
                break;
            case 'P':
                if (current_song == playlist.begin())
                    current_song = --playlist.end();
                else
                    current_song--;
                play_current_song(*current_song);
                break;
            case 'A':
                optionA(playlist, *current_song);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            case 'Q':
                break;
            default:
                std::cout<< "Unknow option" <<std::endl;
                break;
        }
    } while (choice !='Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}