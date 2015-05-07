#pragma once
#include <memory>
#include <string>


namespace cpr
{
    namespace huffman
    {
        struct Node;
        using SharedNode = std::shared_ptr < Node >;

        struct Node
        {
            static auto make_new_node() -> SharedNode
            {
                return std::make_shared< Node >();
            }

            static auto make_new_node(unsigned val, std::size_t freq, SharedNode left, SharedNode right) -> SharedNode
            {
                return std::make_shared < Node > ( val, freq, left, right );
            }

            Node()
                : value{ 0 }, frequence{ 0 }, left{ nullptr }, right{ nullptr }
            {   }
            Node(unsigned val, std::size_t freq)
                : value{ val }, frequence{ freq }, left{ nullptr }, right{ nullptr }
            {   }
            Node(unsigned val, std::size_t freq, SharedNode lft, SharedNode rht)
                : value{ val }, frequence{ freq }, left{ lft }, right{ rht }
            {   }

            auto is_leaf() const -> bool
            {
                return !left && !right;
            }

            auto to_string() const -> std::string
            {
                return "[v=" + (is_leaf() ? std::to_string(value) : "_") + " : f=" + std::to_string(frequence) + "]";
            }

            unsigned value;
            std::size_t frequence;
            SharedNode left, right;
        };
    }
}