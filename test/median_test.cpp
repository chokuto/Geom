#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "GeomVector.h"
#include "GeomMedian.h"
#include <vector>

TEST(GeomMedianTest,Mean)
{
	std::vector<CGeomVector2d> vec_list;
	vec_list.emplace_back(2.0, 3.0);
	vec_list.emplace_back(-1.0, 4.0);
	vec_list.emplace_back(5.0, 5.0);

	EXPECT_EQ(CGeomVector2d(2.0, 4.0), GeometricMean(vec_list.begin(), vec_list.end()));
}
TEST(GeomMedianTest,Median)
{
	std::vector<CGeomVector2d> vec_list;
	vec_list.emplace_back(1, 2);
	vec_list.emplace_back(1, 7);
	vec_list.emplace_back(2, 2);
	vec_list.emplace_back(2, 3);
	vec_list.emplace_back(2, 5);
	vec_list.emplace_back(3, 4);
	vec_list.emplace_back(4, 2);
	vec_list.emplace_back(4, 5);
	vec_list.emplace_back(4, 6);
	vec_list.emplace_back(5, 3);
	vec_list.emplace_back(6, 5);
	CGeomVector2d median = GeometricMedian(vec_list.begin(), vec_list.end());
	EXPECT_NEAR(3, median.x, std::numeric_limits<double>::epsilon());
	EXPECT_NEAR(4, median.y, std::numeric_limits<double>::epsilon());
}

TEST(GeomMedianTest,Median2)
{
	std::vector<CGeomVector2d> vec_list;
	vec_list.emplace_back(1, 4);
	vec_list.emplace_back(3, 4);
	vec_list.emplace_back(3, 4);
	vec_list.emplace_back(3, 4);
	vec_list.emplace_back(4, 4);
	CGeomVector2d median = GeometricMedian(vec_list.begin(), vec_list.end());
	EXPECT_NEAR(3, median.x, std::numeric_limits<double>::epsilon());
	EXPECT_NEAR(4, median.y, std::numeric_limits<double>::epsilon());
}
