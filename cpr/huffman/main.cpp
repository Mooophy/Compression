#include <iostream>
#include "huffman.hpp"
#include "buffer.hpp"

int main()
{
	using Char = cpr::huffman::Node<int>;
	std::vector<Char> C{ Char('a', 45), Char('b', 13), Char('c', 12), Char('d', 16), Char('e', 9), Char('f', 5) };
	cpr::huffman::HuffmanTree<int> huff_tree(C.cbegin(), C.cend());
	huff_tree.print();

	std::cout << "\nfor encoding : \n";
	for (auto ch : C)
		std::cout << "the code for char " << ch.character_ << " is " << huff_tree.encode(ch.character_) << std::endl;


	////////////test for buffer

	cpr::huffman::Buffer<char> buff;

	std::cout << "\nexit normally" << std::endl;
	return 0;
}