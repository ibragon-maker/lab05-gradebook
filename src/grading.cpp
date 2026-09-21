#include "grading.h"
#include "utilities.h"

double student_average(const Student& student, const int num_assignments) {
    if (num_assignments <= 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int j = 0; j < num_assignments; ++j) {
        sum += student.scores[j];
    }
    return sum / num_assignments;
}

double assignment_average(const Student roster[], const int num_students, int assignment_index, const int num_assignments) {
    if (num_students <= 0 || assignment_index < 0 || assignment_index >= num_assignments) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < num_students; ++i) {
        sum += roster[i].scores[assignment_index];
    }
    return sum / num_students;
}

double class_average(const Student roster[], const int num_students, const int num_assignments) {
    if (num_students <= 0 || num_assignments <= 0) {
        return 0.0;
    }
    double total_sum = 0.0;
    for (int i = 0; i < num_students; ++i) {
        for (int j = 0; j < num_assignments; ++j) {
            total_sum += roster[i].scores[j];
        }
    }
    return total_sum / (num_students * num_assignments);
}

void find_extremes(const Student& student, const int num_assignments, double& lowest, double& highest) {
    if (num_assignments <= 0) {
        lowest = 0.0;
        highest = 0.0;
        return;
    }
    lowest = student.scores[0];
    highest = student.scores[0];
    for (int j = 1; j < num_assignments; ++j) {
        if (student.scores[j] < lowest) {
            lowest = student.scores[j];
        }
        if (student.scores[j] > highest) {
            highest = student.scores[j];
        }
    }
}

int count_grade(const Student roster[], const int num_students, const int num_assignments, char target) {
    int count = 0;
    for (int i = 0; i < num_students; ++i) {
        for (int j = 0; j < num_assignments; ++j) {
            if (letter_grade(roster[i].scores[j]) == target) {
                count++;
            }
        }
    }
    return count;
}

bool has_perfect_score(const Student& student, const int num_assignments) {
    for (int j = 0; j < num_assignments; ++j) {
        if (student.scores[j] >= 100.0) {
            return true;
        }
    }
    return false;
}

bool is_at_risk(const Student& student, const int num_assignments) {
    return student_average(student, num_assignments) < 70.0;
}
