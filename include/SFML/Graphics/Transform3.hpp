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

#ifndef SFML_TRANSFORM_HPP
#define SFML_TRANSFORM_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.hpp>

#include <SFML/System/Vector3.hpp>

namespace sf
{
class Angle;

////////////////////////////////////////////////////////////
/// \brief Define a 4x4 transform matrix
///
////////////////////////////////////////////////////////////
class Transform3
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Creates an identity transform (a transform that does nothing).
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3();

    ////////////////////////////////////////////////////////////
    /// \brief Construct a transform from a 4x3 matrix
    ///
    /// \param a00 Element (0, 0) of the matrix
    /// \param a01 Element (0, 1) of the matrix
    /// \param a02 Element (0, 2) of the matrix
    /// \param a03 Element (0, 3) of the matrix
    /// \param a10 Element (1, 0) of the matrix
    /// \param a11 Element (1, 1) of the matrix
    /// \param a12 Element (1, 2) of the matrix
    /// \param a13 Element (1, 3) of the matrix
    /// \param a20 Element (2, 0) of the matrix
    /// \param a21 Element (2, 1) of the matrix
    /// \param a22 Element (2, 2) of the matrix
    /// \param a23 Element (2, 3) of the matrix
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3(float a00, float a01, float a02, float a03,
        float a10, float a11, float a12, float a13,
        float a20, float a21, float a22, float a23,
        float a30, float a31, float a32, float a33);

    ////////////////////////////////////////////////////////////
    /// \brief Return the transform as a 4x4 matrix
    ///
    /// This function returns a pointer to an array of 16 floats
    /// containing the transform elements as a 4x4 matrix, which
    /// is directly compatible with OpenGL functions.
    ///
    /// \code
    /// sf::Transform transform = ...;
    /// glLoadMatrixf(transform.getMatrix());
    /// \endcode
    ///
    /// \return Pointer to a 4x4 matrix
    ///
    ////////////////////////////////////////////////////////////
    constexpr const float* getMatrix() const;

    ////////////////////////////////////////////////////////////
    /// \brief Return the inverse of the transform
    ///
    /// If the inverse cannot be computed, an identity transform
    /// is returned.
    ///
    /// \return A new transform which is the inverse of self
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3 getInverse() const;

    ////////////////////////////////////////////////////////////
    /// \brief Transform a 2D point
    ///
    /// These two statements are equivalent:
    /// \code
    /// sf::Vector2f transformedPoint = matrix.transformPoint(point);
    /// sf::Vector2f transformedPoint = matrix * point;
    /// \endcode
    ///
    /// \param point Point to transform
    ///
    /// \return Transformed point
    ///
    ////////////////////////////////////////////////////////////
    constexpr Vector3f transformPoint(const Vector3f& point) const;

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with another one
    ///
    /// The result is a transform that is equivalent to applying
    /// \a transform followed by *this. Mathematically, it is
    /// equivalent to a matrix multiplication (*this) * transform.
    ///
    /// These two statements are equivalent:
    /// \code
    /// left.combine(right);
    /// left *= right;
    /// \endcode
    ///
    /// \param transform Transform to combine with this transform
    ///
    /// \return Reference to *this
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3& combine(const Transform3& transform);

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with a translation
    ///
    /// This function returns a reference to *this, so that calls
    /// can be chained.
    /// \code
    /// sf::Transform transform;
    /// transform.translate(sf::Vector2f(100, 200)).rotate(sf::degrees(45));
    /// \endcode
    ///
    /// \param offset Translation offset to apply
    ///
    /// \return Reference to *this
    ///
    /// \see rotate, scale
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3& translate(const Vector3f& offset);

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with a rotation
    ///
    /// This function returns a reference to *this, so that calls
    /// can be chained.
    /// \code
    /// sf::Transform transform;
    /// transform.rotate(sf::degrees(90)).translate(50, 20);
    /// \endcode
    ///
    /// \param angle Rotation angle
    ///
    /// \return Reference to *this
    ///
    /// \see translate, scale
    ///
    ////////////////////////////////////////////////////////////
    SFML_GRAPHICS_API Transform3& rotateX(Angle angle);
    SFML_GRAPHICS_API Transform3& rotateY(Angle angle);
    SFML_GRAPHICS_API Transform3& rotateZ(Angle angle);

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with a rotation
    ///
    /// The center of rotation is provided for convenience as a second
    /// argument, so that you can build rotations around arbitrary points
    /// more easily (and efficiently) than the usual
    /// translate(-center).rotate(angle).translate(center).
    ///
    /// This function returns a reference to *this, so that calls
    /// can be chained.
    /// \code
    /// sf::Transform transform;
    /// transform.rotate(sf::degrees(90), sf::Vector2f(8, 3)).translate(sf::Vector2f(50, 20));
    /// \endcode
    ///
    /// \param angle Rotation angle
    /// \param center Center of rotation
    ///
    /// \return Reference to *this
    ///
    /// \see translate, scale
    ///
    ////////////////////////////////////////////////////////////
    SFML_GRAPHICS_API Transform3& rotateX(Angle angle, const Vector3f& center);
    SFML_GRAPHICS_API Transform3& rotateY(Angle angle, const Vector3f& center);
    SFML_GRAPHICS_API Transform3& rotateZ(Angle angle, const Vector3f& center);

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with a scaling
    ///
    /// This function returns a reference to *this, so that calls
    /// can be chained.
    /// \code
    /// sf::Transform transform;
    /// transform.scale(sf::Vector2f(2, 1)).rotate(sf::degrees(45));
    /// \endcode
    ///
    /// \param factors Scaling factors
    ///
    /// \return Reference to *this
    ///
    /// \see translate, rotate
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3& scale(const Vector3f& factors);

