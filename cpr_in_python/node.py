__author__ = 'yue'


class Node:

    def __init__(self):
        self.character = ''
        self.frequency = 0
        self.left = None
        self.right = None

    def __init__(self, ch, freq):
        self.character = ch
        self.frequency = freq
        self.left = None
        self.right = None

    def is_leaf(self):
        return not self.left and not self.right