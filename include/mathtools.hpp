#pragma once

#include "primitives.hpp"
#include <cassert>

namespace yLab::geometry {

// |Dx-Ax Dy-Ay Dz-Az|
// |Dx-Bx Dy-By Dz-Bz|
// |Dx-Cx Dy-Cy Dz-Cz|
inline float determinant3x3(const Point_t &A, const Point_t &B, const Point_t &C, const Point_t &D) {
	assert(A.valid() && B.valid() && C.valid() && D.valid());
    
	float det = (D.x - A.x) * ((D.y - B.y)*(D.z - C.z) - (D.z - B.z)*(D.y - C.y));
	det += (D.y - A.y) * ((D.z - B.z)*(D.x - C.x) - (D.x - B.x)*(D.z - C.z));
	det += (D.z - A.z) * ((D.x - B.x)*(D.y - C.y) - (D.y - B.y)*(D.x - C.x));

	return det;
} 

}

