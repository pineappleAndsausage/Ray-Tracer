#pragma once
#include <cassert>
#include <math.h>
#include <ostream>

class Colors
{
protected:
	float color[3];
public:
	inline Colors() 
	{ 
		for(int i = 0; i < 3; i++)
			color[i] = .0f;
	}
	inline Colors(float red, float green, float blue) 
	{ 
		color[0] = red;
		color[1] = green;
		color[2] = blue;
	}
	inline float get_red() { return color[0];}
	inline float get_green() { return color[1];}
	inline float get_blue() { return color[2];}	
	inline void set_red(float r) { color[0] = r;}
	inline void set_green(float g) { color[1] = g;}
	inline void set_blue(float b) { color[2] = b;}

	inline float operator[] (int i) const { assert( i >=0); assert(i < 3); return color[i];}
	inline float & operator[] (int i) { assert( i >=0); assert(i < 3); return color[i];}

	inline Colors & operator += (const Colors & c) 
	{
		for(int i = 0; i < 3; i++)
			color[i] += c[i];
		return *this;
	}
	inline Colors & operator -= (const Colors & c) 
	{
		for(int i = 0; i < 3; i++)
			color[i] -= c[i];
		return *this;
	}
	inline Colors & operator *= (const Colors & c) 
	{
		for(int i = 0; i < 3; i++)
			color[i] *= c[i];
		return *this;
	}
	inline Colors & operator *= (const float f) 
	{
		for(int i = 0; i < 3; i++)
			color[i] *= f;
		return *this;
	}
	inline Colors & operator /= (const float f) 
	{
		for(int i = 0; i < 3; i++)
			color[i] /= f;
		return *this;
	}
	friend std::ostream & operator << (std::ostream & os, const Colors & c);
	friend const Colors operator + (const Colors & c1, const Colors & c2);
	friend const Colors operator - (const Colors & c1, const Colors & c2);
	friend const Colors operator * (const Colors & c1, const Colors & c2);
	friend const Colors operator * (const Colors & c, const float f);
	friend const Colors operator * (const float f, const Colors & c);
	friend const Colors operator / (const Colors & c, const float f);
};
std::ostream & operator << (std::ostream & os, const Colors & c)
{
	os << "(" << c[0] << ", "
			  << c[1] << ", "
			  << c[2] << ")";
	return os;
}
const Colors operator + (const Colors &c1, const Colors &c2)
{
	return Colors(c1[0]+c2[0],c1[1]+c2[1],c1[2]+c2[2]);
}
const Colors operator - (const Colors &c1, const Colors &c2)
{
	return Colors(c1[0]-c2[0],c1[1]-c2[1],c1[2]-c2[2]);
}
const Colors operator * (const Colors &c1, const Colors &c2)
{
	return Colors(c1[0]*c2[0],c1[1]*c2[1],c1[2]*c2[2]);
}
const Colors operator * (const Colors &c, const float f)
{
	return Colors(c[0]*f,c[1]*f,c[2]*f);
}
const Colors operator * (const float f,const Colors &c)
{
	return Colors(c[0]*f,c[1]*f,c[2]*f);
}
const Colors operator / (const Colors &c, const float f)
{
	return Colors(c[0]/f,c[1]/f,c[2]/f);
}