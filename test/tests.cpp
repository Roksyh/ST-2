// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

const double EPS = 1e-5;
const double PI = 3.14159265358979323846;

// ==================== ТЕСТЫ КОНСТРУКТОРА ====================

TEST(CircleTest, Constructor_Default_InitializesToZero) {
    Circle c;
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, Constructor_WithRadius_CalculatesCorrectly) {
    double test_radius = 7.5;
    Circle c(test_radius);
    EXPECT_NEAR(c.getRadius(), test_radius, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * test_radius, EPS);
    EXPECT_NEAR(c.getArea(), PI * test_radius * test_radius, EPS);
}

TEST(CircleTest, Constructor_ZeroRadius_IsValid) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, Constructor_NegativeRadius_ThrowsException) {
    EXPECT_THROW(Circle(-10.5), std::invalid_argument);
}

// ==================== ТЕСТЫ СЕТТЕРОВ И ГЕТТЕРОВ ====================

TEST(CircleTest, SetRadius_ValidValue_UpdatesFerenceAndArea) {
    Circle c(2.0);
    double new_radius = 4.5;
    c.setRadius(new_radius);
    EXPECT_NEAR(c.getRadius(), new_radius, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * new_radius, EPS);
    EXPECT_NEAR(c.getArea(), PI * new_radius * new_radius, EPS);
}

TEST(CircleTest, SetFerence_ValidValue_UpdatesRadiusAndArea) {
    Circle c(1.0);
    double new_ference = 31.4159; // ~ 2*PI*5
    c.setFerence(new_ference);
    double expected_radius = new_ference / (2.0 * PI);
    EXPECT_NEAR(c.getRadius(), expected_radius, EPS);
    EXPECT_NEAR(c.getFerence(), new_ference, EPS);
    EXPECT_NEAR(c.getArea(), PI * expected_radius * expected_radius, EPS);
}

TEST(CircleTest, SetArea_ValidValue_UpdatesRadiusAndFerence) {
    Circle c(1.0);
    double new_area = 153.938; // ~ PI*7^2
    c.setArea(new_area);
    double expected_radius = std::sqrt(new_area / PI);
    EXPECT_NEAR(c.getRadius(), expected_radius, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * expected_radius, EPS);
    EXPECT_NEAR(c.getArea(), new_area, EPS);
}

TEST(CircleTest, SetRadius_NegativeValue_ThrowsAndDoesNotChangeState) {
    Circle c(3.0);
    double original_radius = c.getRadius();
    EXPECT_THROW(c.setRadius(-2.5), std::invalid_argument);
    EXPECT_NEAR(c.getRadius(), original_radius, EPS);
}

TEST(CircleTest, SetFerence_NegativeValue_ThrowsAndDoesNotChangeState) {
    Circle c(3.0);
    double original_ference = c.getFerence();
    EXPECT_THROW(c.setFerence(-15.0), std::invalid_argument);
    EXPECT_NEAR(c.getFerence(), original_ference, EPS);
}

TEST(CircleTest, SetArea_NegativeValue_ThrowsAndDoesNotChangeState) {
    Circle c(3.0);
    double original_area = c.getArea();
    EXPECT_THROW(c.setArea(-20.0), std::invalid_argument);
    EXPECT_NEAR(c.getArea(), original_area, EPS);
}

TEST(CircleTest, SetToZero_ClearsAllAttributes) {
    Circle c(8.8);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);

    c.setFerence(10.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);

    c.setArea(50.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

// ==================== ТЕСТЫ КОНСИСТЕНТНОСТИ ДАННЫХ ====================

TEST(CircleTest, ChainedSetters_MaintainConsistency) {
    Circle c(9.0);
    c.setRadius(1.5);
    c.setFerence(18.8495); // ~ 2*PI*3
    c.setArea(50.2654);    // ~ PI*4^2
    
    double expected_radius = 4.0;
    EXPECT_NEAR(c.getRadius(), expected_radius, 0.1);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * expected_radius, 0.1);
    EXPECT_NEAR(c.getArea(), PI * expected_radius * expected_radius, 0.1);
}

