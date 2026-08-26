#include <bits/stdc++.h>
using namespace std;
class HotelRoom {
    int roomNumber;
    double price;
    bool available;
    static int totalAvailable; 
public:
    HotelRoom(int num, double p, bool isAvailable = true) {
        roomNumber = num;
        price = p;
        available = isAvailable;
        if (available)
            totalAvailable++;
        cout << "Room " << roomNumber << " created. Available rooms: " << totalAvailable << endl;
    }
    void bookRoom() {
        if (available) {
            available = false;
            totalAvailable--;
            cout << "Room " << roomNumber << " booked. Available rooms: " << totalAvailable << endl;
        } else {
            cout << "Room " << roomNumber << " is already booked!" << endl;
        }
    }
    void freeRoom() {
        if (!available) {
            available = true;
            totalAvailable++;
            cout << "Room " << roomNumber << " is now free. Available rooms: " << totalAvailable << endl;
        } else {
            cout << "Room " << roomNumber << " is already free!" << endl;
        }
    }
    void showInfo() {
        cout << "Room " << roomNumber
             << " | Price: $" << price
             << " | " << (available ? "Available" : "Booked") << endl;
    }
    ~HotelRoom() {
        if (available)
            totalAvailable--;
        cout << "Room " << roomNumber << " removed. Available rooms: " << totalAvailable << endl;
    }
};
int HotelRoom::totalAvailable = 0;
int main() {
    HotelRoom r1(101, 2500.0);
    HotelRoom r2(102, 2000.0);
    HotelRoom r3(103, 3000.0, false);
    r1.showInfo();
    r2.showInfo();
    r3.showInfo();
    r2.bookRoom();
    r3.freeRoom();
    r1.showInfo();
    r2.showInfo();
    r3.showInfo();
    return 0;
}
