#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include "CONV.hpp"
std::string CONV::reverse_string(std::string s){
  char x;
  for(int i = 0; i < (s.size()/2); i++){
    x = s[i];
    s[i] = s[s.size()-i-1];
    s[s.size()-i-1] = x;
  }
  return s;
}
bool CONV::is_num(char c) { return (c >= '0' && c <= '9'); }
float CONV::cal_float(float num1, float num2, char op) {
  switch (op) {
  case '+':
    return num1 + num2;
    break;
  case '-':
    return num1 - num2;
    break;
  case '*':
    return num1 * num2;
    break;
  case '/':
    return num1 / num2;
    break;
  case '^':
    return pow(num1, num2);
    break;
  }
  throw std::invalid_argument("Wrong operator type.");
}
int CONV::cal_int(int num1, int num2, int op) {
  switch (op) {
  case '+':
    return num1 + num2;
    break;
  case '-':
    return num1 - num2;
    break;
  case '*':
    return num1 * num2;
    break;
  case '/':
    return num1 / num2;
    break;
  case '^':
    return pow(num1, num2);
    break;
  }
  throw std::invalid_argument("Wrong operator type.");
}
bool CONV::is_op(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
float CONV::evaluate_float(std::string str) {
  std::vector<float> nums;
  std::vector<char> ops;
  for (int i = 0; i < str.size(); i++) {
    if (is_num(str[i])) {
      std::string num = "";
      while (i < str.length() && is_num(str[i]) || str[i] == '.') {
        num = num + str[i];
        i++;
      }
      i--;
      nums.push_back(std::stof(num));
    } else if (is_op(str[i])) {
      ops.push_back(str[i]);
    } else if (!is_op(str[i]) && !is_num(str[i]) && str[i] != '.') {
      throw std::invalid_argument("Unknown type");
    }
  }
  while (!ops.empty()) {
    int opLoc;
    float num;
    if (std::find(ops.begin(), ops.end(), '^') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '^'));
      num = cal_float(nums[opLoc], nums[opLoc + 1], '^');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '*') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '*'));
      num = cal_float(nums[opLoc], nums[opLoc + 1], '*');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '/') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '/'));
      num = cal_float(nums[opLoc], nums[opLoc + 1], '/');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '+') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '+'));
      num = cal_float(nums[opLoc], nums[opLoc + 1], '+');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '-') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '-'));
      num = cal_float(nums[opLoc], nums[opLoc + 1], '-');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    }
  }
  return nums[0];
}
int CONV::evaluate_int(std::string str) {
  std::vector<int> nums;
  std::vector<char> ops;
  for (int i = 0; i < str.size(); i++) {
    if (is_num(str[i])) {
      std::string num = "";
      while (i < str.length() && is_num(str[i]) || str[i] == '.') {
        num = num + str[i];
        i++;
      }
      i--;
      nums.push_back(std::stoi(num));
    } else if (is_op(str[i])) {
      ops.push_back(str[i]);
    } else if (!is_op(str[i]) && !is_num(str[i]) && str[i] != '.') {
      throw std::invalid_argument("Unknown type");
    }
  }
  while (!ops.empty()) {
    int opLoc;
    float num;
    if (std::find(ops.begin(), ops.end(), '^') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '^'));
      num = cal_int(nums[opLoc], nums[opLoc + 1], '^');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '*') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '*'));
      num = cal_int(nums[opLoc], nums[opLoc + 1], '*');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '/') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '/'));
      num = cal_int(nums[opLoc], nums[opLoc + 1], '/');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '+') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '+'));
      num = cal_int(nums[opLoc], nums[opLoc + 1], '+');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    } else if (std::find(ops.begin(), ops.end(), '-') != ops.end()) {
      opLoc =
          std::distance(ops.begin(), std::find(ops.begin(), ops.end(), '-'));
      num = cal_int(nums[opLoc], nums[opLoc + 1], '-');
      ops.erase(ops.begin() + opLoc);
      nums.erase(nums.begin() + opLoc);
      nums[opLoc] = num;
    }
  }
  return nums[0];
}
int CONV::remainder_div(int x,int y){
  return x - ((x/y)*y);
}
int CONV::binary_to_int(std::string str) {
  int num = 0;
  for (int i = 0; i <= str.size(); i++) {
    if (str[i] == '1') {
      if (i == 0) {
        num = num + 1;
      } else {
        num = num + pow(2,i);
      }
    }
  }
  return num;
}
std::string CONV::int_to_binary(int n) {
  std::string foo;
  while(n > 0){
    foo = foo + std::to_string(remainder_div(n,2));
    n = n/2;
  }
  return foo;
}
std::string CONV::equate_string(std::string str) {
  std::vector<std::string> text;
  std::string holder;
  bool isInQuotes = false;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '"' && !isInQuotes) {
      isInQuotes = true;
    } else if (str[i] == '"' && isInQuotes) {
      isInQuotes = false;
      text.push_back(holder);
      holder = "";
    } else if (!isInQuotes && str[i] != '"' && str[i] != '+' && str[i] != ' ') {
      throw std::invalid_argument("L");
    } else if (!isInQuotes && str[i] == '+' || !isInQuotes && str[i] == ' ') {
      continue;
    } else {
      holder = holder + str[i];
    }
  }
  holder = "";
  for (int i = 0; i < text.size(); i++) {
    holder = holder + text[i];
  }
  return holder;
}
bool CONV::true_false(std::string str){
   std::string holder1, holder2, op;
  if (std::find(str.begin(), str.end(), '=') != str.end() ||
      std::find(str.begin(), str.end(), '>') != str.end() ||
      std::find(str.begin(), str.end(), '<') != str.end()) {
    int opLoc;
    if (std::find(str.begin(), str.end(), '=') != str.end()) {
      opLoc = distance(str.begin(), std::find(str.begin(), str.end(), '='));
    } else if (std::find(str.begin(), str.end(), '>') != str.end()) {
      opLoc = distance(str.begin(), std::find(str.begin(), str.end(), '>'));
    } else if (std::find(str.begin(), str.end(), '<') != str.end()) {
      opLoc = distance(str.begin(), std::find(str.begin(), str.end(), '<'));
    }
    op = str[opLoc];
    for (int i = 0; i < opLoc; i++) {
      if (str[i] == '!') {
        op = str[i] + op;
      } else if (str[i] == '=' || str[i] == '>' || str[i] == '<') {
        op = str[i] + op;
      } else {
        holder1 = holder1 + str[i];
      }
    }
    for (int i = opLoc + 1; i < str.size(); i++) {
      if (str[i] == '!') {
        op = str[i] + op;
      } else if (str[i] == '=' || str[i] == '>' || str[i] == '<') {
        op = str[i] + op;
      } else {
        holder2 = holder2 + str[i];
      }
    }
    if (op == "=" || op == "!=" || op == "<" || op == ">" || op == "=!" ||
        op == "=>" || op == "<=" || op == ">=" || op == "=<") {
      try {
        float x = evaluate_float(holder1);
        float y = evaluate_float(holder2);

        if (op == "=") {
          if (x == y) {
            return true;
          } else {
            return false;
          }
        } else if (op == "!=" || op == "=!") {
          if (x != y) {
            return true;
          } else {
            return false;
          }
        } else if (op == ">") {
          if (x > y) {
            return true;
          } else {
            return false;
          }
        } else if (op == "<") {
          if (x < y) {
            return true;
          } else {
            return false;
          }
        } else if (op == "=<" || op == "<=") {
          if (x <= y) {
            return true;
          } else {
            return false;
          }
        } else if (op == "=>" || op == ">=") {
          if (x >= y) {
            return true;
          } else {
            return false;
          }
        }
        return false;
      } catch (std::invalid_argument) {
      }
      try {
        std::string x = equate_string(holder1);
        std::string y = equate_string(holder2);
        if (op == "=") {
          if (x == y) {
            return true;
          } else {
            return false;
          }
        } else if (op == "!=" || op == "=!") {
          if (x != y) {
            return true;
          } else {
            return false;
          }
        } else if (op == ">") {
          if (x.size() > y.size()) {
            return true;
          } else {
            return false;
          }
        } else if (op == "<") {
          if (x.size() < y.size()) {
            return true;
          } else {
            return false;
          }
        } else if (op == "=<" || op == "<=") {
          if (x.size() <= y.size()) {
            return true;
          } else {
            return false;
          }
        } else if (op == "=>" || op == ">=") {
          if (x.size() >= y.size()) {
            return true;
          } else {
            return false;
          }
        }
      } catch (std::invalid_argument) {
        throw std::invalid_argument("Loser");
      }
    } else {
      exit(2);
    }
  } else if (str == "true") {
    return true;
  } else if (str == "false") {
    return false;
  } else {
    throw std::invalid_argument("L");
  }
  return false;
}
bool CONV::string_to_bool(std::string str) {
  std::vector<std::string> equ;
  std::vector<std::string> andOr;
  bool foo;
  std::string holder;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '&'||str[i] == '|'){
      equ.push_back(holder);
      holder = str[i];
      andOr.push_back(holder);
      holder = "";
    } else {
      holder = holder + str[i];
    }
  }
  equ.push_back(holder);
  if(andOr.size() > 0){
    for(int i = 0; i < andOr.size(); i++){
      if(andOr[i] == "&"){
        if(true_false(equ[i]) && true_false(equ[i+1])){
          foo = true;
        } else {
          foo = false;
        }
      } else {
        if(true_false(equ[i]) || true_false(equ[i+1])){
          foo = true;
        } else {
          foo = false;
        }
      }
    }
  } else {
    return true_false(str);  
  }
  return foo;
}
