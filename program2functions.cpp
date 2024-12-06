#include "program2functions.h"

bool LeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int LastDayOfMonth(int month, int year) {
    // Check for invalid month and return 0
    if (month < 1 || month > 12) {
        return 0;  // Return 0 for invalid months
    }

    // Handle February separately if year is missing (year == 0)
    if (month == 2) {
        if (year == 0) {
            return 0;  
        }
        return LeapYear(year) ? 29 : 28;
    }

    // Handle other months
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 0;  
    }
}

bool ValidDate(int month, int day, int year) {
    if (month < 1 || month > 12 || day < 1 || year < 1)
        return false;

    int lastDay = LastDayOfMonth(month, year);
    return day <= lastDay && lastDay != -1;
}

void NextDate(int &month, int &day, int &year) {
    if (!ValidDate(month, day, year)) return;

    day++;
    if (day > LastDayOfMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void PreviousDate(int &month, int &day, int &year) {
    if (!ValidDate(month, day, year)) return;

    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = LastDayOfMonth(month, year);
    }
}
