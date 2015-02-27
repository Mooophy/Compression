#include <iostream>
#include <set>
#include <algorithm>
#include "huffman.hpp"


int main()
{
    std::vector<unsigned char> v {'a', 'a', 'b'};
    using Set = std::set<cpr::huffman::Node<int>>;
    Set set;

    for(auto ch : v)
    {
        auto it = std::find_if(set.begin(), set.end(), [](cpr::huffman::Node<int> node){return node.character_ == 'a';});
        if( it != set.end())
        {
            auto temp = *it;
            set.erase(it);
            ++temp.freq_;
            set.insert(temp);
        }
        else
            set.insert(*it);
    }

    return 0;
}

