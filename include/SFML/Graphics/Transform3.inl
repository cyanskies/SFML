////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2022 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// clang-format off
constexpr Transform3::Transform3()
    // Identity matrix
    : m_matrix{1.f, 0.f, 0.f, 0.f,
               0.f, 1.f, 0.f, 0.f,
               0.f, 0.f, 1.f, 0.f,
               0.f, 0.f, 0.f, 1.f}
{
}
// clang-format on


////////////////////////////////////////////////////////////
// clang-format off
constexpr Transform3::Transform3(float a00, float a01, float a02, float a03,
                               float a10, float a11, float a12, float a13,
                               float a20, float a21, float a22, float a23,
                               float a30, float a31, float a32, float a33)
    : m_matrix{a00, a10, a20, a30,
               a01, a11, a21, a31,
               a02, a12, a22, a32,
               a03, a13, a23, a33}
{
}
// clang-format on


////////////////////////////////////////////////////////////
constexpr const float* Transform3::getMatrix() const
{
    return m_matrix;
}


////////////////////////////////////////////////////////////
// clang-format off
constexpr Transform3 Transform3::getInverse() const
{
    const auto& m = m_matrix;
    
    const float a2323 = m[10] * m[15] - m[14] * m[11];
    const float a1323 = m[6]  * m[15] - m[14] * m[7];
    const float a1223 = m[6]  * m[11] - m[10] * m[7];
    const float a0323 = m[2]  * m[15] - m[14] * m[3];
    const float a0223 = m[2]  * m[11] - m[10] * m[3];
    const float a0123 = m[2]  * m[7]  - m[6]  * m[3];
    const float a2313 = m[9]  * m[15] - m[13] * m[11];
    const float a1313 = m[5]  * m[15] - m[13] * m[7];
    const float a1213 = m[5]  * m[11] - m[9]  * m[7];
    const float a2312 = m[9]  * m[14] - m[13] * m[10];
    const float a1312 = m[5]  * m[14] - m[13] * m[6];
    const float a1212 = m[5]  * m[10] - m[9]  * m[6];
    const float a0313 = m[1]  * m[15] - m[13] * m[3];
    const float a0213 = m[1]  * m[11] - m[9]  * m[3];
    const float a0312 = m[1]  * m[14] - m[13] * m[2];
    const float a0212 = m[1]  * m[10] - m[9]  * m[2];
    const float a0113 = m[1]  * m[7]  - m[5]  * m[3];
    const float a0112 = m[1]  * m[6]  - m[5]  * m[2];

    float det = m[0] * (m[5] * a2323 - m[9] * a1323 + m[13] * a1223) -
                m[1] * (m[1] * a2323 - m[9] * a0323 + m[13] * a0223) +
                m[2] * (m[1] * a1323 - m[5] * a0323 + m[13] * a0123) -
                m[3] * (m[1] * a1223 - m[5] * a0223 + m[9] * a0123);
    
    if(det != 0.f)
    {
        det = 1 / det;
        return Transform3(
            det *  (m[5] * a2323 - m[9] * a1323 + m[13] * a1223),
            det * -(m[1] * a2323 - m[2] * a1323 + m[3]  * a1223),
            det *  (m[1] * a2313 - m[2] * a1313 + m[3]  * a1213),
            det * -(m[1] * a2312 - m[2] * a1312 + m[3]  * a1212),
            det * -(m[1] * a2323 - m[9] * a0323 + m[13] * a0223),
            det *  (m[0] * a2323 - m[2] * a0323 + m[3]  * a0223),
            det * -(m[0] * a2313 - m[2] * a0313 + m[3]  * a0213),
            det *  (m[0] * a2312 - m[2] * a0312 + m[3]  * a0212),
            det *  (m[1] * a1323 - m[5] * a0323 + m[13] * a0123),
            det * -(m[0] * a1323 - m[1] * a0323 + m[3]  * a0123),
            det *  (m[0] * a1313 - m[1] * a0313 + m[3]  * a0113),
            det * -(m[0] * a1312 - m[1] * a0312 + m[3]  * a0112),
            det * -(m[1] * a1223 - m[5] * a0223 + m[9]  * a0123),
            det *  (m[0] * a1223 - m[1] * a0223 + m[2]  * a0123),
            det * -(m[0] * a1213 - m[1] * a0213 + m[2]  * a0113),
            det *  (m[0] * a1212 - m[1] * a0212 + m[2]  * a0112)
        );
    }
    else
    {
        return Identity;
    }
}
// clang-format on


