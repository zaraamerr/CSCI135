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
    // count how many songs match the genre
    genreCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        if (g_genres[i] == genre) {
            genreCount++;
        }
    }

    // if there are no matching songs, return an empty array
    if (genreCount == 0) {
        return new string[g_number_of_songs];
    }

    // allocate an array to hold the matching song names
    string * genreSongs = new string[g_number_of_songs];

    // fill the array with the names of the matching songs
    int j = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        if (g_genres[i] == genre) {
            genreSongs[j] = g_song_names[i];
            j++;
        }
    }

    // return the array
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
string * getSongsFromDuration(int duration, int &durationsCount, int filter){
    string *durationSongs = new string[g_number_of_songs];
    int index = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        if ((filter == 0 && g_song_durations[i] > duration) ||
            (filter == 1 && g_song_durations[i] < duration) ||
            (filter == 2 && g_song_durations[i] == duration)) {
            durationSongs[index++] = g_song_names[i];
        }
    }
    durationsCount = index;
    if (durationsCount == 0) {
        delete[] durationSongs;
        durationSongs = new string[g_number_of_songs];
    }
    return durationSongs;
}

/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings 
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist     
*/
string * getUniqueArtists(int &uniqueCount) {
    // Create a temporary array to store unique artists
    string *uniqueArtists = new string[g_number_of_songs];

    // Loop through all the songs and add unique artists to the temporary array
    int index = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (g_artist_names[i] == g_artist_names[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArtists[index] = g_artist_names[i];
            index++;
        }
    }

    // Update uniqueCount parameter with the number of unique artists found
    uniqueCount = index;

    // Create a new array to store the unique artists without any empty slots
    string *result = new string[g_number_of_songs];
    for (int i = 0; i < index; i++) {
        result[i] = uniqueArtists[i];
    }

    // Deallocate the temporary array
    delete[] uniqueArtists;

    return result;
}

/* 
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any 
                  other artists in the playlist
*/
string getFavoriteArtist() {
    if (g_number_of_songs == 0) {
        return "NONE";
    }
    string uniqueArtists[g_number_of_songs];
    int artistCount[g_number_of_songs] = {0};
    int uniqueCount = 0;
    int maxCount = 0;
    string maxArtist = "";
    for (int i = 0; i < g_number_of_songs; i++) {
        string artist = g_artist_names[i];
        bool found = false;
        // check if the artist is already in the uniqueArtists array
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueArtists[j] == artist) {
                found = true;
                artistCount[j]++;
                if (artistCount[j] > maxCount) {
                    maxCount = artistCount[j];
                    maxArtist = artist;
                }
                break;
            }
        }
        // if artist is not found in uniqueArtists, add it to the array
        if (!found) {
            uniqueArtists[uniqueCount] = artist;
            artistCount[uniqueCount]++;
            if (artistCount[uniqueCount] > maxCount) {
                maxCount = artistCount[uniqueCount];
                maxArtist = artist;
            }
            uniqueCount++;
        }
    }
    return maxArtist;
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
//     // // Test getSongsFromDuration with different filters and durations
//     // int greater = 0, less = 0, equal = 0;
//     // string* longSongs = getSongsFromDuration(4, greater, 0);
//     // string* shortSongs = getSongsFromDuration(2, less, 1);
//     // string* mediumSongs = getSongsFromDuration(3, equal, 2);

//     // // Print results
//     // cout << "Songs greater than 4 minutes:" << endl;
//     // for (int i = 0; i < greater; i++) {
//     //     cout << longSongs[i] << endl;
//     // }
//     // cout << "Total count: " << greater << endl;

//     // cout << "Songs less than 2 minutes:" << endl;
//     // for (int i = 0; i < less; i++) {
//     //     cout << shortSongs[i] << endl;
//     // }
//     // cout << "Total count: " << less << endl;

//     // cout << "Songs equal to 3 minutes:" << endl;
//     // for (int i = 0; i < equal; i++) {
//     //     cout << mediumSongs[i] << endl;
//     // }
//     // cout << "Total count: " << equal << endl;

//     // // Test getUniqueArtists
//     // int uniqueCount = 0;
//     // string* uniqueArtists = getUniqueArtists(uniqueCount);

// }





