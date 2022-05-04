//
// Created by bartem1us on 30.03.2022.
//

#ifndef TEMPLATE_TASK6_H
#define TEMPLATE_TASK6_H

#include <vector>
#include <map>
template<typename T>
T Sqr(T value);
template<typename T>
std::vector<T> Sqr(const std::vector<T>& vec);
template<typename key, typename value>
std::map<key, value> Sqr(const std::map<key, value>& map_arg);
template<typename first, typename second>
std::pair<first, second> Sqr(const std::pair<first, second>& pair_arg);

template<typename T>
T Sqr(const T value)
{
    return value* value;
}

template<typename T>
std::vector<T> Sqr(const std::vector<T> &vec) {
    std::vector<T> vec2;
    for (auto &i: vec) {
        vec2.push_back(Sqr(i));
    }
    return vec2;
}

template<typename First, typename Second>
std::map<First, Second>  Sqr(const std::map<First, Second> &map) {
    std::map<First,Second> map2;
    for (auto &i: map) {
        map2[i.first] = Sqr(i.second);
    }
    return map2;
}

template<typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second> &pair) {
    std::pair<First,Second> pair2;
    pair2.first = Sqr(pair.first);
    pair2.second = Sqr(pair.second);
    return pair2;
}




#endif //TEMPLATE_TASK6_H
