#include "grading.h"
#include "printing.h"
#include "utilities.h"
#include <iostream>

int main() {
    constexpr int NUM_STUDENTS = 5;
    constexpr int NUM_ASSIGNMENTS = 3;

    Student roster[NUM_STUDENTS] = {
        {"Alice",   {85.5, 92.0, 78.0}},
        {"Bob",     {60.0, 65.5, 58.0}},
        {"Charlie", {100.0, 95.0, 98.0}},
        {"Diana",   {72.0, 81.0, 79.5}},
        {"Eve",     {90.0, 88.5, 94.0}}
    };

    std::cout << "========================================\n";
    std::cout << "           GRADEBOOK REPORT             \n";
    std::cout << "========================================\n\n";

    std::cout << "--- Roster Grades ---\n";
    print_gradebook(roster, NUM_STUDENTS, NUM_ASSIGNMENTS);

    std::cout << "\n--- Student Summary ---\n";
    print_student_summary(roster, NUM_STUDENTS, NUM_ASSIGNMENTS);

    std::cout << "\n--- Grade Histogram ---\n";
    print_histogram(roster, NUM_STUDENTS, NUM_ASSIGNMENTS);

    std::cout << "\n--- Assignment Averages ---\n";
    print_assignment_summary(roster, NUM_STUDENTS, NUM_ASSIGNMENTS);

    return 0;
}
