
#ifndef TEMPLATE_TASK4_H
#define TEMPLATE_TASK4_H

#include <string>
#include <map>
#include <cstdint>
#include <vector>
#include <tuple>

enum class Lang {
    DE, FR, IT
};


/*struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;
    bool  operator== (const Region &rhs) const {
        return std::tie(this->std_name, this->parent_std_name, this->names, this->population) ==
               std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
    }
};*/

struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;
};
[[maybe_unused]]static bool operator== (const Region &lhs , const Region &rhs) {
    return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) ==
           std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}



int FindMaxRepetitionCount(const std::vector<Region> &regions);


#endif //TEMPLATE_TASK4_H
