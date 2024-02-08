
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

class MovieTicketBookingSystem {
private:
    vector<vector<bool>> seats;
    vector<string> movieList;
    double ticketPrice;

public:
    MovieTicketBookingSystem() {
        // Initialize all seats as available
        seats.resize(NUM_ROWS, vector<bool>(NUM_COLS, true));

        // Populate movie list
        movieList = {"Movie 1", "Movie 2", "Movie 3"};

        // Set ticket price
        ticketPrice = 10.0;
    }

    void displayMovieList() {
        cout << "Movie Listings:" << endl;
        for (int i = 0; i < movieList.size(); ++i) {
            cout << i + 1 << ". " << movieList[i] << endl;
        }
    }

    void displaySeatingPlan() {
        cout << "Seating Plan:" << endl;
        for (int i = 0; i < NUM_ROWS; ++i) {
            cout << "Row " << setw(2) << i + 1 << ": ";
            for (int j = 0; j < NUM_COLS; ++j) {
                if (seats[i][j]) {
                    cout << "O ";
                } else {
                    cout << "X ";
                }
            }
            cout << endl;
        }
    }

    bool isValidSeat(int row, int col) {
        return row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col];
    }

    double bookTicket(int movieIndex, int row, int col, int numTickets) {
        if (movieIndex < 1 || movieIndex > movieList.size()) {
            cout << "Invalid movie selection!" << endl;
            return -1.0;
        }

        if (!isValidSeat(row, col)) {
            cout << "Invalid seat selection!" << endl;
            return -1.0;
        }

        double totalCost = numTickets * ticketPrice;
        cout << "Booking confirmed for " << movieList[movieIndex - 1] << ", Row " << row + 1 << ", Seat " << col + 1 << ". Total cost: $" << fixed << setprecision(2) << totalCost << endl;
        
        // Update seat status
        for (int i = 0; i < numTickets; ++i) {
            seats[row][col + i] = false;
        }
        
        return totalCost;
    }
};

int main() {
    MovieTicketBookingSystem bookingSystem;

    // Display movie listings
    bookingSystem.displayMovieList();

    // Display seating plan
    bookingSystem.displaySeatingPlan();

    // Make a booking
    int movieIndex, row, col, numTickets;
    cout << "Enter movie number: ";
    cin >> movieIndex;
    cout << "Enter row and starting seat number (e.g., 1 2): ";
    cin >> row >> col;
    cout << "Enter number of tickets: ";
    cin >> numTickets;

    bookingSystem.bookTicket(movieIndex, row - 1, col - 1, numTickets);

    return 0;
}
