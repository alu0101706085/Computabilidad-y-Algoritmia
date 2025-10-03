#ifndef CLASE_PATRONESREGEX
#define CLASE_PATRONESREGEX

#include <iostream>
#include <regex>

class PatronesRegex {
 public:
  static const std::regex INT_VARIABLE_REGEX;
  static const std::regex DOUBLE_VARIABLE_REGEX;
  static const std::regex FOR_LOOP_REGEX;
  static const std::regex WHILE_LOOP_REGEX;
  static const std::regex SINGLE_LINE_COMMENT_REGEX;
  static const std::regex MULTI_LINE_COMMENT_START_REGEX;
  static const std::regex MULTI_LINE_COMMENT_END_REGEX;
  static const std::regex MAIN_FUNCTION_REGEX;
};

#endif