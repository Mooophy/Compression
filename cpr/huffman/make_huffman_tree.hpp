#pragma once
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include "node.hpp"
#include "frequency_map.hpp"


namespace cpr
{
    namespace huffman
    {
        inline // without inline, one definition rull will be voilated and hence link error happens.
        auto make_huffman_tree(cpr::huffman::FrequencyMap const& fmap) -> SharedNode
        {
            auto greater = [](SharedNode lhs, SharedNode rhs)
            {
                return lhs->frequence != rhs->frequence ? lhs->frequence > rhs->frequence : lhs->value > rhs->value;
            };

            using Q = std::priority_queue < SharedNode, std::vector< SharedNode >, decltype(greater) >;
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

        inline // without inline, one definition rull will be voilated and hence link error happens.
        auto huffman_tree_to_string(SharedNode tree) -> std::string
        {
            std::function<std::string(SharedNode)> inorder = [&](SharedNode t) -> std::string
            {
                return !t ? std::string() : inorder(t->left) + t->to_string() + inorder(t->right);
            };

            return inorder(tree);
        }
    }
}