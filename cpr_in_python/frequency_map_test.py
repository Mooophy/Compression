__author__ = 'yue'


import unittest
import frequency_map as fmap


class TestFrequencyMap(unittest.TestCase):

    def test_ctor(self):
        fm = fmap.FrequencyMap('aaabbc')
        self.assertEqual(3, fm.dictionary['a'])