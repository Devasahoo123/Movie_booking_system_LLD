#include <bits/stdc++.h>
#include "./BookingService.cpp"
using namespace std;

int main() {
    BookingService* service = BookingService::getInstance();

    // Movie
    Movie movie("Inception", 1, 148, "Sci-Fi");

    // Seats
    vector<Seat> seats;
    seats.push_back(Seat(1, SeatType::REGULAR, SeatStatus::AVAILABLE));
    seats.push_back(Seat(2, SeatType::REGULAR, SeatStatus::AVAILABLE));
    seats.push_back(Seat(3, SeatType::PREMIUM, SeatStatus::AVAILABLE));
    seats.push_back(Seat(4, SeatType::RECLINER, SeatStatus::AVAILABLE));

    // Show -> Screen -> Theater -> City
    Show show(101, movie, time(nullptr), seats);
    Screen screen(1, {});
    screen.addShow(show);

    Theater theater("PVR Cinemas", {});
    theater.addScreen(screen);

    City city("Ghaziabad", {});
    city.addTheater(theater);

    service->addCity(city);

    // Movies in city
    cout << "Movies in Ghaziabad:\n";
    for (auto& m : service->getMoviesByCity("Ghaziabad")) {
        cout << " - " << m.getTitle() << " (" << m.getDuration() << " min, " << m.getGenre() << ")\n";
    }

    // Get the real show stored inside the service
    Show& realShow = service->getCities()[0].getTheaters()[0].getScreens()[0].getShows()[0];

    cout << "\nAvailable seats before booking: " << realShow.getAvailableSeats().size() << "\n";

    // Booking 1: should succeed
    try {
        Booking b1 = service->bookTicket(realShow, {1, 2});
        time_t t = b1.getBookingTime();
        cout << "\nBooking successful! ID: " << b1.getBookingId() << ", Seats: ";
        for (int id : b1.getSeatIds()) cout << id << " ";
        cout << "\nTime: " << ctime(&t);
    } catch (exception& e) {
        cout << "Booking 1 failed: " << e.what() << "\n";
    }

    cout << "Available seats after booking: " << realShow.getAvailableSeats().size() << "\n";

    // Booking 2: seat 2 already booked, should fail
    try {
        Booking b2 = service->bookTicket(realShow, {2, 3});
        cout << "Booking 2 successful! ID: " << b2.getBookingId() << "\n";
    } catch (exception& e) {
        cout << "\nBooking 2 failed: " << e.what() << "\n";
    }

    // Booking 3: free seats, should succeed
    try {
        Booking b3 = service->bookTicket(realShow, {3, 4});
        cout << "Booking 3 successful! ID: " << b3.getBookingId() << "\n";
    } catch (exception& e) {
        cout << "Booking 3 failed: " << e.what() << "\n";
    }

    cout << "Available seats at end: " << realShow.getAvailableSeats().size() << "\n";
    return 0;
}