#include <vector>


#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct SegmentTree {
   private:
    int size_ {0};
    int *array_ {nullptr};
    int *tree_ {nullptr};
    int *modification_ {nullptr};

    void build_tree_(int vert, int lp, int rp);

    void push_changes_(int vert);

   public:
    SegmentTree(int size, int *array);

    ~SegmentTree();

    int get_min(int l, int r, int vert, int lp, int rp);

    int get_max(int l, int r, int vert, int lp, int rp);

    int get_sum(int vert, int tl, int tr, int lp, int rp);

    void update(int vert, int lp, int rp, int index, int new_value);

    void assign(int l, int r, int val, int vert, int lp, int rp);

    int size() const;

    void print_tree() const;
  };

}  // namespace itis