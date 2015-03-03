#include <iostream>
#include <memory>


#ifndef NODE_HPP
#define NODE_HPP


namespace cpr
{
	namespace huffman
	{
		template<typename Char, typename Freq>
		struct Node
		{
			using SharedNode = std::shared_ptr < Node<Char, Freq> > ;

			//default ctor
			Node()
				: character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
			{   }

			//ctor
			Node(Char ch, Freq freq)
				: character_{ ch }, freq_{ freq }, left_{ nullptr }, right_{ nullptr }
			{   }

			Char character_;
			Freq freq_;
			SharedNode left_, right_;

			bool is_leaf() const
			{
				return !left_ && !right_;
			}
		};

		template<typename Char, typename Freq>
		inline bool operator > (Node<Char, Freq> const& lhs, Node<Char, Freq> const& rhs)
		{
			return lhs.freq_ > rhs.freq_;
		}

		template<typename Char, typename Freq>
		inline bool operator < (Node<Char, Freq> const& lhs, Node<Char, Freq> const& rhs)
		{
			return lhs.freq_ < rhs.freq_;
		}

		template<typename Char, typename Freq>
		inline std::ostream& operator<<(std::ostream& os, Node<Char, Freq> const& node)
		{
			return os << "[" << node.character_ << "," << node.freq_ << "]";
		}

		template<typename Char, typename Freq>
		std::shared_ptr < Node<Char, Freq>> make_new_node()
		{
			return std::make_shared<Node<Char, Freq>>();
		}

		template<typename Char, typename Freq>
		std::shared_ptr < Node<Char, Freq>> make_new_node(Char ch, Freq freq)
		{
			return std::make_shared<Node<Char, Freq>>(ch, freq);
		}

		template<typename Char, typename Freq>
		std::shared_ptr < Node<Char, Freq>> make_new_node(Node<Char, Freq> const& other)
		{
			return std::make_shared<Node<Char, Freq>>(other);
		}
	}
}
#endif // !NODE_HPP