    ////////////////////////////////////////////////////////////
    /// \brief Combine the current transform with a scaling
    ///
    /// The center of scaling is provided for convenience as a second
    /// argument, so that you can build scaling around arbitrary points
    /// more easily (and efficiently) than the usual
    /// translate(-center).scale(factors).translate(center).
    ///
    /// This function returns a reference to *this, so that calls
    /// can be chained.
    /// \code
    /// sf::Transform transform;
    /// transform.scale(sf::Vector2f(2, 1), sf::Vector2f(8, 3)).rotate(45);
    /// \endcode
    ///
    /// \param factors Scaling factors
    /// \param center Center of scaling
    ///
    /// \return Reference to *this
    ///
    /// \see translate, rotate
    ///
    ////////////////////////////////////////////////////////////
    constexpr Transform3& scale(const Vector3f& factors, const Vector3f& center);

    ////////////////////////////////////////////////////////////
    // Static member data
    ////////////////////////////////////////////////////////////
    static const Transform3 Identity; //!< The identity transform (does nothing)

private:
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    float m_matrix[16]; //!< 4x4 matrix defining the transformation
};

////////////////////////////////////////////////////////////
/// \relates sf::Transform
/// \brief Overload of binary operator * to combine two transforms
///
/// This call is equivalent to calling Transform(left).combine(right).
///
/// \param left Left operand (the first transform)
/// \param right Right operand (the second transform)
///
/// \return New combined transform
///
////////////////////////////////////////////////////////////
constexpr Transform3 operator*(const Transform3& left, const Transform3& right);

////////////////////////////////////////////////////////////
/// \relates sf::Transform
/// \brief Overload of binary operator *= to combine two transforms
///
/// This call is equivalent to calling left.combine(right).
///
/// \param left Left operand (the first transform)
/// \param right Right operand (the second transform)
///
/// \return The combined transform
///
////////////////////////////////////////////////////////////
constexpr Transform3& operator*=(Transform3& left, const Transform3& right);

////////////////////////////////////////////////////////////
/// \relates sf::Transform
/// \brief Overload of binary operator * to transform a point
///
/// This call is equivalent to calling left.transformPoint(right).
///
/// \param left Left operand (the transform)
/// \param right Right operand (the point to transform)
///
/// \return New transformed point
///
////////////////////////////////////////////////////////////
constexpr Vector3f operator*(const Transform3& left, const Vector3f& right);

////////////////////////////////////////////////////////////
/// \relates sf::Transform
/// \brief Overload of binary operator == to compare two transforms
///
/// Performs an element-wise comparison of the elements of the
/// left transform with the elements of the right transform.
///
/// \param left Left operand (the first transform)
/// \param right Right operand (the second transform)
///
/// \return true if the transforms are equal, false otherwise
///
////////////////////////////////////////////////////////////
[[nodiscard]] constexpr bool operator==(const Transform3& left, const Transform3& right);

////////////////////////////////////////////////////////////
/// \relates sf::Transform
/// \brief Overload of binary operator != to compare two transforms
///
/// This call is equivalent to !(left == right).
///
/// \param left Left operand (the first transform)
/// \param right Right operand (the second transform)
///
/// \return true if the transforms are not equal, false otherwise
///
////////////////////////////////////////////////////////////
[[nodiscard]] constexpr bool operator!=(const Transform3& left, const Transform3& right);

#include <SFML/Graphics/Transform3.inl>

} // namespace sf


#endif // SFML_TRANSFORM_HPP


////////////////////////////////////////////////////////////
/// \class sf::Transform
/// \ingroup graphics
///
/// A sf::Transform specifies how to translate, rotate, scale,
/// shear, project, whatever things. In mathematical terms, it defines
/// how to transform a coordinate system into another.
///
/// For example, if you apply a rotation transform to a sprite, the
/// result will be a rotated sprite. And anything that is transformed
/// by this rotation transform will be rotated the same way, according
/// to its initial position.
///
/// Transforms are typically used for drawing. But they can also be
/// used for any computation that requires to transform points between
/// the local and global coordinate systems of an entity (like collision
/// detection).
///
/// Example:
/// \code
/// // define a translation transform
/// sf::Transform translation;
/// translation.translate(20, 50);
///
/// // define a rotation transform
/// sf::Transform rotation;
/// rotation.rotate(45);
///
/// // combine them
/// sf::Transform transform = translation * rotation;
///
/// // use the result to transform stuff...
/// sf::Vector2f point = transform.transformPoint(10, 20);
/// sf::FloatRect rect = transform.transformRect(sf::FloatRect(0, 0, 10, 100));
/// \endcode
///
/// \see sf::Transformable, sf::RenderStates
///
////////////////////////////////////////////////////////////
