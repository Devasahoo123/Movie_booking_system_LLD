#pragma once
#include <bits/stdc++.h>
#include "./City.cpp"
#include "./Booking.cpp"
using namespace std;

class BookingService {
private:
    static BookingService* instance;  // inline: no separate definition needed
    BookingService() {}

    vector<City> cities;
    int bookingIdCounter = 1;

public:
    static BookingService* getInstance() {
        if (instance == nullptr) {
            instance = new BookingService();
        }
        return instance;
    }

    void addCity(City city) { cities.push_back(city); }

    vector<City>& getCities() { return cities; }

    vector<Movie> getMoviesByCity(string cityName) {
        vector<Movie> movies;
        for (auto& city : cities) {
            if (city.getName() == cityName) {
                for (auto& theater : city.getTheaters()) {
                    for (auto& screen : theater.getScreens()) {
                        for (auto& show : screen.getShows()) {
                            movies.push_back(show.getMovie());
                        }
                    }
                }
            }
        }
        return movies;
    }

    // Show is taken by reference so the real show's seats get updated
    Booking bookTicket(Show& show, vector<int> seatIds) {
        if (show.bookSeat(seatIds)) {
            return Booking(bookingIdCounter++, show, seatIds, time(nullptr));
        }
        throw runtime_error("Seats not available");
    }
};
BookingService* BookingService::instance = nullptr;