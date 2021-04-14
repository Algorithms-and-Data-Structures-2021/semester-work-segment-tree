#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct MyStructure {
   public:
    int size_{0};
    int capacity_{0};
    int* data_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }


    // обертка над рекурсивной функцией поиска минимума get_min

    int dec_get_min(int l, int r){
      if (l >= 0 && r < size_ && r >= l){
        return get_min(l, r, 1, 0, size_-1);
      }
      throw std::logic_error("invalid borders entered");
    }


    // обертка над рекурсивной функцией поиска минимума get_max

    int dec_get_max(int l, int r){
      if (l >= 0 && r < size_ && r >= l){
        return get_min(l, r, 1, 0, size_-1);
      }
      throw std::logic_error('invalid borders entered');
    }

  };

}  // namespace itis