TEST(CircleTest, MathematicalRelation_FerenceAndArea) {
    Circle c(6.6);
    double r = c.getRadius();
    // Проверяем что c = 2*pi*r и s = pi*r^2
    EXPECT_NEAR(c.getFerence() / (2.0 * r), PI, EPS);
    EXPECT_NEAR(c.getArea() / (r * r), PI, EPS);
}

TEST(CircleTest, FerenceToArea_IndirectCalculation) {
    Circle c;
    double test_ference = 25.0;
    c.setFerence(test_ference);
    double calculated_area = PI * std::pow(test_ference / (2.0 * PI), 2);
    EXPECT_NEAR(c.getArea(), calculated_area, EPS);
}

TEST(CircleTest, AreaToFerence_IndirectCalculation) {
    Circle c;
    double test_area = 200.0;
    c.setArea(test_area);
    double calculated_ference = 2.0 * PI * std::sqrt(test_area / PI);
    EXPECT_NEAR(c.getFerence(), calculated_ference, EPS);
}

// Дополнительный тест для проверки const-корректности геттеров
TEST(CircleTest, Getters_AreConstCorrect) {
    const Circle c(12.3);
    EXPECT_NEAR(c.getRadius(), 12.3, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 12.3, EPS);
    EXPECT_NEAR(c.getArea(), PI * 12.3 * 12.3, EPS);
}

// ==================== ТЕСТЫ ЗАДАЧИ "ВЕРЕВКА" ====================

TEST(EarthRopeTask, Gap_IsPositive) {
    double gap = solveEarthRopeTask();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTask, Gap_MatchesFormula) {
    double gap = solveEarthRopeTask();
    double expected_gap = 1.0 / (2.0 * PI);
    EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(EarthRopeTask, Gap_ApproximateValueInMeters) {
    double gap = solveEarthRopeTask();
    // 1 / (2 * 3.14159) ~= 0.1591549
    EXPECT_NEAR(gap, 0.159155, 1e-6);
}

// ==================== ТЕСТЫ ЗАДАЧИ "БАССЕЙН" ====================

TEST(PoolTask, ConcreteArea_Calculation) {
    PoolCosts costs = solvePoolTask();
    Circle pool(3.0);
    Circle pool_with_path(4.0); // 3 + 1
    double expected_concrete_area = pool_with_path.getArea() - pool.getArea();
    double actual_concrete_area = costs.concrete_cost / 1000.0;
    EXPECT_NEAR(actual_concrete_area, expected_concrete_area, EPS);
}

TEST(PoolTask, FenceLength_Calculation) {
    PoolCosts costs = solvePoolTask();
    Circle outer_circle(4.0); // Радиус с учетом дорожки
    double expected_fence_length = outer_circle.getFerence();
    double actual_fence_length = costs.fence_cost / 2000.0;
    EXPECT_NEAR(actual_fence_length, expected_fence_length, EPS);
}

TEST(PoolTask, ConcreteCost_IsPositive) {
    PoolCosts costs = solvePoolTask();
    EXPECT_GT(costs.concrete_cost, 0.0);
}

TEST(PoolTask, FenceCost_IsPositive) {
    PoolCosts costs = solvePoolTask();
    EXPECT_GT(costs.fence_cost, 0.0);
}

TEST(PoolTask, OverallCosts_ApproximateValues) {
    PoolCosts costs = solvePoolTask();
    // Площадь дорожки: pi*(4^2 - 3^2) = 7*pi ≈ 21.99 м^2. Стоимость: ~21991 руб.
    // Длина ограды: 2*pi*4 = 8*pi ≈ 25.13 м. Стоимость: ~50265 руб.
    EXPECT_NEAR(costs.concrete_cost, 21991.1, 15.0);
    EXPECT_NEAR(costs.fence_cost, 50265.5, 15.0);
}

// ==================== ИТОГО ТЕСТОВ ====================
// CircleTest: 16 тестов
// EarthRopeTask: 3 теста
// PoolTask: 5 тестов
// ВСЕГО: 24 теста
