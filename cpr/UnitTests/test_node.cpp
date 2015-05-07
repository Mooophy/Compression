#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(test_node)
    {
    public:

        TEST_METHOD(test_node_defualt_ctor)
        {
            auto node = cpr::huffman::Node{};
            Assert::IsTrue(nullptr == node.left);
            Assert::IsTrue(nullptr == node.right);
            Assert::AreEqual(0u, node.value);
            Assert::AreEqual(0u, node.frequence);
        }

        TEST_METHOD(test_node_ctor)
        {
            auto node = cpr::huffman::Node{ 42, 10 };
            Assert::IsTrue(nullptr == node.left);
            Assert::IsTrue(nullptr == node.right);
            Assert::AreEqual(42u, node.value);
            Assert::AreEqual(10u, node.frequence);
        }

        TEST_METHOD(test_make_new_node)
        {
            auto sptr = cpr::huffman::Node::make_new_node();
            Assert::IsTrue(nullptr == sptr->left);
            Assert::IsTrue(nullptr == sptr->right);
            Assert::AreEqual(0u, sptr->value);
            Assert::AreEqual(0u, sptr->frequence);

            auto sptr_ = cpr::huffman::Node::make_new_node(42, 99, nullptr, nullptr);
            Assert::IsTrue(nullptr == sptr_->left);
            Assert::IsTrue(nullptr == sptr_->right);
            Assert::AreEqual(42u, sptr_->value);
            Assert::AreEqual(99u, sptr_->frequence);
        }

        TEST_METHOD(test_is_leaf)
        {
            auto sptr = cpr::huffman::Node::make_new_node();
            Assert::IsTrue(sptr->is_leaf());
        }

        TEST_METHOD(test_to_string)
        {
            auto sptr = cpr::huffman::Node::make_new_node();
            auto expt = std::string("[v=0 : f=0]");
            Assert::AreEqual(expt, sptr->to_string());
        }

    };
}