#pragma once

#include "Vector3d.h"

namespace Math {
    
    //template <typename T>
    //T TemplateExample(T const & x) {
    //    return x;
    //}

    float dot(const Vector3d &a, const Vector3d &b) {
        return a.dot(b);
    }
}
