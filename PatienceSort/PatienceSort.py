import bisect, heapq

def patienceSort(seq):
    piles = []
    for x in seq:
        new_pile = [x]
        i = bisect.bisect_left(piles, new_pile)
        if i != len(piles):
            piles[i].insert(0, x)
        else:
            piles.append(new_pile)

    for i in range(len(seq)):
        small_pile = piles[0]
        seq[i] = small_pile.pop(0)
        if small_pile:
            heapq.heapreplace(piles, small_pile)
        else:
            heapq.heappop(piles)
    assert not piles

arr = [4, 65, 2, 4, -31, 0, 99, 1, 83, 782, 1]
patienceSort(arr)
print(arr)
