// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// ==================== ТЕСТЫ ДЛЯ checkPrime ====================

TEST(CheckPrimeTest, ZeroAndOneAreNotPrime) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrimeTest, SmallPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
}

TEST(CheckPrimeTest, SmallComposites) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
}

TEST(CheckPrimeTest, LargePrime) {
    EXPECT_TRUE(checkPrime(7919));
    EXPECT_TRUE(checkPrime(104729));
}

TEST(CheckPrimeTest, LargeComposite) {
    EXPECT_FALSE(checkPrime(7920));
    EXPECT_FALSE(checkPrime(104730));
}

// ==================== ТЕСТЫ ДЛЯ nPrime ====================

TEST(NPrimeTest, FirstFivePrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
}

TEST(NPrimeTest, TenthAndTwentiethPrimes) {
    EXPECT_EQ(nPrime(10), 29);
    EXPECT_EQ(nPrime(20), 71);
}

TEST(NPrimeTest, ZeroInput) {
    EXPECT_EQ(nPrime(0), 0);
}

// ==================== ТЕСТЫ ДЛЯ nextPrime ====================

TEST(NextPrimeTest, SimpleCases) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(6), 7);
}

TEST(NextPrimeTest, ZeroCase) {
    EXPECT_EQ(nextPrime(0), 2);
}

TEST(NextPrimeTest, AfterLargePrime) {
    EXPECT_EQ(nextPrime(13), 17);
}

// ==================== ТЕСТЫ ДЛЯ sumPrime ====================

TEST(SumPrimeTest, SmallBounds) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 5);
    EXPECT_EQ(sumPrime(5), 5);
    EXPECT_EQ(sumPrime(6), 10);
    EXPECT_EQ(sumPrime(7), 10);
    EXPECT_EQ(sumPrime(8), 17);
}

TEST(SumPrimeTest, TenAndEleven) {
    EXPECT_EQ(sumPrime(10), 17);
    EXPECT_EQ(sumPrime(11), 17);
    EXPECT_EQ(sumPrime(12), 28);
}
