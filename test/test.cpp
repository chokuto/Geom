#include <gtest/gtest.h>
#include <geom.h>

TEST(GeomVecter2fTest,AccessXY)
{
	CGeomVector2f vec(1.0f, 2.0f);
	EXPECT_EQ(1.0f, vec.x);
	EXPECT_EQ(2.0f, vec.y);
}

TEST(GeomVecter2fTest,AccessWithIndices)
{
	CGeomVector2f vec(1.0f, 2.0f);
	EXPECT_EQ(1.0f, vec.v[0]);
	EXPECT_EQ(2.0f, vec.v[1]);
}

TEST(GeomVecter2dTest,AccessXY)
{
	CGeomVector2d vec(1.0, 2.0);
	EXPECT_EQ(1.0, vec.x);
	EXPECT_EQ(2.0, vec.y);
}

TEST(GeomVecter2dTest,AccessWithIndices)
{
	CGeomVector2d vec(1.0, 2.0);
	EXPECT_EQ(1.0, vec.v[0]);
	EXPECT_EQ(2.0, vec.v[1]);
}

TEST(GeomVecter2dTest,AdditionAssignment)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	vec1 += vec2;
	EXPECT_EQ(4.0, vec1.x);
	EXPECT_EQ(7.0, vec1.y);
}

TEST(GeomVecter2dTest,SubtractionAssignment)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	vec2 -= vec1;
	EXPECT_EQ(2.0, vec2.x);
	EXPECT_EQ(3.0, vec2.y);
}

TEST(GeomVecter2dTest,MultiplicationAssignment)
{
	CGeomVector2d vec(1.0, 2.0);
	vec *= 1.5;
	EXPECT_EQ(1.5, vec.x);
	EXPECT_EQ(3.0, vec.y);
}

TEST(GeomVecter2dTest,DivisionAssignment)
{
	CGeomVector2d vec(1.0, 2.0);
	vec /= 4.0;
	EXPECT_EQ(0.25, vec.x);
	EXPECT_EQ(0.5, vec.y);
}

TEST(GeomVecter2dTest,Addition)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	CGeomVector2d result = vec1 + vec2;
	EXPECT_EQ(4.0, result.x);
	EXPECT_EQ(7.0, result.y);
}

TEST(GeomVecter2dTest,Subtraction)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	CGeomVector2d result = vec2 - vec1;
	EXPECT_EQ(2.0, result.x);
	EXPECT_EQ(3.0, result.y);
}

TEST(GeomVecter2dTest,Multiplication)
{
	CGeomVector2d vec(1.2, 2.0);
	CGeomVector2d result = vec * 2;
	EXPECT_EQ(2.4, result.x);
	EXPECT_EQ(4.0, result.y);
}

TEST(GeomVecter2dTest,Multiplication2)
{
	CGeomVector2d vec(1.2, 2.0);
	CGeomVector2d result = 2 * vec;
	EXPECT_EQ(2.4, result.x);
	EXPECT_EQ(4.0, result.y);
}

TEST(GeomVecter2dTest,Division)
{
	CGeomVector2d vec(1.0, 2.0);
	CGeomVector2d result = vec / 4;
	EXPECT_EQ(0.25, result.x);
	EXPECT_EQ(0.5, result.y);
}

TEST(GeomVecter2dTest,DotProduct)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	EXPECT_EQ(13.0, DotProduct(vec1, vec2));
}

TEST(GeomVecter2dTest,CrossProduct2D)
{
	CGeomVector2d vec1(2.0, 3.0);
	CGeomVector2d vec2(4.0, 5.0);
	EXPECT_EQ(-2.0, CrossProduct2D(vec1, vec2));
}

TEST(GeomVecter2dTest,Length)
{
	CGeomVector2d vec(-3.0, 4.0);
	EXPECT_EQ(5.0, vec.Length());
}

TEST(GeomVecter2dTest,LengthSquared)
{
	CGeomVector2d vec(-3.0, 4.0);
	EXPECT_EQ(25.0, vec.LengthSquared());
}

TEST(GeomVecter2dTest,EqualityOperator)
{
	CGeomVector2d vec1(-3.0, 4.0);
	CGeomVector2d vec2(-3.0, 4.0);
	EXPECT_TRUE(vec1 == vec2);
}

TEST(GeomVecter2dTest,InequalityOperator1)
{
	CGeomVector2d vec1(-3.0, 5.0);
	CGeomVector2d vec2(-3.0, 4.0);
	EXPECT_TRUE(vec1 != vec2);
}

TEST(GeomVecter2dTest,InequalityOperator2)
{
	CGeomVector2d vec1(3.0, 4.0);
	CGeomVector2d vec2(-3.0, 4.0);
	EXPECT_TRUE(vec1 != vec2);
}

TEST(GeomVecter2dTest,CopyConstructor)
{
	CGeomVector2d vec1(3.0, 4.0);
	CGeomVector2d vec2(vec1);
	EXPECT_EQ(vec2, vec1);
}

TEST(GeomVecter2dTest,Assignment)
{
	CGeomVector2d vec1(3.0, 4.0);
	CGeomVector2d vec2;
	vec2 = vec1;
	EXPECT_EQ(vec2, vec1);
}

TEST(GeomVecter2dTest,UnaryPlusOperator)
{
	CGeomVector2d vec(-3.0, 4.0);
	EXPECT_EQ(vec, +vec);
}

TEST(GeomVecter2dTest,UnaryNegationOperator)
{
	CGeomVector2d vec1(-3.0, 4.0);
	CGeomVector2d vec2(3.0, -4.0);
	EXPECT_EQ(vec2, -vec1);
}

