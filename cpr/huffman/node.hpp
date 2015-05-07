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

            static auto make_new_node(unsigned val, std::size_t freq, std::shared_ptr < Node > left, std::shared_ptr < Node > right) -> std::shared_ptr < Node >
            {
                return std::make_shared < Node > ( val, freq, left, right );
            }

            Node()
                : value{ 0 }, frequence{ 0 }, left{ nullptr }, right{ nullptr }
            {   }
            Node(unsigned val, std::size_t freq)
                : value{ val }, frequence{ freq }, left{ nullptr }, right{ nullptr }
            {   }
            Node(unsigned val, std::size_t freq, std::shared_ptr < Node > lft, std::shared_ptr < Node > rht)
                : value{ val }, frequence{ freq }, left{ lft }, right{ rht }
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