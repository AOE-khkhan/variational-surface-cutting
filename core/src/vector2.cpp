#include <vector2.h>
#include <utilities.h>

#include <cmath>
#include <iostream>

std::ostream &operator<<( std::ostream &output, const Vector2 &v )
{
    output << "<" << v.x << ", " << v.y << ">";
    return output;
}

