#pragma once
#include <cassert>
#include <math.h>
#include <ostream>
class Vector3F
{
protected:
	float elems[3];
public:
	inline Vector3F(void)
	{
		for(int i = 0; i < 3; i++)
				elems[i] = .0f;
	}
	inline Vector3F(float x,float y, float z)
	{
		elems[0] = x; elems[1] = y; elems[2] = z;
	}

	inline float getElem(int i) { assert(i >= 0); assert( i < 3); return elems[i];};
	inline float operator[] (int i) const {	assert(i >= 0); assert( i < 3);	return elems[i];}
	inline float & operator[] (int i) {	assert(i >= 0); assert( i < 3);	return elems[i];}	
	inline const Vector3F operator-() const { return Vector3F(-elems[0],-elems[1],-elems[2]);};
	
	inline Vector3F & operator+= (float factor)
	{
		for(int i = 0; i < 3; i++)
			elems[i] += factor;
		return *this;
	}
	inline Vector3F & operator-= (float factor)
	{
		for(int i = 0; i < 3; i++)
			elems[i] -= factor;
		return *this;
	}
	inline Vector3F & operator*= (float factor)
	{
		for(int i = 0; i < 3; i++)
			elems[i] *= factor;
		return *this;
	}
	inline Vector3F & operator/= (float factor)
	{
		for(int i = 0; i < 3; i++)
			elems[i] /= factor;
		return *this;
	}
	friend const Vector3F operator* (float s, const Vector3F &v);
	friend const Vector3F operator* (const Vector3F &v, float s);
	friend const float operator* (const Vector3F &v, const Vector3F &v2);
	friend const Vector3F operator% (const Vector3F &v, const Vector3F &v2);
	friend const Vector3F operator/ (const Vector3F &v, float s);
	friend const Vector3F operator+ (const Vector3F &v, float s);
	friend const Vector3F operator- (const Vector3F &v, float s);
	friend std::ostream & operator<< (std::ostream &os,const Vector3F  &v);
	inline float magnitude_squared() 
	{
		return sqrtf(*this * *this);
	}
	inline float magnitude() 
	{
		return *this * *this;
	}
	inline  const Vector3F normalize() 
	{
		float t = this->magnitude_squared();
		return Vector3F(elems[0]/t,elems[1]/t,elems[2]/t);
	}
};

std::ostream & operator<< (std::ostream &os,const Vector3F  &v)
{
	os << "(" << v[0] << ", "
			  << v[1] << ", "
			  << v[2] << ")";
	return os;
}

const Vector3F operator* (float s, const Vector3F &v)
{
	return Vector3F(v[0]*s,v[1]*s,v[2]*s);
}
const Vector3F operator* (const Vector3F &v, float s)
{
	return Vector3F(v[0]*s,v[1]*s,v[2]*s);
}
const Vector3F operator/ (const Vector3F &v, float s)
{
	return Vector3F(v[0]/s,v[1]/s,v[2]/s);
}
const Vector3F operator+ (const Vector3F &v, float s)
{
	return Vector3F(v[0]+s,v[1]+s,v[2]+s);
}
const Vector3F operator- (const Vector3F &v, float s)
{
	return Vector3F(v[0]-s,v[1]-s,v[2]-s);
}

const float operator* (const Vector3F &v, const Vector3F &v2)
{
	return (v[0]*v2[0]+v[1]*v2[1]+v[2]*v2[2]);
}

const Vector3F operator% (const Vector3F &v, const Vector3F &v2)
{
	Vector3F temp;
	temp[0] = v[1]*v2[2] - v[2]*v2[1];
	temp[1] = v[2]*v2[0] - v[0]*v2[2];
	temp[2] = v[0]*v2[1] - v[1]*v2[0];
	return temp;
}