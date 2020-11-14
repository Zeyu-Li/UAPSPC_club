#include <algorithm>
#include <iostream>

int main(){
  int v[30] = {1,1,2,32,2,4,234,1234,1324,1324,123,324,123,4132,412,34,12,532,5};
  std::sort(std::begin(v), std::end(v));
  for (auto i:v) 
  std::cout << i<<std::endl;
}