/*
 * Problem: Trapping Rain Water
 * Given n non-negative integers representing an elevation map,
 * where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6
 * 
 * From:LeetCode 42 
 * URL:https://leetcode.com/problems/trapping-rain-water/description/
 * 
 */

#include <iostream>
#include <vector>

class Water{
public:
  Water(){}
  ~Water(){}
  int get_result(std::vector<int>& input);

private:
  int get_max_r(int n, std::vector<int>& input);
  int get_min(int a, int b);

  std::vector<int> v_max_r;

  template<class T>
  int get_size(T& input){
    return (sizeof(input) / sizeof(input[0]));
  }
};

int Water::get_result(std::vector<int>& input){
  int max_l, max_r, water = 0;
  for (int i = 0; i < input.size(); i++){
    if (i == 0){
      max_l = input[i];
      max_r = get_max_r(i, input);
      continue;
    }
    if(max_r == 0){
        return water;
    }
    if (input[i] == max_r){
      max_r = get_max_r(i, input);
    }
    else if (input[i] >= max_l){
      max_l = input[i];
    }
    else{
      water += (get_min(max_l, max_r) - input[i]);
    }
  }
  return water;
}

int Water::get_max_r(int n, std::vector<int>& input){
  int max = 0, count = 0;
  for (int i = input.size() - 1; i > n; i--){
    if (input[i] > max){
      max = input[i];
    }
    if ((i != n + 1) && input[i] < input[i-1]){
      count++;
    }
  }
  // if the numbers behind n decrease progressively
  if (count == (input.size() - n - 2)){
    std::cout << "ok" << std::endl; 
    return 0;
  }
  return max; 
}

int Water::get_min(int a, int b){
  if(a < b){
    return a;
  }else{
    return b;
  }
}

int main(){
  std::cout << "Please input the heights of box, and end with #: " << std::endl;
  int input;
  std::vector<int> vinput;
  while(std::cin >> input){
      vinput.push_back(input);
  }
  Water w;
  std::cout << w.get_result(vinput) << std::endl;
  return 0;
} 