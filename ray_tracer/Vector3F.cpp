#include "Vector3F.h"

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