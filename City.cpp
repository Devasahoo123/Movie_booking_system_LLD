#pragma once
#include <bits/stdc++.h>
#include "./Theater.cpp"
using namespace std;

class City {
private:
    string name;
    vector<Theater> theaters;

public:
    City(string name, vector<Theater> theaters) : name(name), theaters(theaters) {}

    string getName() { return name; }
    vector<Theater>& getTheaters() { return theaters; }
    void addTheater(Theater theater) { theaters.push_back(theater); }
};