////////////////////////////////////////////////////////////
constexpr Vector3f Transform3::transformPoint(const Vector3f& point) const
{
    return Vector3f(m_matrix[0] * point.x + m_matrix[4] * point.y + m_matrix[8]  * point.z + m_matrix[12],
                    m_matrix[1] * point.x + m_matrix[5] * point.y + m_matrix[9]  * point.z + m_matrix[13],
                    m_matrix[2] * point.x + m_matrix[6] * point.y + m_matrix[10] * point.z + m_matrix[14]);
}


////////////////////////////////////////////////////////////
constexpr Transform3& Transform3::combine(const Transform3& transform)
{
    const float* a = m_matrix;
    const float* b = transform.m_matrix;

     // clang-format off
    *this = Transform3(
        a[0] * b[0] + a[1] * b[4] + a[2] * b[8]  + a[3] * b[12],
        a[0] * b[1] + a[1] * b[5] + a[2] * b[9]  + a[3] * b[13],
        a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14],
        a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15],

        a[4] * b[0] + a[5] * b[4] + a[6] * b[8]  + a[7] * b[12],
        a[4] * b[1] + a[5] * b[5] + a[6] * b[9]  + a[7] * b[13],
        a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14],
        a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15],

        a[8] * b[0] + a[9] * b[4] + a[10] * b[8]  + a[11] * b[12],
        a[8] * b[1] + a[9] * b[5] + a[10] * b[9]  + a[11] * b[13],
        a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14],
        a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15],

        a[12] * b[0] + a[13] * b[4] + a[14] * b[8]  + a[15] * b[12],
        a[12] * b[1] + a[13] * b[5] + a[14] * b[9]  + a[15] * b[13],
        a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14],
        a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15]);
    // clang-format on

    return *this;
}


////////////////////////////////////////////////////////////
constexpr Transform3& Transform3::translate(const Vector3f& offset)
{
    // clang-format off
    Transform3 translation(1, 0, 0, offset.x,
                           0, 1, 0, offset.y,
                           0, 0, 1, offset.z,
                           0, 0, 0, 1);
    // clang-format on

    return combine(translation);
}


////////////////////////////////////////////////////////////
constexpr Transform3& Transform3::scale(const Vector3f& factors)
{
    // clang-format off
    Transform3 scaling( factors.x, 0,         0,         0,
                        0,         factors.y, 0,         0,
                        0,         0,         factors.z, 0,
                        0,         0,         0,         1);
    // clang-format on

    return combine(scaling);
}


////////////////////////////////////////////////////////////
constexpr Transform3& Transform3::scale(const Vector3f& factors, const Vector3f& center)
{
    // clang-format off
    Transform3 scaling(factors.x, 0,         0,         center.x * (1 - factors.x),
                       0,         factors.y, 0,         center.y * (1 - factors.y),
                       0,         0,         factors.z, center.z * (1 - factors.z),
                       0,         0,         0,         1);
    // clang-format on

    return combine(scaling);
}


////////////////////////////////////////////////////////////
constexpr Transform3 operator*(const Transform3& left, const Transform3& right)
{
    return Transform3(left).combine(right);
}


////////////////////////////////////////////////////////////
constexpr Transform3& operator*=(Transform3& left, const Transform3& right)
{
    return left.combine(right);
}


////////////////////////////////////////////////////////////
constexpr Vector3f operator*(const Transform3& left, const Vector3f& right)
{
    return left.transformPoint(right);
}


////////////////////////////////////////////////////////////
constexpr bool operator==(const Transform3& left, const Transform3& right)
{
    const float* a = left.getMatrix();
    const float* b = right.getMatrix();

    // clang-format off
    return ((a[0]  == b[0])  && (a[1]  == b[1])  && (a[2] == b[2])   && (a[3]  == b[3])  &&
            (a[4]  == b[4])  && (a[5]  == b[5])  && (a[6] == b[6])   && (a[7]  == b[7])  &&
            (a[8]  == b[8])  && (a[9]  == b[9])  && (a[10] == b[10]) && (a[11] == b[11]) &&
            (a[12] == b[12]) && (a[13] == b[13]) && (a[14] == b[14]) && (a[15] == b[15]));
    // clang-format on
}


////////////////////////////////////////////////////////////
constexpr bool operator!=(const Transform3& left, const Transform3& right)
{
    return !(left == right);
}


////////////////////////////////////////////////////////////
// Static member data
////////////////////////////////////////////////////////////

// Note: the 'inline' keyword here is technically not required, but VS2019 fails
// to compile with a bogus "multiple definition" error if not explicitly used.
inline constexpr Transform3 Transform3::Identity;
