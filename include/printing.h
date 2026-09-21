#ifndef PRINTING_H
#define PRINTING_H

#include "utilities.h"

/**
 * @brief Prints the entire gradebook grid with names, scores, averages, and letter grades.
 *
 * @post Roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Total number of students in the roster.
 * @param[in] num_assignments Total number of assignments per student.
 */
void print_gradebook(const Student roster[], const int num_students, const int num_assignments);

/**
 * @brief Prints a detailed summary per student including min/max scores and status flags.
 *
 * @post Roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Total number of students in the roster.
 * @param[in] num_assignments Total number of assignments per student.
 */
void print_student_summary(const Student roster[], const int num_students, const int num_assignments);

/**
 * @brief Displays a letter grade distribution histogram across all scores in the roster.
 *
 * @post Roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Total number of students in the roster.
 * @param[in] num_assignments Total number of assignments per student.
 */
void print_histogram(const Student roster[], const int num_students, const int num_assignments);

/**
 * @brief Prints class average metrics for each assignment column.
 *
 * @post Roster is not modified.
 *
 * @param[in] roster Array of student records.
 * @param[in] num_students Total number of students in the roster.
 * @param[in] num_assignments Total number of assignments per student.
 */
void print_assignment_summary(const Student roster[], const int num_students, const int num_assignments);

#endif
