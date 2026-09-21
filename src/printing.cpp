#include "printing.h"
#include "grading.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>

void print_gradebook(const Student roster[], const int num_students, const int num_assignments) {
    for (int i = 0; i < num_students; ++i) {
        std::cout << pad_name(roster[i].name, 15) << " | ";
        for (int j = 0; j < num_assignments; ++j) {
            std::cout << std::setw(6) << std::fixed << std::setprecision(1) << roster[i].scores[j] << " ";
        }
        double avg = student_average(roster[i], num_assignments);
        std::cout << "| Avg: " << std::setw(5) << std::fixed << std::setprecision(1) << avg;
        std::cout << " (" << letter_grade(avg) << ")\n";
    }
}

void print_student_summary(const Student roster[], const int num_students, const int num_assignments) {
    for (int i = 0; i < num_students; ++i) {
        double avg = student_average(roster[i], num_assignments);
        double low = 0.0, high = 0.0;
        find_extremes(roster[i], num_assignments, low, high);

        std::cout << pad_name(roster[i].name, 15)
                  << " | Avg: " << std::setw(5) << std::fixed << std::setprecision(1) << avg
                  << " (" << letter_grade(avg) << ")"
                  << " | Min: " << std::setw(5) << low
                  << " | Max: " << std::setw(5) << high;

        if (has_perfect_score(roster[i], num_assignments)) {
            std::cout << " [PERFECT]";
        }
        if (is_at_risk(roster[i], num_assignments)) {
            std::cout << " [AT-RISK]";
        }
        std::cout << "\n";
    }
}

void print_histogram(const Student roster[], const int num_students, const int num_assignments) {
    const char grades[] = {'A', 'B', 'C', 'D', 'F'};
    for (char letter : grades) {
        int count = count_grade(roster, num_students, num_assignments, letter);
        std::cout << letter << ": ";
        for (int k = 0; k < count; ++k) {
            std::cout << "*";
        }
        std::cout << " (" << count << ")\n";
    }
}

void print_assignment_summary(const Student roster[], const int num_students, const int num_assignments) {
    for (int j = 0; j < num_assignments; ++j) {
        double avg = assignment_average(roster, num_students, j, num_assignments);
        std::cout << "Assignment " << (j + 1) << " Avg: "
                  << std::setw(5) << std::fixed << std::setprecision(1) << avg << "\n";
    }
}
