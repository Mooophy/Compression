__author__ = 'yue'


import unittest
import node as n


class TestNode(unittest.TestCase):

    def test_default_ctor(self):
        node = n.Node.default()
        self.assertEqual('', node.character)
        self.assertEqual(0, node.frequency)
        self.assertIsNone(node.left)
        self.assertIsNone(node.right)

    def test_ctor(self):
        node = n.Node('c', 42)
        self.assertEqual('c', node.character)
        self.assertEqual(42, node.frequency)
        self.assertIsNone(node.left)
        self.assertIsNone(node.right)

    def test_is_leaf(self):
        node = n.Node('c', 42)
        self.assertTrue(node.is_leaf())