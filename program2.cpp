#include <iostream>
#include "program2functions.h"

using namespace std;

int CalculateDaysDifference(int m1, int d1, int y1, int m2, int d2, int y2) {
    int count = 0;
    
    if (!ValidDate(m1, d1, y1)) {
        cout << m1 << "/" << d1 << "/" << y1 << " is not a valid date" << endl;
        return -1;
    }

    if (!ValidDate(m2, d2, y2)) {
        cout << m2 << "/" << d2 << "/" << y2 << " is not a valid date" << endl;
        return -1;
    }

    while (m1 != m2 || d1 != d2 || y1 != y2) {
        if (y1 < y2 || (y1 == y2 && (m1 < m2 || (m1 == m2 && d1 < d2)))) {
            NextDate(m1, d1, y1);
            count++;
        } else {
            NextDate(m2, d2, y2);
            count--;
        }
    }

    return count;
}

int main() {
    int m1, d1, y1, m2, d2, y2;
    char separator;

    // Input format: MM/DD/YYYY
    cin >> m1 >> separator >> d1 >> separator >> y1;
    cin >> m2 >> separator >> d2 >> separator >> y2;


    // Check if the dates are valid
    if (!ValidDate(m1, d1, y1)) {
        cout << m1 << "/" << d1 << "/" << y1 << " is not a valid date" << endl;
    }

    if (!ValidDate(m2, d2, y2)) {
        cout << m2 << "/" << d2 << "/" << y2 << " is not a valid date" << endl;
        return 0;
    }


    int daysDifference = CalculateDaysDifference(m1, d1, y1, m2, d2, y2);
    
    if (daysDifference == 0) {
    cout << m1 << "/" << d1 << "/" << y1 << " is 0 days before " << m2 << "/" << d2 << "/" << y2 << endl;
    } else {
    cout << m1 << "/" << d1 << "/" << y1 << " is "
         << abs(daysDifference) << " days "
         << (daysDifference > 0 ? "before" : "after") << " "
         << m2 << "/" << d2 << "/" << y2 << endl;
    }

}
