#include "C:\univer\OOP\lab1\lab1\Ratio.cpp"
#include "pch.h"

TEST(Basic, CurrentCout)
{
    Ratio num(3, 4);
    int res = Ratio::GetCurrentCount();
    EXPECT_EQ(res, 1);
    Ratio num1(3, 4), num2(2, 5), num3(-3, 4), num4(0, 0);
    res = Ratio::GetCurrentCount();
    EXPECT_EQ(res, 5);
}

TEST(ConstructorTest, DefaultConstructor) {
    Ratio num;
    EXPECT_EQ(num.GetNumerator(), 0);
    EXPECT_EQ(num.GetDenominator(), 1);
}

TEST(ConstructorTest, SingleParameterConstructor) {
    Ratio num(5);
    EXPECT_EQ(num.GetNumerator(), 5);
    EXPECT_EQ(num.GetDenominator(), 1);

    Ratio numNeg(-5);
    EXPECT_EQ(numNeg.GetNumerator(), -5);
    EXPECT_EQ(numNeg.GetDenominator(), 1);
}

TEST(ConstructorTest, TwoParameterConstructor) {
    Ratio num(3, 4);
    EXPECT_EQ(num.GetNumerator(), 3);
    EXPECT_EQ(num.GetDenominator(), 4);

    Ratio numNegNumerator(-3, 4);
    EXPECT_EQ(numNegNumerator.GetNumerator(), -3);
    EXPECT_EQ(numNegNumerator.GetDenominator(), 4);

    Ratio numNegDenominator(3, -4);
    EXPECT_EQ(numNegDenominator.GetNumerator(), -3);
    EXPECT_EQ(numNegDenominator.GetDenominator(), 4);

    Ratio zeroNumerator(0, 4);
    EXPECT_EQ(zeroNumerator.GetNumerator(), 0);
    EXPECT_EQ(zeroNumerator.GetDenominator(), 1);
}

TEST(ConstructorTest, CopyConstructor) {
    Ratio num1(2, 5);
    Ratio num2 = num1;
    EXPECT_EQ(num2.GetNumerator(), 2);
    EXPECT_EQ(num2.GetDenominator(), 5);

    Ratio numNeg(-2, 5);
    Ratio num3 = numNeg;
    EXPECT_EQ(num3.GetNumerator(), -2);
    EXPECT_EQ(num3.GetDenominator(), 5);
}

TEST(Basic, Sing)
{
    Ratio num1(-5, -2), num2(5, 2), num3(3, -4), num4( -3, 4 );
    EXPECT_EQ(num1, num2);
    EXPECT_EQ(num3, num4);
}

TEST(AccessTest, GetSetNumerator) {
    Ratio num(3, 4);
    num.SetNumerator(5);
    EXPECT_EQ(num.GetNumerator(), 5);
    num.SetNumerator(-5);
    EXPECT_EQ(num.GetNumerator(), -5);
    num.SetNumerator(0);
    EXPECT_EQ(num.GetNumerator(), 0);
}

TEST(AccessTest, GetSetDenominator) {
    Ratio num(3, 4);
    num.SetDenominator(6);
    EXPECT_EQ(num.GetDenominator(), 6);
    num.SetDenominator(-6);
    EXPECT_EQ(num.GetDenominator(), 6);
    num.SetDenominator(0);
    EXPECT_EQ(num.GetDenominator(), 1);
}

TEST(RatioTest, ReduceRatioWorks) {
    Ratio num1(8, 12);  
    num1.ReduceRatio();
    EXPECT_EQ(num1.GetNumerator(), 2);
    EXPECT_EQ(num1.GetDenominator(), 3);
    Ratio num2(3, 4);
    num2.ReduceRatio();
    EXPECT_EQ(num2.GetNumerator(), 3);
    EXPECT_EQ(num2.GetDenominator(), 4);
    Ratio num3(-4, 6);
    num3.ReduceRatio();
    EXPECT_EQ(num3.GetNumerator(), -2);
    EXPECT_EQ(num3.GetDenominator(), 3);
    Ratio num4(0, 6);
    num3.ReduceRatio();
    EXPECT_EQ(num4.GetNumerator(), 0);
    EXPECT_EQ(num4.GetDenominator(), 1);
}

