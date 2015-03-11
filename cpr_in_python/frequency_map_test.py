__author__ = 'yue'


import unittest
import frequency_map as fmap


class TestFrequencyMap(unittest.TestCase):

    def test_ctor(self):
        fm = fmap.FrequencyMap('aaabbc')
        self.assertEqual(3, fm.dictionary['a'])
        self.assertEqual(2, fm.dictionary['b'])
        self.assertEqual(1, fm.dictionary['c'])

    def test_frequency_to_bytes(self):
        self.assertEqual([0x01], fmap.FrequencyMap.frequency_to_bytes(0x01))
        self.assertEqual([0xab, 0xcd], fmap.FrequencyMap.frequency_to_bytes(0xabcd))
        self.assertEqual([0x0b, 0xcd], fmap.FrequencyMap.frequency_to_bytes(0xbcd))

    def test_str(self):
        fm = fmap.FrequencyMap('aaabbc')
        self.assertEqual(12, len(str(fm)))
