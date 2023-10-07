#pragma once

#include "primitives.hpp"
#include <cassert>

// |Dx-Ax Dy-Ay Dz-Az|
// |Dx-Bx Dy-By Dz-Bz|
// |Dx-Cx Dy-Cy Dz-Cz|
float determinant3x3(Point_t &A, Point_t &B, Point_t &C, Point_t &D) {
	assert(valid(A) && valid(B) && valid(C) && valid(D));
    float det = 0;
	
	det += (D.x - A.x) * ((D.y - B.y)*(D.z - C.z) - (D.z - B.z)*(D.y - C.y));
	det += (D.y - A.y) * ((D.z - B.z)*(D.x - C.x) - (D.x - B.x)*(D.z - C.z));
	det += (D.z - A.z) * ((D.x - B.x)*(D.y - C.y) - (D.y - B.y)*(D.x - C.x));

	return det;
} 

float magicDeterminant3(struct NODE* A, struct NODE* B, struct NODE* C, struct NODE* D){
	float out=0;

	out+=(D->x-A->x)*((D->y-B->y)*(D->z-C->z)-(D->z-B->z)*(D->y-C->y));
	out+=(D->y-A->y)*((D->z-B->z)*(D->x-C->x)-(D->x-B->x)*(D->z-C->z));
	out+=(D->z-A->z)*((D->x-B->x)*(D->y-C->y)-(D->y-B->y)*(D->x-C->x));
	
	return out;	
}