#ifndef _ALIASES_H
#define _ALIASES_H

#include "glm.hpp"

#include <fstream>
#include <map>
#include <string>
#include <vector>

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Matrix = glm::mat4;
using Mat3 = glm::mat3;

using InputFileStream = std::ifstream;

template<typename T, typename U>
using map = std::map<T, U>;

template<typename T, typename U>
using pair = std::pair<T, U>;

using string = std::string;

template<typename T>
using strmap = map<string, T>;


template<typename T>
using strpair = pair<string, T>;

template <typename T>
using vector = std::vector<T>;

#endif