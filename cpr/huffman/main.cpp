#include <iostream>
#include "huffman.hpp"

int main()
{
	//std::vector<char> raw_data{ 'a', 'a', 'a', 'a', 'b', 'b', 'c' };
	//std::vector<cpr::huffman::Node<int>> C;
	//for (auto ch : raw_data)
	//{
	//	auto it = std::find_if(C.begin(), C.end(), [ch](cpr::huffman::Node<int> const& node){return node.character_ == ch; });
	//	if (it != C.cend())
	//		++it->freq_;
	//	else
	//		C.push_back(cpr::huffman::Node<int>(ch, 1));
	//}
	//std::cout << "size of Set C : " << C.size() << std::endl;

	using Char = cpr::huffman::Node<int>;
	std::vector<Char> C{ Char('a', 45), Char('b', 13), Char('c', 12), Char('d', 16), Char('e', 9), Char('f', 5) };
	cpr::huffman::HuffmanTree<int> huff_tree(C.cbegin(), C.cend());
	huff_tree.print();

	std::cout << "\nexit" << std::endl;
	return 0;
}