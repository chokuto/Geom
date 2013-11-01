#include <gtest/gtest.h>
#include <geom.h>

TEST(GeomVecter2fTest,AccessXY)
{
	Geom::Vector2f vec = { 1.0f, 2.0f };
	EXPECT_EQ(1.0f, vec.x);
	EXPECT_EQ(2.0f, vec.y);
}

TEST(GeomVecter2fTest,AccessWithIndices)
{
	Geom::Vector2f vec = { 1.0f, 2.0f };
	EXPECT_EQ(1.0f, vec.v[0]);
	EXPECT_EQ(2.0f, vec.v[1]);
}

TEST(GeomVecter2gTest,AccessXY)
{
	Geom::Vector2d vec = { 1.0, 2.0 };
	EXPECT_EQ(1.0, vec.x);
	EXPECT_EQ(2.0, vec.y);
}

TEST(GeomVecter2dTest,AccessWithIndices)
{
	Geom::Vector2d vec = { 1.0, 2.0 };
	EXPECT_EQ(1.0, vec.v[0]);
	EXPECT_EQ(2.0, vec.v[1]);
}


