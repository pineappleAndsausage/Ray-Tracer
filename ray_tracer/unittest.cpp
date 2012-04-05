#pragma once

#include "unittest.h"

using namespace testing;
TEST(ColorsTest, Plus)
{
	Colors color(.1f, .2f, .3f);
	Colors color2 = color + color;
	ASSERT_FLOAT_EQ(color2[0],.2f);
	ASSERT_FLOAT_EQ(color2[1],.4f);
	ASSERT_FLOAT_EQ(color2[2],.6f);
}
TEST(ColorsTest, Minus)
{
	Colors color(.1f, .2f, .3f);
	Colors color2 = color - color;
	ASSERT_FLOAT_EQ(color2[0],.0f);
	ASSERT_FLOAT_EQ(color2[1],.0f);
	ASSERT_FLOAT_EQ(color2[2],.0f);
}
TEST(ColorsTest, Multiplying)
{
	Colors color(.1f, .2f, .3f);
	Colors color2 = color * color;
	ASSERT_FLOAT_EQ(color2[0],.01f);
	ASSERT_FLOAT_EQ(color2[1],.04f);
	ASSERT_FLOAT_EQ(color2[2],.09f);
}
TEST(ColorsTest, ScalarMultiplying)
{
	Colors color(.1f, .2f, .3f);
	Colors color2 = color * 2;
	ASSERT_FLOAT_EQ(color2[0],.2f);
	ASSERT_FLOAT_EQ(color2[1],.4f);
	ASSERT_FLOAT_EQ(color2[2],.6f);
	color2 = 2 *color;
	ASSERT_FLOAT_EQ(color2[0],.2f);
	ASSERT_FLOAT_EQ(color2[1],.4f);
	ASSERT_FLOAT_EQ(color2[2],.6f);
}
TEST(ColorsTest, ScalarDividing)
{
	Colors color(.1f, .2f, .3f);
	Colors color2 = color / 2;
	ASSERT_FLOAT_EQ(color2[0],.05f);
	ASSERT_FLOAT_EQ(color2[1],.1f);
	ASSERT_FLOAT_EQ(color2[2],.15f);	
}

TEST(Vector3FTest, UnaryMinus)
{
	Vector3F vec(1,2,3);	
	Vector3F vec2 = -vec;
	ASSERT_FLOAT_EQ(vec2[0],-1);
	ASSERT_FLOAT_EQ(vec2[1],-2);
	ASSERT_FLOAT_EQ(vec2[2],-3);	
}
TEST(Vector3FTest, ScalarPlus)
{
	Vector3F vec(1,2,3);	
	Vector3F vec2 = vec + 1;
	ASSERT_FLOAT_EQ(vec2[0], 2);
	ASSERT_FLOAT_EQ(vec2[1], 3);
	ASSERT_FLOAT_EQ(vec2[2], 4);	
}
TEST(Vector3FTest, ScalarMinus)
{
	Vector3F vec(1,2,3);	
	Vector3F vec2 = vec - 1;
	ASSERT_FLOAT_EQ(vec2[0], 0);
	ASSERT_FLOAT_EQ(vec2[1], 1);
	ASSERT_FLOAT_EQ(vec2[2], 2);	
}
TEST(Vector3FTest, ScalarMultiplying)
{
	Vector3F vec(1,2,3);	
	Vector3F vec2 = vec * 2;
	ASSERT_FLOAT_EQ(vec2[0], 2);
	ASSERT_FLOAT_EQ(vec2[1], 4);
	ASSERT_FLOAT_EQ(vec2[2], 6);	
}
TEST(Vector3FTest, ScalarDividing)
{
	Vector3F vec(1,2,3);	
	Vector3F vec2 = vec / 2;
	ASSERT_FLOAT_EQ(vec2[0], .5f);
	ASSERT_FLOAT_EQ(vec2[1], 1);
	ASSERT_FLOAT_EQ(vec2[2], 1.5f);	
}
void unittest(int argc, char **argv)
{
	InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}