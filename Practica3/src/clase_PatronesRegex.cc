#include "clase_PatronesRegex.h"

#include <iostream>
#include <regex>

const std::regex PatronesRegex::INT_VARIABLE_REGEX(R"(int\s+(\w+)\s*((\=)\s*(\d+))?\s*;)");
const std::regex PatronesRegex::DOUBLE_VARIABLE_REGEX(R"(double\s+(\w+)\s*((\=)\s*(\d+)(\.\d+))?\s*;)");
const std::regex PatronesRegex::FOR_LOOP_REGEX(R"(for\s*\()");
const std::regex PatronesRegex::WHILE_LOOP_REGEX(R"(while\s*\()");
const std::regex PatronesRegex::SINGLE_LINE_COMMENT_REGEX(R"(\/\/[^\n]*)");
const std::regex PatronesRegex::MULTI_LINE_COMMENT_START_REGEX(R"(\/\*)");
const std::regex PatronesRegex::MULTI_LINE_COMMENT_END_REGEX(R"(\*\/)");
const std::regex PatronesRegex::MAIN_FUNCTION_REGEX(R"(int\s+main\s*\()");