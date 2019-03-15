#include <cmath>
#include "Tools.h"
#include "ImplicitQRSVD.h"

extern "C" {

void polar2(double *m, double *r, double *s) {
    Eigen::Matrix<double, 2, 2> A,R,S;

    A<<m[0],m[1],m[2],m[3];

    JIXIE::polarDecomposition(A, R, S);

    r[0] = R(0,0); r[1] = R(0,1);
    r[2] = R(1,0); r[3] = R(1,1);

    s[0] = S(0,0); s[1] = S(0,1);
    s[2] = S(1,0); s[3] = S(1,1);
}

void svd2(double *m, double *u, double *s, double *v) {
    Eigen::Matrix<double, 2, 2> A;
    Eigen::Matrix<double, 2, 2> U;
    Eigen::Matrix<double, 2, 1> S;
    Eigen::Matrix<double, 2, 2> V;

    A<<m[0],m[1],m[2],m[3];

    // Taichi safeguard: matrices close to diagonal make QR SVD crash
    if(m[1]*m[1] + m[2]*m[2] < 1.0e-7) {
        s[0] = m[0];
        s[1] = m[3];
        u[0] = u[3] = v[0] = v[3] = 1;
        u[1] = u[2] = v[1] = v[2] = 0;
    } else {
        JIXIE::singularValueDecomposition(A,U,S,V);

        u[0] = U(0,0); u[1] = U(0,1);
        u[2] = U(1,0); u[3] = U(1,1);

        s[0] = S(0,0); s[1] = S(1,0);

        v[0] = V(0,0); v[1] = V(0,1);
        v[2] = V(1,0); v[3] = V(1,1);
    }
}
void polar3(double *m, double *r, double *s) {
    Eigen::Matrix<double, 3, 3> A;
    Eigen::Matrix<double, 3, 3> R;
    Eigen::Matrix<double, 3, 3> S;

    A<<m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7],m[8];

    JIXIE::polarDecomposition(A, R, S);

    r[0] = R(0,0); r[1] = R(0,1); r[2] = R(0,2);
    r[3] = R(1,0); r[4] = R(1,1); r[5] = R(1,2);
    r[6] = R(2,0); r[7] = R(2,1); r[8] = R(2,2);

    s[0] = S(0,0); s[1] = S(0,1); s[2] = S(0,2);
    s[3] = S(1,0); s[4] = S(1,1); s[5] = S(1,2);
    s[6] = S(2,0); s[7] = S(2,1); s[8] = S(2,2);
}

void svd3(double *m, double *u, double *s, double *v) {
    Eigen::Matrix<double, 3, 3> A;
    Eigen::Matrix<double, 3, 3> U;
    Eigen::Matrix<double, 3, 1> S;
    Eigen::Matrix<double, 3, 3> V;

    A<<m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7],m[8];

    // Taichi safeguard: matrices close to diagonal make QR SVD crash
    if(m[1]*m[1] + m[2]*m[2] < 1.0e-7) {
        s[0] = m[0];
        s[1] = m[4];
        s[2] = m[8];
        u[0] = u[4] = u[8] = v[0] = v[4] = v[8] = 1;
        u[1] = u[2] = u[3] = u[5] = u[6] = u[7] = 0;
        v[1] = v[2] = v[3] = v[5] = v[6] = v[7] = 0;
    } else {
        JIXIE::singularValueDecomposition(A,U,S,V);

        u[0] = U(0,0); u[1] = U(0,1); u[2] = U(0,2);
        u[3] = U(1,0); u[4] = U(1,1); u[5] = U(1,2);
        u[6] = U(2,0); u[7] = U(2,1); u[8] = U(2,2);

        s[0] = S(0,0); s[1] = S(1,0); s[2] = S(2,0);

        v[0] = V(0,0); v[1] = V(0,1); v[2] = V(0,2);
        v[3] = V(1,0); v[4] = V(1,1); v[5] = V(1,2);
        v[6] = V(2,0); v[7] = V(2,1); v[8] = V(2,2);
    }
}
}