TEST(MathOperationsTest, Operatplus) {
    Ratio num1(1, 2), num2(1, 3), num3(-1, 2), num4(1, 2), num5(0, 0);
    Ratio result = num1 + num2;
    EXPECT_EQ(result.GetNumerator(), 5);
    EXPECT_EQ(result.GetDenominator(), 6);

    Ratio result1 = num3 + num2;
    EXPECT_EQ(result1.GetNumerator(), -1);
    EXPECT_EQ(result1.GetDenominator(), 6);

    Ratio result2 = num4 + num1;
    EXPECT_EQ(result2.GetNumerator(), 1);
    EXPECT_EQ(result2.GetDenominator(), 1);

    Ratio result3 = num3 + num5;
    EXPECT_EQ(result3.GetNumerator(), -1);
    EXPECT_EQ(result3.GetDenominator(), 2);
}

TEST(MathOperationsTest, Operatminus) {
    Ratio num1(3, 4), num2(1, 2), num3(-3, 4), num4(1, 2), num5(0, 0);
    Ratio result = num1 - num2;
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 4);

    Ratio result1 = num3 - num2;
    EXPECT_EQ(result1.GetNumerator(), -5);
    EXPECT_EQ(result1.GetDenominator(), 4);
    
    Ratio result2 = num4 - num2;
    EXPECT_EQ(result2.GetNumerator(), 0);
    EXPECT_EQ(result2.GetDenominator(), 1);

    Ratio result3 = num3 - num5;
    EXPECT_EQ(result3.GetNumerator(), -3);
    EXPECT_EQ(result3.GetDenominator(), 4);
}

TEST(MathOperationsTest, Operatmulti) {
    Ratio num1(2, 3), num2(3, 4), num3(-2, 3), num5(0, 0);
    Ratio result = num1 * num2;
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 2);

    Ratio result1 = num3 * num2;
    EXPECT_EQ(result1.GetNumerator(), -1);
    EXPECT_EQ(result1.GetDenominator(), 2);

    Ratio result2 = num5 * num2;
    EXPECT_EQ(result2.GetNumerator(), 0);
    EXPECT_EQ(result2.GetDenominator(), 1);
}

TEST(MathOperationsTest, Operatdivision) {
    Ratio num1(3, 4), num2(2, 5), num3(-3, 4), num5(0, 0);
    Ratio result = num1 / num2;
    EXPECT_EQ(result.GetNumerator(), 15);
    EXPECT_EQ(result.GetDenominator(), 8);

    Ratio result1 = num3 / num2;
    EXPECT_EQ(result1.GetNumerator(), -15);
    EXPECT_EQ(result1.GetDenominator(), 8);

    Ratio result2 = num5 / num2;
    EXPECT_EQ(result2.GetNumerator(), 0);
    EXPECT_EQ(result2.GetDenominator(), 1);

    Ratio result3 = num3 / num5;
    EXPECT_EQ(result3.GetNumerator(), 0);
    EXPECT_EQ(result3.GetDenominator(), 1);
}

TEST(ComparisonTest, Equality) {
    Ratio num1(3, 4);
    Ratio num2(3, 4);
    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 != num2);

    Ratio numNeg(-3, 4);
    EXPECT_FALSE(num1 == numNeg);
}

TEST(ComparisonTest, GreaterThan) {
    Ratio num1(5, 6);
    Ratio num2(4, 6);
    EXPECT_TRUE(num1 > num2);

    Ratio num3(-5, 6);
    EXPECT_FALSE(num3 > num2);
}

TEST(ComparisonTest, LessThan) {
    Ratio num1(2, 7);
    Ratio num2(3, 7);
    EXPECT_TRUE(num1 < num2);

    Ratio num3(-2, 7);
    EXPECT_TRUE(num3 < num1);
}

TEST(ComparisonTest, LessGreatEglitiThan) {
    Ratio num1(2, 7), num2(2, 7), num3(-2, 7);

    EXPECT_TRUE(num1 <= num2);
    EXPECT_TRUE(num3 <= num1);
    EXPECT_FALSE(num3 >= num1);
    EXPECT_FALSE(num3 >= num1);
}

TEST(PowTest, PositiveExponent) {
    Ratio num(2, 3);
    Ratio result = num.Pow(2);
    EXPECT_EQ(result.GetNumerator(), 4);
    EXPECT_EQ(result.GetDenominator(), 9);
}

TEST(PowTest, NegativeExponent) {
    Ratio num(2, 3);
    Ratio result = num.Pow(-2);
    EXPECT_EQ(result.GetNumerator(), 9);
    EXPECT_EQ(result.GetDenominator(), 4);
}

TEST(WholePartTest, WholePart) {
    Ratio num(5, 2);
    EXPECT_EQ(num.WholePartRatio(), 2);

    Ratio numNeg(-5, 2);
    EXPECT_EQ(numNeg.WholePartRatio(), -2);
}

