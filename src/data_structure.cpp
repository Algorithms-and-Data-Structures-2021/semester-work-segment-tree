#include "data_structure.hpp"

// файл с определениями

namespace itis {

  int get_min(int l, int r, int tl, int tr) {
    // границы текущего отрезка лежат в границах запроса
    if (l <= tl && tr <= r) && (tl==tr){
      return tree[tl];
    }

    // границы текущего отрезка полностью выходят за границы запроса
    if (tr < l || r < tl) {
      return INT_MAX;
    }

    // границы текущего отрезка частично в границах запроса
    int tm = (tl + tr) / 2;
    return min(get_min(l, r, v * 2 + 1, tl, tm),
               get_min(l, r, v * 2 + 2, tm + 1, tr));


    int get_max(int l, int r, int tl, int tr) {
      // границы текущего отрезка лежат в границах запроса
      if (l <= tl && tr <= r) && (tl==tr){
        return tree[tl];
      }

      // границы текущего отрезка полностью выходят за границы запроса
      if (tr < l || r < tl) {
        return INT_MIN;
      }

      // границы текущего отрезка частично в границах запроса
      int tm = (tl + tr) / 2;
      return max(get_max(l, r, v * 2 + 1, tl, tm),
                 get_max(l, r, v * 2 + 2, tm + 1, tr));

}  // namespace itis