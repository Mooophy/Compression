
#include <vector>
#include <queue>

#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

namespace cpr
{
	namespace huffman
	{
		template<typename Freq>
		class Node
		{
		public:
			Node()
				: character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
			{   }
			Node(unsigned char ch, Freq freq)
				: character_{ ch }, freq_{ freq }, left_{ nullptr }, right_{ nullptr }
			{   }
			Node(Node const& other)
				: character_{ other.character_ }, freq_{ other.freq_ }, left_{ other.left_ }, right_{ other.right_ }
			{	}

		private:
			unsigned char character_;
			Freq freq_;
			Node *left_, *right_;
		};

		template<typename Freq>
		inline bool operator > (Node<Freq> const& lhs, Node<Freq> const& rhs)
		{
			return lhs.freq_ > rhs.freq_;
		}
		template<typename Freq>
		inline bool operator < (Node<Freq> const& lhs, Node<Freq> const& rhs)
		{
			return lhs.freq_ < rhs.freq_;
		}
	}
}


#endif // !HUFFMAN_HPP
