#pragma once
#include <bits/stdc++.h>
#include "./Movie.cpp"
#include "./Seat.cpp"
using namespace std;

class Show {
private:
    int showId;
    Movie movie;
    time_t showTime;  // C++ has no LocalDateTime, so time_t is used
    vector<Seat> seats;

public:
    Show(int showId, Movie movie, time_t showTime, vector<Seat> seats)
        : showId(showId), movie(movie), showTime(showTime), seats(seats) {}

    int getShowId() { return showId; }
    Movie getMovie() { return movie; }
    time_t getShowTime() { return showTime; }

    vector<Seat> getAvailableSeats() {
        vector<Seat> availableSeats;
        for (auto& seat : seats) {
            if (seat.isAvailable()) availableSeats.push_back(seat);
        }
        return availableSeats;
    }

    // Books all seats or none
    bool bookSeat(vector<int> seatIds) {
        // Step 1: check every requested seat exists and is available
        for (int seatId : seatIds) {
            bool found = false;
            for (auto& seat : seats) {
                if (seat.getSeatId() == seatId) {
                    if (!seat.isAvailable()) return false;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        // Step 2: book them
        for (int seatId : seatIds) {
            for (auto& seat : seats) {
                if (seat.getSeatId() == seatId) seat.book();
            }
        }
        return true;
    }
};