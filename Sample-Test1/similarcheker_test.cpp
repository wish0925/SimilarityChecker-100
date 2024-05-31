#include "pch.h"
#include "../Project5//similarcheker.cpp"

TEST(LengthCheck, LengthSame) {
	similarChecker sc("apple", "apple");
	sc.checkLength();
	EXPECT_EQ(60, sc.getLengthScore());
}

TEST(LengthCheck, LengthDiff1) {
	similarChecker sc("apple", "appl");
	sc.checkLength();
	EXPECT_EQ(45, sc.getLengthScore());
}

TEST(LengthCheck, LengthDiff2) {
	similarChecker sc("appl", "apple");
	sc.checkLength();
	EXPECT_EQ(45, sc.getLengthScore());
}

TEST(LengthCheck, LengthDiff3) {
	similarChecker sc("AA", "AAE");
	sc.checkLength();
	EXPECT_EQ(30, sc.getLengthScore());
}

TEST(LengthCheck, LengthZero) {
	similarChecker sc("appl", "appleappl");
	sc.checkLength();
	EXPECT_EQ(0, sc.getLengthScore());
}