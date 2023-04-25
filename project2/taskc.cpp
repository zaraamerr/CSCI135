//Zara Amer
//CS 135
//Project 2 Task C
//April 17 2023

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Song {
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

/*
    @post             :   Replace the old global
                          dynamically allocated array
                          'g_songs' with new dynamically
                          allocated array of twice the 
                          capacity ('g_capacity' * 2). 
                          Update 'g_capacity' accordingly.
                          Make sure you copy the contents
                          of the old array to the new one.
*/

void allocateNew() {
    // double the current capacity
    int new_capacity = g_capacity * 2;
    // create new array with the new capacity
    Song *new_songs = new Song[new_capacity];
    // copy the contents of the old array into the new array
    for (int i = 0; i < g_size; i++) {
        new_songs[i].name = g_songs[i].name;
        new_songs[i].artist = g_songs[i].artist;
        new_songs[i].duration = g_songs[i].duration;
        new_songs[i].genre = g_songs[i].genre;
    }
    // delete the old array
    delete[] g_songs;
    // update the global pointer to point to the new array
    g_songs = new_songs;
    // update the global capacity variable
    g_capacity = new_capacity;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the 'g_songs' and sets the 
                          value of 'g_size' to the number 
                          of songs read. Call 'allocateNew()' 
                          where necessary similar to Task A.
*/
void readSongs(string filename) {
    ifstream inputFile(filename);
    string line;
    getline(inputFile, line);
    if (inputFile.is_open()) {
        do {
            // Extract the song name
            string songName = line.substr(0, line.find(':'));
            line = line.substr(line.find(':') + 1);
            // Extract the artist name
            string artistName = line.substr(0, line.find('-'));
            line = line.substr(line.find('-') + 1);
            // Extract the genre
            string genre = line.substr(0, line.find('-'));
            line = line.substr(line.find('-') + 1);
            // Extract the duration
            string durationStr = line.substr(0, line.find("mins"));
            int duration = stoi(durationStr);
            // Check if we need to allocate a larger array
            if (g_size == g_capacity) {
                allocateNew();
            }
            // Add the song data to the global array
            g_songs[g_size].name = songName;
            g_songs[g_size].artist = artistName;
            g_songs[g_size].genre = genre;
            g_songs[g_size].duration = duration;
            g_size++;
        } while (getline(inputFile, line));
        inputFile.close();
    }
}

// Now returns a dynamic array of 'Song' objects instead of a 'string' objects
Song * getSongsFromDuration(int duration, int &durationsCount, int filter){
    // Create a dynamic array of 'Song' objects
    Song *songs = new Song[g_capacity];
    // Keep track of the number of songs that match the duration
    int count = 0;
    // Loop through the global array of songs
    for (int i = 0; i < g_size; i++) {
        // Check if the song duration matches the filter
        if (filter == 0 && g_songs[i].duration > duration) {
            // Add the song to the dynamic array
            songs[count].name = g_songs[i].name;
            songs[count].artist = g_songs[i].artist;
            songs[count].duration = g_songs[i].duration;
            songs[count].genre = g_songs[i].genre;
            count++;
        } else if (filter == 1 && g_songs[i].duration < duration) {
            // Add the song to the dynamic array
            songs[count].name = g_songs[i].name;
            songs[count].artist = g_songs[i].artist;
            songs[count].duration = g_songs[i].duration;
            songs[count].genre = g_songs[i].genre;
            count++;
        } else if (filter == 2 && g_songs[i].duration == duration) {
            // Add the song to the dynamic array
            songs[count].name = g_songs[i].name;
            songs[count].artist = g_songs[i].artist;
            songs[count].duration = g_songs[i].duration;
            songs[count].genre = g_songs[i].genre;
            count++;
        }
    }
    // Update the count of songs that match the duration
    durationsCount = count;
    // Return the dynamic array of 'Song' objects
    return songs;
    
}

Song * getGenreSongs(string genre, int &genreCount){
    // Create a dynamic array of 'Song' objects
    Song *songs = new Song[g_capacity];
    // Keep track of the number of songs that match the genre
    int count = 0;
    // Loop through the global array of songs
    for (int i = 0; i < g_size; i++) {
        // Check if the song genre matches the filter
        if (g_songs[i].genre == genre) {
            // Add the song to the dynamic array
            songs[count].name = g_songs[i].name;
            songs[count].artist = g_songs[i].artist;
            songs[count].duration = g_songs[i].duration;
            songs[count].genre = g_songs[i].genre;
            count++;
        }
    }
    // Update the count of songs that match the genre
    genreCount = count;
    // Return the dynamic array of 'Song' objects
    return songs;
  
}

// Change the implementation since we are using 'Song' class
string * getUniqueArtists(int &uniqueCount){
    // Create a dynamic array of 'string' objects
    string *artists = new string[g_capacity];
    // Keep track of the number of unique artists
    int count = 0;
    // Loop through the global array of songs
    for (int i = 0; i < g_size; i++) {
        // Check if the artist is already in the array
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (artists[j] == g_songs[i].artist) {
                found = true;
                break;
            }
        }
        // If the artist is not in the array, add it
        if (!found) {
            artists[count] = g_songs[i].artist;
            count++;
        }
    }
    // Update the count of unique artists
    uniqueCount = count;
    // Return the dynamic array of 'string' objects
    return artists;
   
}

string getFavoriteArtist(){
    // Create a dynamic array of 'string' objects
    string *artists = new string[g_capacity];
    // Create a dynamic array of 'int' objects
    int *counts = new int[g_capacity];
    // Keep track of the number of unique artists
    int count = 0;
    // Loop through the global array of songs
    for (int i = 0; i < g_size; i++) {
        // Check if the artist is already in the array
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (artists[j] == g_songs[i].artist) {
                found = true;
                counts[j]++;
                break;
            }
        }
        // If the artist is not in the array, add it
        if (!found) {
            artists[count] = g_songs[i].artist;
            counts[count] = 1;
            count++;
        }
    }
    // Find the artist with the most songs
    int max = 0;
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (counts[i] > max) {
            max = counts[i];
            index = i;
        }
    }
    // Return the artist with the most songs
    return artists[index];
   
}