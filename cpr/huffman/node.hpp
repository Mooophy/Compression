#pragma once
#include <memory>


namespace cpr
{
    namespace huffman
    {
        struct Node
        {
            using SharedNode = std::shared_ptr < Node >;

            //default ctor
            Node()
                : value{ 0 }, frequence{ 0 }, left{ nullptr }, right{ nullptr }
            {   }

            //ctor
            Node(unsigned val, std::size_t freq)
                : value{ val }, frequence{ freq }, left{ nullptr }, right{ nullptr }
            {   }

            unsigned value;
            std::size_t frequence;
            SharedNode left, right;

            auto is_leaf() const -> bool
            {
                return !left && !right;
            }
        };
    }
}