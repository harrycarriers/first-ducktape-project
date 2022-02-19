/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Ducktape/engine/vector2.h>
using namespace DT;

Vector2::Vector2()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float xpos, float ypos)
{
    x = xpos;
    y = ypos;
}

Vector2 Vector2::operator+(Vector2 vec2)
{
    return Vector2(x + vec2.x, y + vec2.y);
}

Vector2 Vector2::operator-(Vector2 vec2)
{
    return Vector2(x - vec2.x, y - vec2.y);
}

Vector2 Vector2::operator*(float val)
{
    return Vector2(x * val, y * val);
}

Vector2 Vector2::operator/(float val)
{
    return Vector2(x / val, y / val);
}

Vector2 &Vector2::operator=(Vector2 vec)
{
    x = vec.x;
    y = vec.y;
    return *this;
}

bool Vector2::operator==(Vector2 vec)
{
    if (Mathf::Approximately(x, vec.x) && Mathf::Approximately(y, vec.y))
    {
        return true;
    }
    return false;
}

float Vector2::Magnitude()
{
    return Mathf::Sqrt((x * x) + (y * y));
}

const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
const Vector2 Vector2::UP = Vector2(0.0f, 1.0f);
const Vector2 Vector2::DOWN = Vector2(0.0f, -1.0f);
const Vector2 Vector2::LEFT = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);
const Vector2 Vector2::ONE = Vector2(1.0f, 1.0f);
const Vector2 Vector2::NEGATIVE_INFINITY = Vector2(Mathf::NegativeInfinity, Mathf::NegativeInfinity);
const Vector2 Vector2::POSITIVE_INFINITY = Vector2(Mathf::PositiveInfinity, Mathf::PositiveInfinity);

Vector2 Vector2::Normalized()
{
    float mag = Magnitude();
    return Vector2(x / mag, y / mag);
}

float Vector2::SqrMagnitude()
{
    return (x * x) + (y * y);
}

float Vector2::Distance(Vector2 vec1, Vector2 vec2)
{
    return (vec2 - vec1).Magnitude();
}

Vector2 Vector2::Lerp(Vector2 start, Vector2 target, float delta)
{
    return Vector2(Mathf::Lerp(start.x, target.x, delta), Mathf::Lerp(start.y, target.y, delta));
}

Vector2 Vector2::Max(Vector2 vec1, Vector2 vec2)
{
    return Vector2(Mathf::Max(vec1.x, vec2.x), Mathf::Max(vec1.y, vec2.y));
}

Vector2 Vector2::Min(Vector2 vec1, Vector2 vec2)
{
    return Vector2(Mathf::Min(vec1.x, vec2.x), Mathf::Min(vec1.y, vec2.y));
}

Vector2 Vector2::MoveTowards(Vector2 value, Vector2 target, float delta)
{
    return Vector2(Mathf::MoveTowards(value.x, target.x, delta), Mathf::MoveTowards(value.y, target.y, delta));
}

std::ostream &operator<<(std::ostream &out, const Vector2 &vec)
{
    out << "Vector2(" + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ")";
    return out;
}

std::istream &operator>>(std::istream &in, Vector2 &vec)
{
    in >> vec.x;
    in >> vec.y;
    return in;
}

Vector2::operator std::string() const
{
    return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2::operator sf::Vector2f() const
{
    return sf::Vector2f(x, y);
}

Vector2::operator b2Vec2() const
{
    return b2Vec2(x, y);
}