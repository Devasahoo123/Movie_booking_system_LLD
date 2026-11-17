#pragma once
#include <bits/stdc++.h>
#include "./Show.cpp"
using namespace std;

class Screen {
private:
    int screenId;
    vector<Show> shows;

public:
    Screen(int screenId, vector<Show> shows) : screenId(screenId), shows(shows) {}

    int getScreenId() { return screenId; }
    vector<Show>& getShows() { return shows; }  // reference so changes persist
    void addShow(Show show) { shows.push_back(show); }
};