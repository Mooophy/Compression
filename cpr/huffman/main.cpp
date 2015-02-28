#include <iostream>
#include "huffman.hpp"
#include "buffer.hpp"

int main()
{
	///////////test for huffman node and tree
	using Char = cpr::huffman::Node<int>;
	std::vector<Char> C{ Char('a', 45), Char('b', 13), Char('c', 12), Char('d', 16), Char('e', 9), Char('f', 5) };
	cpr::huffman::HuffmanTree<int> huff_tree(C.cbegin(), C.cend());
	huff_tree.print();

	///////////test for encoding
	std::cout << "\n--test for encoding : \n";
	for (auto ch : C)
		std::cout << "the code for char " << ch.character_ << " is " << huff_tree.encode(ch.character_) << std::endl;

	////////////test for buffer
	std::cout << "\n--test for buffer\n";
	cpr::huffman::Buffer<unsigned char> buff{ 0x31, 0xff, 0x00 };
	while (!buff.data().empty())
		std::cout << buff.pop_front_bit();

	std::cout << std::endl;
	system("pause");
	return 0;
}