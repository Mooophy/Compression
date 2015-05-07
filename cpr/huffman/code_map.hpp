#pragma once 
#include <unordered_map>
#include <stack>
#include <tuple>
#include "make_huffman_tree.hpp"


namespace cpr
{
    namespace huffman
    {
        class CodeMap : public std::unordered_map<unsigned, std::size_t>
        {
            void fill_by_dfs(SharedNode node)
            {
                auto code = std::size_t(0);
                auto source = std::make_tuple(code, node);
                auto stk = std::stack < decltype(source) > {};
                for (stk.push(source); !stk.empty(); /* */)
                {
                    std::tie(code, node) = stk.top(); stk.pop();
                    if (node->is_leaf())
                    {
                        (*this)[node->value] = code;
                        continue;
                    }
                    stk.push(std::make_tuple((code << 1) + 0, node->left));
                    stk.push(std::make_tuple((code << 1) + 1, node->right));
                }
            }

        public:
            explicit CodeMap(SharedNode tree)
            {
                fill_by_dfs(tree);
            }
        };
    }
}