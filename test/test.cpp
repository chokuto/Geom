#include <gtest/gtest.h>
#include <geom.h>

TEST(GeomVecter2fTest,AccessXY)
{
	Geom::Vector2f vec(1.0f, 2.0f);
	EXPECT_EQ(1.0f, vec.x);
	EXPECT_EQ(2.0f, vec.y);
}

TEST(GeomVecter2fTest,AccessWithIndices)
{
	Geom::Vector2f vec(1.0f, 2.0f);
	EXPECT_EQ(1.0f, vec.v[0]);
	EXPECT_EQ(2.0f, vec.v[1]);
}

TEST(GeomVecter2gTest,AccessXY)
{
	Geom::Vector2d vec(1.0, 2.0);
	EXPECT_EQ(1.0, vec.x);
	EXPECT_EQ(2.0, vec.y);
}

TEST(GeomVecter2dTest,AccessWithIndices)
{
	Geom::Vector2d vec(1.0, 2.0);
	EXPECT_EQ(1.0, vec.v[0]);
	EXPECT_EQ(2.0, vec.v[1]);
}

TEST(GeomVecter2dTest,AdditionAssginment)
{
	Geom::Vector2d vec1(1.0, 2.0);
	Geom::Vector2d vec2(3.0, 5.0);
	vec1 += vec2;
	EXPECT_EQ(4.0, vec1.x);
	EXPECT_EQ(7.0, vec1.y);
}

TEST(GeomVecter2dTest,SubtractionAssginment)
{
	Geom::Vector2d vec1(1.0, 2.0);
	Geom::Vector2d vec2(3.0, 5.0);
	vec2 -= vec1;
	EXPECT_EQ(2.0, vec2.x);
	EXPECT_EQ(3.0, vec2.y);
}

TEST(GeomVecter2dTest,Addition)
{
	Geom::Vector2d vec1(1.0, 2.0);
	Geom::Vector2d vec2(3.0, 5.0);
	Geom::Vector2d result = vec1 + vec2;
	EXPECT_EQ(4.0, result.x);
	EXPECT_EQ(7.0, result.y);
}

TEST(GeomVecter2dTest,Subtraction)
{
	Geom::Vector2d vec1(1.0, 2.0);
	Geom::Vector2d vec2(3.0, 5.0);
	Geom::Vector2d result = vec2 - vec1;
	EXPECT_EQ(2.0, result.x);
	EXPECT_EQ(3.0, result.y);
}


