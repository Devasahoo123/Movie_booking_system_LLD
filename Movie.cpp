#pragma once
#include <bits/stdc++.h>
using namespace std;

class Movie {
private:
    string title;
    int movieId;
    int duration;
    string genre;

public:
    Movie(string title, int movieId, int duration, string genre)
        : title(title), movieId(movieId), duration(duration), genre(genre) {}

    string getTitle() { return title; }
    int getMovieId() { return movieId; }
    int getDuration() { return duration; }
    string getGenre() { return genre; }
};