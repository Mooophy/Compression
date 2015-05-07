#pragma once 
#include <unordered_map>
#include <stack>
#include <tuple>
#include "node.hpp"
//#include "make_huffman_tree.hpp"


namespace cpr
{
    namespace huffman
    {
        class CodeMap : public std::unordered_map<unsigned, std::size_t>
        {
            void fill_by_dfs(SharedNode tree)
            {
                auto code = std::size_t(0);
                auto source = std::make_tuple(code, tree);
                auto stk = std::stack < decltype(source) > {};
                for (stk.push(source); !stk.empty(); /* */)
                {
                    std::tie(code, tree) = stk.top(); stk.pop();
                    if (tree->is_leaf())
                    {
                        (*this)[tree->value] = code;
                        continue;
                    }
                    stk.push(std::make_tuple((code << 1) + 0, tree->left));
                    stk.push(std::make_tuple((code << 1) + 1, tree->right));
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