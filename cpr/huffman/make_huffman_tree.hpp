#include <queue>
#include <vector>

#include "node.hpp"
#include "frequency_map.hpp"


namespace cpr
{
    namespace huffman
    {
        auto make_huffman_tree(cpr::huffman::FrequencyMap const& fmap) -> std::shared_ptr < Node >
        {
            using SharedPtr = std::shared_ptr < Node > ;
            auto greater = [](SharedPtr lhs, SharedPtr rhs)
            {
                return lhs->frequence != rhs->frequence ? lhs->frequence > rhs->frequence : lhs->value > rhs->value;
            };

            using Q = std::priority_queue < SharedPtr, std::vector<SharedPtr>, decltype(greater) > ;
            auto q = Q(greater);
            for (auto pair : fmap)
                q.push(Node::make_new_node(pair.first, pair.second, nullptr, nullptr));
            for (int i = 1; i != fmap.size(); ++i)
            {
                auto lft = q.top(); q.pop();
                auto rht = q.top(); q.pop();
                q.push(Node::make_new_node(0, lft->frequence + rht->frequence, lft, rht));
            }

            return q.top();
        }
    }
}