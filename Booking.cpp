#pragma once
#include <bits/stdc++.h>
#include "./Show.cpp"
using namespace std;

class Booking {
private:
    int bookingId;
    Show show;
    vector<int> seatIds;
    time_t bookingTime;

public:
    Booking(int bookingId, Show show, vector<int> seatIds, time_t bookingTime)
        : bookingId(bookingId), show(show), seatIds(seatIds), bookingTime(bookingTime) {}

    int getBookingId() { return bookingId; }
    Show getShow() { return show; }
    vector<int> getSeatIds() { return seatIds; }
    time_t getBookingTime() { return bookingTime; }
};