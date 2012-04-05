#include "Colors.h"

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