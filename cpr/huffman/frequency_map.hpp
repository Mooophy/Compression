#pragma once
#include <unordered_map>

namespace cpr
{
    namespace huffman
    {
        class FrequencyMap : public std::unordered_map < unsigned, std::size_t >
        {
        public:
            FrequencyMap()
                : std::unordered_map < unsigned, std::size_t >()
            {}

            explicit FrequencyMap(std::vector<unsigned> const& splited_data)
            {
                for (auto elem : splited_data)
                    if (this->find(elem) != this->end())
                        ++(*this)[elem];
                    else
                        (*this)[elem] = 1;
            }
        };
    }
}