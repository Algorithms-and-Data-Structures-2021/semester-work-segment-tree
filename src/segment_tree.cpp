#include "segment_tree.hpp"

namespace itis {
  // потом определимся с методом проталкивания модификации

  SegmentTree::SegmentTree(int size, int *array) {

    size_ = size;
    array_ = array;
    tree_ = new int [4 * size_];
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
    delete [] array_;
    delete [] tree_;
    array_ = nullptr;
    tree_ = nullptr;
    size_ = 0;
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
