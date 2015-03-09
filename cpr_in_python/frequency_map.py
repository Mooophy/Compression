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

#for testing, move to unit tests later on
seq = ['a', 'a', 'a', 'a']
seq2 = 'aaazzzaaaacccccccsssbb'

freq_map = FrequencyMap(seq2)
print(freq_map)  #s:3,b:2,z:3,c:7,a:7,
