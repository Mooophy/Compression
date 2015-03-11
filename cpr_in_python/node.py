__author__ = 'yue'


class Node:

    def __init__(self, ch, freq):
        self.character = ch
        self.frequency = freq
        self.left = None
        self.right = None

    @classmethod
    def default(cls):
        return cls('', 0)

    def is_leaf(self):
        return not self.left and not self.right