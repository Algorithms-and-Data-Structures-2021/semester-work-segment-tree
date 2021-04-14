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
    if (size_ != 0) {
      delete[] modification_;
      delete[] array_;
      delete[] tree_;
      modification_ = nullptr;
      array_ = nullptr;
      tree_ = nullptr;
      size_ = 0;
    }
  }

  void SegmentTree::push_changes_(int vert) {
    if ((modification_[vert] != 0) || (vert * 2 + 2 < 4 * size_)) {
      modification_[vert * 2 + 1] = modification_[vert * 2 + 2] = modification_[vert];
      tree_[vert] = tree_[vert] * modification_[vert];
      modification_[vert] = 0;
    }
  }

  void SegmentTree::assign(int l, int r, int val, int vert, int lp, int rp) {
    if (l >= lp && r <= rp) {
      tree_[vert] = val * tree_[vert];
      modification_[vert] = val;
      SegmentTree::push_changes_(vert);
      return;
    }

    if (rp < l || r < lp) {
      return;
    }

    SegmentTree::push_changes_(vert);
    int m = (l + r) / 2;
    SegmentTree::assign(l, m, val, vert * 2 + 1, lp, rp);
    SegmentTree::assign(m + 1, r, val, vert * 2 + 2, lp, rp);
    tree_[vert] = tree_[vert * 2 + 1] + tree_[vert * 2 + 2];
  }

  int SegmentTree::get_min(int l, int r, int lp, int rp) {
    // TODO получение минимума на отрезке
    //  мне кажется только границ поиска достаточно,
    //  проверять не вышли ли мы за пределы можно с помощю фукции сайз и просто 0
  }

  int SegmentTree::get_max(int l, int r, int lp, int rp) {
    // TODO получение максимума на отрезке
  }

  int SegmentTree::get_sum(int vert, int lp, int rp, int l, int r) {
    if (l > r)
      return 0;
    if (l == lp && r == rp)
      return tree_[vert];
    int mp = (lp + rp) / 2;
    int min_r = (r < mp) ? r : mp;
    int max_l = (l > mp+1) ? l : mp+1;
    return get_sum(vert*2, lp, mp, l, min_r) +
           get_sum(vert*2+1, mp+1, rp, max_l, r);
  }

  void SegmentTree::update(int vert, int lp, int rp, int index, int new_value) {
    if (lp == rp)
      tree_[vert] = new_value;
    else {
      int mp = (lp + rp) / 2;
      if (index <= mp)
        update(vert * 2, lp, mp, index, new_value);
      else
        update(vert * 2 + 1, mp + 1, rp, index, new_value);
      tree_[vert] = tree_[vert * 2] + tree_[vert * 2 + 1];
    }
  }

  [[maybe_unused]] int SegmentTree::size() const {
    // [[maybe_unused]] - прикольная фишка, впервые увидел
    return size_;
  }

}  // namespace itis
