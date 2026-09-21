#ifndef GRADING_H
#define GRADING_H

#include "utilities.h"

/**
 * @brief Calculates one student's mean score across all assignments.
 *
 * @pre student has valid scores.
 * @post student record is not modified.
 *
 * @param[in] student The student record to calculate average for.
 * @param[in] num_assignments Number of assignments in the course.
 * @return The mean of that student's assignment scores.
 */
[[nodiscard]] double student_average(const Student& student, const int num_assignments);

/**
 * @brief Calculates the mean score on one assignment across all students.
 *
 * @pre assignment_index is in the range [0, num_assignments).
 * @post roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Number of students in the roster.
 * @param[in] assignment_index Column index of the assignment.
 * @param[in] num_assignments Total number of assignments.
 * @return The mean score on that assignment.
 */
[[nodiscard]] double assignment_average(const Student roster[], const int num_students, int assignment_index, const int num_assignments);

/**
 * @brief Calculates the overall average score across all students and assignments.
 *
 * @post roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Number of students in the roster.
 * @param[in] num_assignments Number of assignments per student.
 * @return The overall class average.
 */
[[nodiscard]] double class_average(const Student roster[], const int num_students, const int num_assignments);

/**
 * @brief Finds the lowest and highest assignment scores for a single student.
 *
 * @post student is not modified.
 *
 * @param[in] student The student record to evaluate.
 * @param[in] num_assignments Number of assignments per student.
 * @param[out] lowest Reference variable to store the lowest score.
 * @param[out] highest Reference variable to store the highest score.
 */
void find_extremes(const Student& student, const int num_assignments, double& lowest, double& highest);

/**
 * @brief Counts how many assignment grades in the entire roster match a target letter grade.
 *
 * @post roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Number of students in the roster.
 * @param[in] num_assignments Number of assignments per student.
 * @param[in] target Letter grade to match ('A', 'B', 'C', 'D', 'F').
 * @return Total count of matching grades.
 */
[[nodiscard]] int count_grade(const Student roster[], const int num_students, const int num_assignments, char target);

/**
 * @brief Checks if a student has earned at least one score of 100.0.
 *
 * @post student is not modified.
 *
 * @param[in] student The student record to evaluate.
 * @param[in] num_assignments Number of assignments per student.
 * @return True if the student has a score of 100.0, false otherwise.
 */
[[nodiscard]] bool has_perfect_score(const Student& student, const int num_assignments);

/**
 * @brief Checks if a student's average score falls below the passing threshold.
 *
 * @post student is not modified.
 *
 * @param[in] student The student record to evaluate.
 * @param[in] num_assignments Number of assignments per student.
 * @return True if the student's average is below passing, false otherwise.
 */
[[nodiscard]] bool is_at_risk(const Student& student, const int num_assignments);

#endif
