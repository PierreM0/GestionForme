#ifndef EXCEPTION_FORME_H
#define EXCEPTION_FORME_H

struct ExceptionForme {
  int val;
  ExceptionForme(int val) : val(val){};

  static constexpr int AJOUT_IMPOSSIBLE = 0;
};

#endif // ! EXCEPTION_FORME_H
