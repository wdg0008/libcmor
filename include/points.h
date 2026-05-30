/*!
 * \file points.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Contains code for manipulating representations of points in 3D space
 * \version 0.1
 * \date 2026-05-22
 * 
 * \copyright Copyright (c) 2026
 * 
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Point3D {
    double x;
    double y;
    double z;
} Vec3D;

extern Vec3D v3d_0; // (0, 0, 0)

// basis elements
extern Vec3D v3d_e1; // (1, 0 ,0)
extern Vec3D v3d_e2; // (0, 1, 0)
extern Vec3D v3d_e3; // (0, 0, 1)

Vec3D v3d_add(const Vec3D *a, const Vec3D *b);

Vec3D v3d_sub(const Vec3D *a, const Vec3D *b);

Vec3D v3d_scale(const Vec3D *v, double s);

double v3d_mag(const Vec3D *v);

double v3d_dot(const Vec3D *a, const Vec3D *b);

Vec3D v3d_cross(const Vec3D *a, const Vec3D *b);

double v3d_angle(const Vec3D *a, const Vec3D *b);

#ifdef __cplusplus
}
#endif