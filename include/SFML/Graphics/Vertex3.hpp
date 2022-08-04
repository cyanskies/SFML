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

#ifndef SFML_VERTEX3_HPP
#define SFML_VERTEX3_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Define a point with color and texture coordinates
///
////////////////////////////////////////////////////////////
class Vertex3
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vertex3();

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vertex from its position
    ///
    /// The vertex color is white and texture coordinates are (0, 0).
    ///
    /// \param thePosition Vertex3 position
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vertex3(const Vector3f& thePosition);

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vertex from its position and color
    ///
    /// The texture coordinates are (0, 0).
    ///
    /// \param thePosition Vertex3 position
    /// \param theColor    Vertex3 color
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vertex3(const Vector3f& thePosition, const Color& theColor);

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vertex from its position and texture coordinates
    ///
    /// The vertex color is white.
    ///
    /// \param thePosition  Vertex3 position
    /// \param theTexCoords Vertex3 texture coordinates
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vertex3(const Vector3f& thePosition, const Vector2f& theTexCoords);

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vertex from its position, color and texture coordinates
    ///
    /// \param thePosition  Vertex3 position
    /// \param theColor     Vertex3 color
    /// \param theTexCoords Vertex3 texture coordinates
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vertex3(const Vector3f& thePosition, const Color& theColor, const Vector2f& theTexCoords);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Vector3f position;  //!< 2D position of the vertex
    Color    color;     //!< Color of the vertex
    Vector2f texCoords; //!< Coordinates of the texture's pixel to map to the vertex
};

#include <SFML/Graphics/Vertex3.inl>

} // namespace sf

#endif // SFML_VERTEX_HPP