TEST(WholePartTest, ShotgunPart) {
    Ratio num(5, 2);
    Ratio shotgun = num.ShotgunPartRatio();
    EXPECT_EQ(shotgun.GetNumerator(), 1);
    EXPECT_EQ(shotgun.GetDenominator(), 2);

    Ratio numNeg(-5, 2);
    Ratio shotgunNeg = numNeg.ShotgunPartRatio();
    EXPECT_EQ(shotgunNeg.GetNumerator(), -1);
    EXPECT_EQ(shotgunNeg.GetDenominator(), 2);
}

TEST(ConversionTest, ConvertToFloat) {
    Ratio num1(3, 4), numNeg(-3, 4),  num2(0, 0);
    EXPECT_FLOAT_EQ(num1.ConverInFloat(), 0.75f);

    EXPECT_FLOAT_EQ(numNeg.ConverInFloat(), -0.75f);

    EXPECT_FLOAT_EQ(num2.ConverInFloat(), 0.0f);
}

TEST(ConversionTest, ConvertToInt) {
    Ratio num1(7, 3), numNeg(-7, 3), num2(0, 0);
    EXPECT_EQ(num1.ConverInInt(), 2);

    EXPECT_EQ(numNeg.ConverInInt(), -2);

    EXPECT_FLOAT_EQ(num2.ConverInInt(), 0);
}

TEST(AssignmentTest, AdditionAssignment) {
    Ratio num1(1, 2), num2(1, 3), num3(-1, 2), num4(0, 0);
    num1 += num2;
    EXPECT_EQ(num1.GetNumerator(), 5);
    EXPECT_EQ(num1.GetDenominator(), 6);

    num3 += num2;
    EXPECT_EQ(num3.GetNumerator(), -1);
    EXPECT_EQ(num3.GetDenominator(), 6);

    num3 *= num4;
    EXPECT_EQ(num3.GetNumerator(), 0);
    EXPECT_EQ(num3.GetDenominator(), 1);
}

TEST(AssignmentTest, Assignment) {
    Ratio num1(2, 3), num2(3, 4), num3(-2, 3), num4(0, 0);
    num1 = num2;
    EXPECT_EQ(num1.GetNumerator(), 3);
    EXPECT_EQ(num1.GetDenominator(), 4);

    num3 = num2;
    EXPECT_EQ(num3.GetNumerator(), 3);
    EXPECT_EQ(num3.GetDenominator(), 4);

    num3 = num4;
    EXPECT_EQ(num3.GetNumerator(), 0);
    EXPECT_EQ(num3.GetDenominator(), 1);
}

TEST(AssignmentTest, SubtractionAssignment) {
    Ratio num1(3, 4), num2(1, 2), num3(-3, 4), num4(0, 0);
    num1 -= num2;
    EXPECT_EQ(num1.GetNumerator(), 1);
    EXPECT_EQ(num1.GetDenominator(), 4);

    num3 -= num2;
    EXPECT_EQ(num3.GetNumerator(), -5);
    EXPECT_EQ(num3.GetDenominator(), 4);
    
    num3 -= num4;
    EXPECT_EQ(num3.GetNumerator(), -5);
    EXPECT_EQ(num3.GetDenominator(), 4);
}

TEST(AssignmentTest, MultiplicationAssignment) {
    Ratio num1(2, 3), num2(3, 4), num3(-2, 3), num4(0, 0);
    num1 *= num2;
    EXPECT_EQ(num1.GetNumerator(), 1);
    EXPECT_EQ(num1.GetDenominator(), 2);

    num3 *= num2;
    EXPECT_EQ(num3.GetNumerator(), -1);
    EXPECT_EQ(num3.GetDenominator(), 2);

    num3 *= num4;
    EXPECT_EQ(num3.GetNumerator(), 0);
    EXPECT_EQ(num3.GetDenominator(), 1);
}

TEST(AssignmentTest, DivisionAssignment) {
    Ratio num1(3, 4), num2(2, 5), num3(-3, 4), num4(0, 0);
    num1 /= num2;
    EXPECT_EQ(num1.GetNumerator(), 15);
    EXPECT_EQ(num1.GetDenominator(), 8);

    num3 /= num2;
    EXPECT_EQ(num3.GetNumerator(), -15);
    EXPECT_EQ(num3.GetDenominator(), 8);

    num3 /= num4;
    EXPECT_EQ(num3.GetNumerator(), 0);
    EXPECT_EQ(num3.GetDenominator(), 1);
}

TEST(CheckTest, IsInteger) {
    Ratio num1(4, 2);
    EXPECT_TRUE(num1.IsInt());

    Ratio num2(5, 2);
    EXPECT_FALSE(num2.IsInt());

    Ratio num3(-6, 3);
    EXPECT_TRUE(num3.IsInt());
}

