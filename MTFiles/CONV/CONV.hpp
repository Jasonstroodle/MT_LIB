#ifndef CONV_HPP
#define CONV_HPP
namespace CONV{
  bool is_num(char c);
  float cal_float(float num1, float num2, char op); 
  int cal_int(int num1, int num2, int op); 
  bool is_op(char c);
  std::string equate_string(std::string str);
  int binary_to_int(std::string str);
  std::string int_to_binary(int n);
  std::string reverse_string(std::string s);
  float evaluate_float(std::string str); 
  int evaluate_int(std::string str) ;
  int remainder_div(int x,int y);
  bool true_false(std::string str);
  bool string_to_bool(std::string str);
};
#endif
