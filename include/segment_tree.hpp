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

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.
   public:

    SegmentTree(int size, int *array);

    ~SegmentTree();

    int get_min(int l, int r);

    int get_max(int l, int r);

    int get_sum(int l, int r);

    void update(int index, int value);

    [[maybe_unused]] int size() const;
  };

}  // namespace itis