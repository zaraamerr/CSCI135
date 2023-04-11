//Zara Amer
//CS 135
//Prof Maryash
//April 10
//Project 2
//Task A: We will be making a playlist system to keep the order of songs. 
//these arrays are going to be dynamically allocated!

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//global variables
int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/

void allocateNew(){
    //creates a new integer variable called 'new_size', which is equal to the current size of the arrays
    //multiplied by 2. creating new arrays that are twice as large as the old ones.
    int new_size = g_curr_size * 2; 
    //create new arrays of strings and integers, each with 'new_size' number of elements. 
    //These will be used to store the new, larger arrays of song information.
    string *new_song_names = new string[new_size];
    string *new_artist_names = new string[new_size];
    int *new_song_durations = new int[new_size];
    string *new_genres = new string[new_size];
    //iterate over each element of the arrays containing song information.
    for (int i = 0; i < g_number_of_songs; i++) {
        //copy the contents of the old arrays into the new ones, element by element. 
        //so we don't lose any of the information we've already stored.
        new_song_names[i] = g_song_names[i];
        new_artist_names[i] = g_artist_names[i];
        new_song_durations[i] = g_song_durations[i];
        new_genres[i] = g_genres[i];
    }
    //delete the old arrays, since we don't need them anymore and want to free up memory.
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;
    //assign the new arrays of song information to the global variables that previously held the old
    //arrays. we are now using the new, larger arrays to store song information.
    g_song_names = new_song_names;
    g_artist_names = new_artist_names;
    g_song_durations = new_song_durations;
    g_genres = new_genres;
    //updates the global variable 'g_curr_size' to reflect the new size of the arrays. 
    //This is important, because other parts of the program might need to know how much space we
    //have available for storing song information.
    g_curr_size = new_size;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/

void readSongs(string filename) {
    ifstream inputFile(filename);
    string line;
    getline(inputFile, line);
    if (inputFile.is_open()) {
        do {
            // Extract the song name, artist name, duration, and genre from the line
            string songName = line.substr(0, line.find(':'));
            string artistName = line.substr(line.find(':') + 1, line.find('-') - line.find(':') - 1);
            string genre = line.substr(line.find('-') + 1, line.find('-', line.find('-') + 1) - line.find('-') - 1);
            int duration = stoi(line.substr(line.find_last_of('-') + 1, line.find("mins") - line.find_last_of('-') - 1));

            // Check if we need to allocate a larger array
            if (g_number_of_songs == g_curr_size) {
                allocateNew();
        }
        // Add the song data to the global arrays
        g_song_names[g_number_of_songs] = songName;
        g_artist_names[g_number_of_songs] = artistName;
        g_genres[g_number_of_songs] = genre;
        g_song_durations[g_number_of_songs] = duration;
        g_number_of_songs++;
        } while (getline(inputFile, line));
        inputFile.close();
    }
}

//Task B:
/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings 
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and 
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'
    
    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist 
*/
string * getGenreSongs(string genre, int &genreCount) {
    // Count the number of songs of the given genre
    genreCount = 0;
    for (int i = 1; i <= g_number_of_songs; i++) {
        //loop thru the genres array
        if (g_genres[i] == genre) {
            genreCount++;
        }
    }

    // dynamically allocate an array of strings with size equal to the number of songs found.
    string * genreSongs = new string[genreCount];

    // Populate the array with the names of the songs of the given genre
    int index = 0;
    for (int i = 1; i <= g_number_of_songs; i++) {
        if (g_genres[i] == genre) {
            genreSongs[index] = g_song_names[i];
            index++;
        }
    }

    // Return a pointer to the array of song names
    return genreSongs;
}

/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings 
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a 
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs 
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song 
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration      
*/
string * getSongsFromDuration(int duration, int &durationsCount, int filter) {
    //first allocate an array of strings of size of g_number_of_songs
    //then initialize a counter variable count to 0
    string *result = new string[g_number_of_songs];
    int count = 0;
    //loops through all songs, checking if the duration of each song matches the given filter, 
    //and if so, adds its name to the result array and increments count.
    for (int i = 0; i < g_number_of_songs; i++) {
        if ((filter == 0 && g_song_durations[i] > duration) ||
            (filter == 1 && g_song_durations[i] < duration) ||
            (filter == 2 && g_song_durations[i] == duration)) {
            result[count++] = g_song_names[i];
        }
    }
    //update the durationsCount parameter with the value of count.
    durationsCount = count;

    //if count is 0, then the result array is empty, so we need to deallocate it 
    //and return a pointer to a new empty array.
    if (count == 0) {
        delete[] result;
        result = new string[0];
    } else {
        //Otherwise, create a new array temp of size count, 
        //copy the elements of result into temp, deallocate result, and return temp
        string *temp = new string[count];
        for (int i = 0; i < count; i++) {
            temp[i] = result[i];
        }
        delete[] result;
        result = temp;
    }

    return result;
}

// int main() {
//     string filename = "songs.txt"; // replace with the actual filename
//     readSongs(filename);
//     cout << g_number_of_songs << endl;
//     // print the contents of the global arrays to verify they were filled correctly
//     for (int i = 0; i < g_number_of_songs; i++) {
//     cout << "Song " << i+1 << ": " << g_song_names[i] << " by " << g_artist_names[i] << " (" << g_song_durations[i] << " mins, " << g_genres[i] << ")" << endl;
//     }
//     int count = 0;
//     string * genreSongs = getGenreSongs("Pop", count);

//     // print out the songs found
//     cout << "Found " << count << " Pop songs:" << endl;
//     for (int i = 0; i < count; i++) {
//         cout << genreSongs[i] << endl;
//     }

//     return 0;
// }





