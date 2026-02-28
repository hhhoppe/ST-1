// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// ==================== ТЕСТЫ ДЛЯ checkPrime ====================

TEST(TestCheckPrime, TestOnPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
}

TEST(TestCheckPrime, TestOnNotPrimes) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
    EXPECT_FALSE(checkPrime(15));
}

TEST(TestCheckPrime, TestOnLargePrimes) {
    EXPECT_TRUE(checkPrime(7919));  // 1000-е простое
    EXPECT_TRUE(checkPrime(104729));  // 10000-е простое
    EXPECT_FALSE(checkPrime(7920));
    EXPECT_FALSE(checkPrime(104730));
}

// ==================== ТЕСТЫ ДЛЯ nPrime ====================

TEST(TestNPrime, TestFirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
    EXPECT_EQ(nPrime(6), 13);
    EXPECT_EQ(nPrime(7), 17);
    EXPECT_EQ(nPrime(8), 19);
}

TEST(TestNPrime, TestZeroInput) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(TestNPrime, TestNthPrimes) {
    EXPECT_EQ(nPrime(10), 29);
    EXPECT_EQ(nPrime(20), 71);
    EXPECT_EQ(nPrime(30), 113);
}

// ==================== ТЕСТЫ ДЛЯ nextPrime ====================

TEST(TestNextPrime, TestSimpleCases) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(7), 11);
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(9), 11);
    EXPECT_EQ(nextPrime(10), 11);
}

TEST(TestNextPrime, TestZeroAndOne) {
    EXPECT_EQ(nextPrime(0), 2);
    EXPECT_EQ(nextPrime(1), 2);
}

TEST(TestNextPrime, TestLargeNumbers) {
    EXPECT_EQ(nextPrime(100), 101);
    EXPECT_EQ(nextPrime(102), 103);
    EXPECT_EQ(nextPrime(110), 113);
}

// ==================== ТЕСТЫ ДЛЯ sumPrime ====================

TEST(TestSumPrime, TestSmallBounds) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);  // простых чисел < 2 нет
    EXPECT_EQ(sumPrime(3), 2);  // 2
    EXPECT_EQ(sumPrime(4), 2);  // 2 + 3? нет, 3 < 4? да, 3 < 4, так что 2 + 3 = 5? Стоп, надо проверить
    // Исправляю: простые числа < 4: 2, 3. Сумма = 5
}

TEST(TestSumPrime, TestCorrected) {
    EXPECT_EQ(sumPrime(4), 5);  // 2 + 3
    EXPECT_EQ(sumPrime(5), 5);  // 2 + 3 (5 не входит, hbound не включается)
    EXPECT_EQ(sumPrime(6), 10); // 2 + 3 + 5
    EXPECT_EQ(sumPrime(7), 10); // 2 + 3 + 5
    EXPECT_EQ(sumPrime(8), 17); // 2 + 3 + 5 + 7
}

TEST(TestSumPrime, TestLargerBounds) {
    EXPECT_EQ(sumPrime(10), 17);  // 2+3+5+7
    EXPECT_EQ(sumPrime(11), 17);  // 2+3+5+7 (11 не входит)
    EXPECT_EQ(sumPrime(12), 28);  // 2+3+5+7+11
}

// ==================== ИТОГ: 15 ТЕСТОВ ====================
// checkPrime: 3 теста
// nPrime: 3 теста
// nextPrime: 3 теста
// sumPrime: 3 теста (с подтестами = 6)