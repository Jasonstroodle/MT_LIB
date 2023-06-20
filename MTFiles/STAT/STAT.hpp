#include <vector> 
#include <algorithm>
#include <map>
#include <iostream>
#ifndef STAT_HPP 
#define STAT_HPP 
namespace ST { 
template <typename t>
t MODE(std::vector<t> v){
  std::map<int, int> m; 
  for(int i = 0; i < v.size(); i++) { 
    m[v[i]]++; 
  } 
  auto it = std::max_element(m.begin(), m.end(), [](const auto &p1, const auto &p2) { return p1.second < p2.second; }); 
  return it->first; 
}
template <typename t>
t AVERAGE(std::vector<t> v){
  t sum; 
  if(v.size() < 1){ 
    throw std::invalid_argument("Life sucks"); 
  } 
  for(int i = 0; i < v.size(); i++){ 
    sum = sum + v[i]; 
  } 
  return sum/v.size(); 
} 
} 


#endif
