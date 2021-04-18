#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds

// подключаем вашу структуру данных
#include "segment_tree.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main() {
  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы

  // Можете передать путь до входного/выходного файла в качестве аргумента,
  // т.е. не обязательно использовать kDatasetPath и прочие константы

  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)
  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path + "database/insert/01/Random_100.csv"<< endl;

  int trials = 10;


  // Контрольный тест: операции добавления, удаления, поиска и пр. над структурой данных

  // Tip 3: время работы программы (или участка кода) можно осуществить
  // как изнутри программы (std::chrono), так и сторонними утилитами
  for (int i = 0; i < trials; i++) {
    {
      cout << "life is good" << endl;
      string line = "1";
      auto input_file = ifstream(path + "/database/insert/01/Random_100.csv");
//
//      // здесь находится участок кода, время которого необходимо замерить
      int count = 0;
      int value_now;
      int *array = new int[100];
      if (input_file) {
        getline(input_file, line);
        while (line != "") {
          array[count] = stoi(line);
          value_now = stoi(line);
          count++;
          getline(input_file, line);
          if (line == "") {
            break;
          }
        }
      }
      SegmentTree sTree = SegmentTree(count, array);
      const auto time_point_before = chrono::steady_clock::now();
//      cout << sTree.get_sum(0, 0, sTree.size() - 1, 0, sTree.size() - 1);
      const auto time_point_after = chrono::steady_clock::now();
      input_file.close();
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
      cout << i << endl;
      cout << "some_string" << endl;
      cout << time_elapsed_ns << endl;
      delete[] array;
    }
    cout << endl << endl;
  }
//  cout << "Time elapsed (ns): " << summ/trials << '\n';
//  -12618678560
  return 0;
}