#pragma once
#include <bits/stdc++.h>
#include "./SeatType.cpp"
#include "./SeatStatus.cpp"
using namespace std;

class Seat {
private:
    int seatId;
    SeatType seatType;
    SeatStatus seatStatus;

public:
    Seat(int seatId, SeatType seatType, SeatStatus seatStatus)
        : seatId(seatId), seatType(seatType), seatStatus(seatStatus) {}

    int getSeatId() { return seatId; }
    SeatType getSeatType() { return seatType; }
    SeatStatus getSeatStatus() { return seatStatus; }
    bool isAvailable() { return seatStatus == SeatStatus::AVAILABLE; }
    void book() { seatStatus = SeatStatus::BOOKED; }
};