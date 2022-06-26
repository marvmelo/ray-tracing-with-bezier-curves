#include <cmath>

using namespace std;

template <typename T>
class Vec3D
{
public:
    T x, y, z;
    Vec3D(T x, T y, T z) : x(x), y(y), z(z) {}
    Vec3D operator+ (const Vec3D<T>&);
    T operator^ (const Vec3D<T>&);
    Vec3D normalize ();
};

template <typename T>
Vec3D<T> Vec3D<T>::operator+ (const Vec3D<T>& B)
{
    Vec3D temp = Vec3D(x + B.x, y + B.y, z + B.z);
    return temp;
}

template <typename T>
T Vec3D<T>::operator^ (const Vec3D<T>& B)
{
    return x*B.x + y*B.y + z*B.z;
}

template <typename T>
Vec3D<T> operator* (const T& scalar, const Vec3D<T>& B)
{
    Vec3D temp = Vec3D(scalar*B.x, scalar*B.y, scalar*B.z);
    return temp;
}

template <typename T>
Vec3D<T> Vec3D<T>::normalize ()
{
    T s = sqrt(x*x + y*y + z*z);
    s = 1 / s;
    return s * this;
}
