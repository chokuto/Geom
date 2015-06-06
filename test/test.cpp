#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "GeomVector.h"

TEST(GeomVecter2fTest,Zero)
{
	CGeomVector2f vec(0.0f, 0.0f);
	EXPECT_EQ(CGeomVector2f::Zero, vec);
}

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

TEST(GeomVecter2dTest,Zero)
{
	CGeomVector2d vec(0.0, 0.0);
	EXPECT_EQ(CGeomVector2d::Zero, vec);
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

TEST(GeomVecter2dTest,MultiplicationAssignment2)
{
	CGeomVector2d vec(1.0, 2.5);
	vec *= 2;
	EXPECT_EQ(2.0, vec.x);
	EXPECT_EQ(5.0, vec.y);
}

TEST(GeomVecter2dTest,DivisionAssignment)
{
	CGeomVector2d vec(1.0, 2.0);
	vec /= 4.0;
	EXPECT_EQ(0.25, vec.x);
	EXPECT_EQ(0.5, vec.y);
}

TEST(GeomVecter2dTest,DivisionAssignment2)
{
	CGeomVector2d vec(1.0, 2.0);
	vec /= 4;
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
	CGeomVector2d result = vec * 2.0;
	EXPECT_EQ(2.4, result.x);
	EXPECT_EQ(4.0, result.y);
}

TEST(GeomVecter2dTest,Multiplication3)
{
	CGeomVector2d vec(1.2, 2.0);
	CGeomVector2d result = 2 * vec;
	EXPECT_EQ(2.4, result.x);
	EXPECT_EQ(4.0, result.y);
}

TEST(GeomVecter2dTest,Multiplication4)
{
	CGeomVector2d vec(1.2, 2.0);
	CGeomVector2d result = 2.0 * vec;
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

TEST(GeomVecter2dTest,Division2)
{
	CGeomVector2d vec(1.0, 2.0);
	CGeomVector2d result = vec / 4.0;
	EXPECT_EQ(0.25, result.x);
	EXPECT_EQ(0.5, result.y);
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

TEST(GeomVecter2dTest,DotProduct)
{
	CGeomVector2d vec1(1.0, 2.0);
	CGeomVector2d vec2(3.0, 5.0);
	EXPECT_DOUBLE_EQ(13.0, DotProduct(vec1, vec2));
}

TEST(GeomVecter2dTest,CrossProduct)
{
	CGeomVector2d vec1(2.0, 3.0);
	CGeomVector2d vec2(4.0, 5.0);
	EXPECT_DOUBLE_EQ(-2.0, CrossProduct(vec1, vec2));
}

TEST(GeomVecter2dTest,RotatedVector)
{
	CGeomVector2d vec(2.0, 3.0);
	CGeomVector2d result = vec.RotatedVector(90 * M_PI / 180);
	EXPECT_DOUBLE_EQ(-3.0, result.x);
	EXPECT_DOUBLE_EQ(2.0, result.y);
}

TEST(GeomVecter2dTest,RotatedVector2)
{
	CGeomVector2d vec(2.0, 3.0);
	CGeomVector2d result = vec.RotatedVector(-90 * M_PI / 180);
	EXPECT_DOUBLE_EQ(3.0, result.x);
	EXPECT_DOUBLE_EQ(-2.0, result.y);
}

TEST(GeomVecter2dTest,Rotate)
{
	CGeomVector2d vec(2.0, 3.0);
	vec.Rotate(90 * M_PI / 180);
	EXPECT_DOUBLE_EQ(-3.0, vec.x);
	EXPECT_DOUBLE_EQ(2.0, vec.y);
}

TEST(GeomVecter2dTest,Rotate2)
{
	CGeomVector2d vec(2.0, 3.0);
	vec.Rotate(-90 * M_PI / 180);
	EXPECT_DOUBLE_EQ(3.0, vec.x);
	EXPECT_DOUBLE_EQ(-2.0, vec.y);
}

TEST(GeomVecter2dTest,AngleBetween)
{
	CGeomVector2d vec1(2.0, 3.0);
	CGeomVector2d vec2(3.0, -2.0);
	EXPECT_DOUBLE_EQ(-90 * M_PI / 180, AngleBetween(vec1, vec2));
}

TEST(GeomVecter1fTest,Zero)
{
	CGeomVector1f vec(0.0f);
	EXPECT_EQ(CGeomVector1f::Zero, vec);
}

TEST(GeomVecter1fTest,AccessX)
{
	CGeomVector1f vec(1.0f);
	EXPECT_EQ(1.0f, vec.x);
}

TEST(GeomVecter1fTest,AccessWithIndices)
{
	CGeomVector1f vec(1.0f);
	EXPECT_EQ(1.0f, vec.v[0]);
}

TEST(GeomVecter1dTest,Zero)
{
	CGeomVector1d vec(0.0);
	EXPECT_EQ(CGeomVector1d::Zero, vec);
}

TEST(GeomVecter1dTest,AccessX)
{
	CGeomVector1d vec(1.0);
	EXPECT_EQ(1.0, vec.x);
}

TEST(GeomVecter1dTest,AccessWithIndices)
{
	CGeomVector1d vec(1.0);
	EXPECT_EQ(1.0, vec.v[0]);
}

TEST(GeomVecter1dTest,Length)
{
	CGeomVector1d vec(-3.0);
	EXPECT_EQ(3.0, vec.Length());
}

TEST(GeomVecter1dTest,LengthSquared)
{
	CGeomVector1d vec(-3.0);
	EXPECT_EQ(9.0, vec.LengthSquared());
}

TEST(GeomVecter3fTest,Zero)
{
	CGeomVector3f vec(0.0f, 0.0f, 0.0f);
	EXPECT_EQ(CGeomVector3f::Zero, vec);
}

TEST(GeomVecter3fTest,AccessXYZ)
{
	CGeomVector3f vec(1.0f, 2.0f, 3.0f);
	EXPECT_EQ(1.0f, vec.x);
	EXPECT_EQ(2.0f, vec.y);
	EXPECT_EQ(3.0f, vec.z);
}

TEST(GeomVecter3fTest,AccessWithIndices)
{
	CGeomVector3f vec(1.0f, 2.0f, 3.0f);
	EXPECT_EQ(1.0f, vec.v[0]);
	EXPECT_EQ(2.0f, vec.v[1]);
	EXPECT_EQ(3.0f, vec.v[2]);
}

TEST(GeomVecter3dTest,Zero)
{
	CGeomVector3d vec(0.0, 0.0, 0.0);
	EXPECT_EQ(CGeomVector3d::Zero, vec);
}

TEST(GeomVecter3dTest,AccessXYZ)
{
	CGeomVector3d vec(1.0, 2.0, 3.0);
	EXPECT_EQ(1.0, vec.x);
	EXPECT_EQ(2.0, vec.y);
	EXPECT_EQ(3.0, vec.z);
}

TEST(GeomVecter3dTest,AccessWithIndices)
{
	CGeomVector3d vec(1.0, 2.0, 3.0);
	EXPECT_EQ(1.0, vec.v[0]);
	EXPECT_EQ(2.0, vec.v[1]);
	EXPECT_EQ(3.0, vec.v[2]);
}

TEST(GeomVecter3dTest,Length)
{
	CGeomVector3d vec(1.0, -4.0, 8.0);
	EXPECT_EQ(9.0, vec.Length());
}

TEST(GeomVecter3dTest,LengthSquared)
{
	CGeomVector3d vec(1.0, -4.0, 8.0);
	EXPECT_EQ(81.0, vec.LengthSquared());
}

TEST(GeomVecter3dTest,CrossProduct)
{
	CGeomVector3d vec1(1.0, -2.0, 0.0);
	CGeomVector3d vec2(-2.0, 1.0, -1.0);
	EXPECT_EQ(CGeomVector3d(2.0, 1.0, -3.0), CrossProduct(vec1, vec2));
}

TEST(GeomVecterNdTest,Zero)
{
	CGeomVector<double,4> vec;
	vec.v[0] = 0.0;
	vec.v[1] = 0.0;
	vec.v[2] = 0.0;
	vec.v[3] = 0.0;

	EXPECT_EQ((CGeomVector<double,4>::Zero), vec);
}

TEST(GeomVecterNdTest,Length)
{
	CGeomVector<double,4> vec;
	vec.v[0] = 1.0;
	vec.v[1] = 3.0;
	vec.v[2] = 5.0;
	vec.v[3] = 17.0;

	EXPECT_EQ(18.0, vec.Length());
}
