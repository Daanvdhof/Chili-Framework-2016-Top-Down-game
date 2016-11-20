#include "Utilities.h"

int Constraint(int n, int lower, int upper)
{
	if (n > upper)
		return upper;

	if (n < lower)
		return lower;

	return n;
}

float Constraint(float n, float lower, float upper)
{
	if (n > upper)
		return upper;

	if (n < lower)
		return lower;

	return n;
}

void Swap(int* n1, int* n2)
{
	int buffer = *n1;
	*n1 = *n2;
	*n2 = buffer;

}
void Swap(float* n1, float* n2)
{
	float buffer = *n1;
	*n1 = *n2;
	*n2 = buffer;
}
bool CheckCollision(int x1, int y1,int width1,int height1, int x2, int y2,int width2, int height2)
{

	return x1 + width1 > x2 &&
		x1 < x2 + width2  &&
		y1 + height1 > y2 &&
		y1 < y2 + height2;
}