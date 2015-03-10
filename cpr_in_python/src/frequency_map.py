from collections import deque


class FrequencyMap():
    def __init__(self, sequence):
        dic = {}
        for key in sequence:
            if key in dic:
                dic[key] += 1
            else:
                dic[key] = 1
        self.dictionary = dic

    @staticmethod
    def frequency_to_bytes(freq):
        dq = deque()
        while freq > 0:
            dq.appendleft(freq & 0xff)
            freq >>= 8
        return [byte for byte in dq]

    def __str__(self):
        return ','.join([(key + ':' + str(self.dictionary[key])) for key in self.dictionary.keys()]) + ','