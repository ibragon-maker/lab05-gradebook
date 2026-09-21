#include <gtest/gtest.h>
#include <algorithm>
#include <initializer_list>

#include "grading.h"
#include "utilities.h"

TEST(GradingEdgeCases, OneStudentOneAssignment) {
    Student roster[] = {
        {"Alice", {85.0, 0.0, 0.0}}
    };
    EXPECT_NEAR(student_average(roster[0], 1), 85.0, 0.001);
}

TEST(GradingEdgeCases, OneRowMultipleAssignments) {
    Student student{"Bob", {90.0, 80.0, 70.0}};
    EXPECT_NEAR(student_average(student, 3), 80.0, 0.001);
}

TEST(GradingEdgeCases, ZeroesAndNegativeValues) {
    Student student{"Charlie", {0.0, 0.0, 0.0}};
    EXPECT_NEAR(student_average(student, 3), 0.0, 0.001);
}

TEST(GradingEdgeCases, AtRiskVariations) {
    Student student{"Diana", {50.0, 60.0, 65.0}};
    EXPECT_TRUE(is_at_risk(student, 3));
}

TEST(GradingEdgeCases, PerfectScoreVariations) {
    Student student{"Eve", {100.0, 95.0, 98.0}};
    EXPECT_TRUE(has_perfect_score(student, 3));
}

