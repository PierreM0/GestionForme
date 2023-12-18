#ifndef EXCEPTION_GEOMETRIE_PLANE_H
#define EXCEPTION_GEOMETRIE_PLANE_H

struct ExceptionGeometriePlane {
  int val;
  ExceptionGeometriePlane(int val) : val(val){};

  static constexpr int DELTA_NEGATIF = 0;
  static constexpr int DETERMINANT_NUL = 1;
};

#endif // ! EXCEPTION_GEOMETRIE_PLANE_H
