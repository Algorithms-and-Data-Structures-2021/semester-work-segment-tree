#include "segment_tree.hpp"

namespace itis {
  // потом определимся с методом проталкивания модификации

  SegmentTree::SegmentTree(int size, int *array) {
    size_ = size;
    array_ = array;
    tree_ = new int [4 * size_];
    modification_ = new int [4 * size_] {};
    SegmentTree::build_tree_(0, 0, size_);
  }

  void SegmentTree::build_tree_(int vert, int lp, int rp) {
    if (lp == rp) {
      tree_[vert] = array_[lp];
    } else {
      int tm = (lp + rp) / 2;
      SegmentTree::build_tree_(vert * 2 + 1, lp, tm); // 
      SegmentTree::build_tree_(vert * 2 + 2, tm + 1, rp);
      tree_[vert] = tree_[vert * 2 + 1] + tree_[vert * 2 + 2];
    }
  }

  SegmentTree::~SegmentTree() {
    delete [] modification_;
    delete [] array_;
    delete [] tree_;
    modification_ = nullptr;
    array_ = nullptr;
    tree_ = nullptr;
    size_ = 0;
  }

  void SegmentTree::push_changes_(int vert, int lp, int rp) {
    if ((modification_[vert] != 0) || (vert * 2 + 2 < 4 * size_)) {
      modification_[vert * 2 + 1] = modification_[vert * 2 + 2] = modification_[vert];
      modification_[vert] = 0;

      tree_[vert * 2 + 1] = tree_[vert * 2 + 1] * modification_[vert * 2 + 1];
      tree_[vert * 2 + 2] = tree_[vert * 2 + 2] * modification_[vert * 2 + 2];
    }
  }

  void SegmentTree::assign(int l, int r, int val, int vert, int lp, int rp) {
    if (l >= lp && r <= rp) {
      tree_[vert] = val * (rp - lp + 1);
      modification_[vert] = val;
      return;
    }

    if (rp < l || r < lp) {
      return;
    }

    SegmentTree::push_changes_(vert, l, r);
    int m = (l + r) / 2;
    SegmentTree::assign(l, m, val, vert * 2 + 1, lp, rp);
    SegmentTree::assign(m + 1, r, val, vert * 2 + 2, lp, rp);
    tree_[vert] = tree_[vert * 2 + 1] + tree_[vert * 2 + 2];
  }

  int SegmentTree::get_min(int l, int r) {
    // TODO получение минимума на отрезке
    //  мне кажется только границ поиска достаточно,
    //  проверять не вышли ли мы за пределы можно с помощю фукции сайз и просто 0
  }

  int SegmentTree::get_max(int l, int r) {
    // TODO получение максимума на отрезке
  }

  int SegmentTree::get_sum(int l, int r) {
    // TODO получение суммы на отрезке
  }

  void SegmentTree::update(int index, int value) {
    // TODO обновление элемента
  }

  [[maybe_unused]] int SegmentTree::size() const {
    // [[maybe_unused]] - прикольная фишка, впервые увидел
    return size_;
  }

}  // namespace itis
