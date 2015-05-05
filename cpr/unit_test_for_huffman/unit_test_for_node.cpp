#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/node.hpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
    using Node = cpr::huffman::Node < char, long > ;

    TEST_CLASS(test_node)
    {
    public:

        TEST_METHOD(default_ctor)
        {
            Node node;

            Assert::AreEqual((char)0, node.character_);
            Assert::AreEqual(0l, node.freq_);
            Assert::IsNull(node.left_.get());
            Assert::IsNull(node.right_.get());
        }

        TEST_METHOD(ctor_with_2_args)
        {
            Node node{ 'a', 42ul };

            Assert::AreEqual('a', node.character_);
            Assert::AreEqual(42l, node.freq_);
            Assert::IsNull(node.left_.get());
            Assert::IsNull(node.right_.get());
        }

        TEST_METHOD(copy_ctor)
        {
            Node lhs{ 'a', 42l };
            lhs.left_ = cpr::huffman::make_new_node<char, long>();
            lhs.right_ = cpr::huffman::make_new_node<char, long>('b', 99l);
            Node rhs(lhs);

            Assert::AreEqual(lhs.character_, rhs.character_);
            Assert::AreEqual(lhs.freq_, rhs.freq_);

            Assert::IsTrue(lhs.left_ == rhs.left_);
            Assert::IsTrue(lhs.right_ == rhs.right_);

            Assert::AreSame(lhs.left_->character_, rhs.left_->character_);
            Assert::AreSame(lhs.left_->freq_, rhs.left_->freq_);
        }

        TEST_METHOD(is_leaf)
        {
            Node node;
            Assert::IsTrue(node.is_leaf());
        }

        TEST_METHOD(make_new_node_without_args)
        {
            auto pointer = cpr::huffman::make_new_node<char, long>();

            Assert::AreEqual((char)0, pointer->character_);
            Assert::AreEqual(0l, pointer->freq_);
            Assert::IsNull(pointer->left_.get());
            Assert::IsNull(pointer->right_.get());
        }

        TEST_METHOD(make_new_node_with_2_args)
        {
            auto pointer = cpr::huffman::make_new_node<char, long>('a', 42l);

            Assert::AreEqual('a', pointer->character_);
            Assert::AreEqual(42l, pointer->freq_);
            Assert::IsNull(pointer->left_.get());
            Assert::IsNull(pointer->right_.get());
        }

        TEST_METHOD(make_new_node_that_calling_copy_ctor)
        {
            auto copied_from = cpr::huffman::make_new_node<char, long>('a', 42ul);
            copied_from->left_ = cpr::huffman::make_new_node<char, long>();
            copied_from->right_ = cpr::huffman::make_new_node<char, long>();

            auto copied_to = cpr::huffman::make_new_node<char, long>(*copied_from);

            Assert::AreEqual(copied_from->character_, copied_to->character_);
            Assert::AreEqual(copied_from->freq_, copied_to->freq_);

            Assert::AreEqual(true, copied_from->left_ == copied_to->left_);
            Assert::AreEqual(true, copied_from->right_ == copied_to->right_);

            Assert::AreSame(copied_from->left_->character_, copied_to->left_->character_);
            Assert::AreSame(copied_from->left_->freq_, copied_to->left_->freq_);

            Assert::AreSame(copied_from->right_->character_, copied_to->right_->character_);
            Assert::AreSame(copied_from->right_->freq_, copied_to->right_->freq_);
        }

        TEST_METHOD(for_shared_pointer)
        {
            auto pointer = cpr::huffman::make_new_node<char, long>('a', 42l);
            auto p2 = pointer;
            auto p3 = p2;
        }

        TEST_METHOD(operator_greater_than)
        {
            // note there is a type conversion here:
            auto lhs = Node('a', 42);
            auto rhs = Node('c', 41);
            Assert::IsTrue(lhs > rhs);
        }

        TEST_METHOD(operator_less_than)
        {
            // note there is a type conversion here:
            auto lhs = Node('a', 42);
            auto rhs = Node('c', 41);
            Assert::IsTrue(rhs < lhs);
        }

        TEST_METHOD(operator_output)
        {
            std::stringstream stream;
            // note there is a type conversion here:
            auto node = Node('a', 10);
            stream << node;
            Assert::AreEqual("[a,10]", stream.str().c_str());
        }
    };
}