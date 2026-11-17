#pragma once
#include <bits/stdc++.h>
#include "./Screen.cpp"
using namespace std;

class Theater {
private:
    string name;
    vector<Screen> screens;

public:
    Theater(string name, vector<Screen> screens) : name(name), screens(screens) {}

    string getName() { return name; }
    vector<Screen>& getScreens() { return screens; }
    void addScreen(Screen screen) { screens.push_back(screen); }
};