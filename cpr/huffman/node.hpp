#include <memory>


#ifndef NODE_HPP
#define NODE_HPP


namespace cpr
{
	namespace huffman
	{
		struct Node
		{
			using UniquePointer = std::unique_ptr < Node > ;

			//default ctor
			Node()
				: character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
			{   }

			//ctor
			Node(uint8_t ch, uint64_t freq)
				: character_{ ch }, freq_{ freq }, left_{ nullptr }, right_{ nullptr }
			{   }

			//move ctor
			Node(Node && other)
				: character_{ other.character_ }, freq_{ other.freq_ }, left_{ other.left_.release() }, right_{ other.right_.release() }
			{	}

			//data members
			uint8_t character_;
			uint64_t freq_;
			UniquePointer left_, right_;

			//public interface
			bool is_leaf() const
			{
				return !left_ && !right_;
			}
		};

		//
		// non member functions
		//

		inline bool operator > (Node const& lhs, Node const& rhs)
		{
			return lhs.freq_ > rhs.freq_;
		}

		inline bool operator < (Node const& lhs, Node const& rhs)
		{
			return lhs.freq_ < rhs.freq_;
		}

		inline std::ostream& operator<<(std::ostream& os, Node const& node)
		{
			return os << "[" << node.character_ << "," << node.freq_ << "]";
		}
	}
}
#endif // !NODE_HPP
