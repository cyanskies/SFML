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
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transform3.hpp>
#include <SFML/System/Angle.hpp>

#include <cmath>


namespace sf
{
////////////////////////////////////////////////////////////
Transform3& Transform3::rotateX(Angle angle)
{
    float rad = angle.asRadians();
    float cos = std::cos(rad);
    float sin = std::sin(rad);

    // clang-format off
    Transform3 rotation(1,   0,    0, 0,
                        0, cos, -sin, 0,
                        0, sin,  cos, 0,
                        0,   0,    0, 1);
    // clang-format on

    return combine(rotation);
}

////////////////////////////////////////////////////////////
Transform3& Transform3::rotateY(Angle angle)
{
    float rad = angle.asRadians();
    float cos = std::cos(rad);
    float sin = std::sin(rad);

    // clang-format off
    Transform3 rotation( cos, 0, sin, 0,
                           0, 1,   0, 0,
                        -sin, 0, cos, 0,
                           0, 0,   0, 1);
    // clang-format on

    return combine(rotation);
}

///////////////////////////////////////////////////////////
Transform3& Transform3::rotateZ(Angle angle)
{
    float rad = angle.asRadians();
    float cos = std::cos(rad);
    float sin = std::sin(rad);

    // clang-format off
    Transform3 rotation(cos, -sin, 0, 0,
                        sin,  cos, 0, 0,
                        0,    0,   1, 0,
                        0,    0,   0, 1);
    // clang-format on

    return combine(rotation);
}

////////////////////////////////////////////////////////////
Transform3& Transform3::rotateX(Angle angle, const Vector3f& center)
{
    return combine(Transform3().translate(-center).rotateX(angle).translate(center));
}

////////////////////////////////////////////////////////////
Transform3& Transform3::rotateY(Angle angle, const Vector3f& center)
{
    return combine(Transform3().translate(-center).rotateY(angle).translate(center));
}


////////////////////////////////////////////////////////////
Transform3& Transform3::rotateZ(Angle angle, const Vector3f& center)
{
    return combine(Transform3().translate(-center).rotateZ(angle).translate(center));
}

} // namespace sf
