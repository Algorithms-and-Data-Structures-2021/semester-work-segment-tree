#include <iostream>
#include <math.h>
#include "ctime"
#include <iomanip>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "segment_tree.hpp"



std::vector<int> split(const std::string &s, char delimiter) {
  std::vector<int> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}
int* get_array(const std::vector<int>& vec){
  auto *array = new int [vec.size()];
  for (unsigned i = 0; i < vec.size(); i++) {
    array[i] = vec[i];
  }
  return array;
}


std::string process_data(int iter) {
  std::string absolutePathToInputFile = "dataset/data/Random_" + std::to_string(iter) + ".csv";
  std::ifstream file(absolutePathToInputFile);
  std::string result = "";
  std::string line;

  while (getline(file, line)) {
    // create structure here
    std::vector<int> intValues = split(line, ',');
    result = std::to_string(intValues.size()) + ",";

    itis::SegmentTree s = itis::SegmentTree(intValues.size(), get_array(intValues));

    double startTime = clock();
//    s.get_max(0, );

    double endTime = clock();
    std::cout << result << std::to_string(endTime - startTime) + "\n";
  }
  file.close();
  return result;
}

int main()
{
  int amount = 100;
  for (int i = 0; i < 10; i++) {
    process_data(amount);

    if (i % 2 == 0) {
      amount *= 5;
    } else {
      amount *= 2;
    }
  }

  return 0;
}
