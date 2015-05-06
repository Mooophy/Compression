#pragma once
#include <memory>


namespace cpr
{
    namespace huffman
    {
        struct Node
        {
            static auto make_new_node() -> std::shared_ptr < Node >
            {
                return std::make_shared< Node >();
            }

            Node()
                : value{ 0 }, frequence{ 0 }, left{ nullptr }, right{ nullptr }
            {   }

            Node(unsigned val, std::size_t freq)
                : value{ val }, frequence{ freq }, left{ nullptr }, right{ nullptr }
            {   }

            auto is_leaf() const -> bool
            {
                return !left && !right;
            }

            unsigned value;
            std::size_t frequence;
            std::shared_ptr < Node > left, right;
        };
    }
}