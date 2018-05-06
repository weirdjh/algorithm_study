import random

def heuristic(queens):
	
	conflictQueenPair = 0

	for queen in queens:
		x,y = queen[0], queen[1]

		for _queen in queens:
			_x, _y = _queen[0], _queen[1]

			if(conflict(x,y,_x,_y)):
				 conflictQueenPair += 1
				
	return conflictQueenPair


def conflict(x, y, _x, _y) :
	if x == _x and y == _y:
		return False
	elif x == _x or y == _y or x-y == _x-_y or x+y == _x+_y:
		return True
	else:
		return False

def getRandomQueen(n):
	ret = []
	for r in range(n):
		ret.append((r, random.randrange(1,n)))
	return ret

def nextSuccesor(queens, n):
	min = 987654321
	for idx in range(n):
		tmp = queens[idx]
		for possibleRow in range(n):
			queens[idx] = (idx, possibleRow)
			h = heuristic(queens)
			if min > h:
				min = h
				succesor = queens[:]
		queens[idx] = tmp

	return succesor

def solve(queens, n):
	h = heuristic(queens)
	cnt = 0

	while(h > 0):
		nextQueens = nextSuccesor(queens, n)
		nh = heuristic(nextQueens)

		if nh == 0:
			return True, cnt, nextQueens

		elif nh < h:
			h = nh
			queens = nextQueens[:]
			cnt += 1
			
		else:
			return False, cnt, nextQueens

	return True, cnt, queens


def printQueen(queens, n):
	for r in range(n):
		for c in range(n):
			find = False
			for queen in queens:
				if c == queen[0] and r == queen[1]:
					find = True
			if find:
				print('X', end=' ')
			else:
				print('O', end=' ')
		print()

if __name__=='__main__':

	solved, solvedCnt = 0, 0
	unSolved, unSolvedCnt = 0, 0
	
	for i in range(1000):
		queens = getRandomQueen(8)
		
		#printQueen(queens, 8)

		isSolved, count, lastQueens = solve(queens, 8)
		
		if isSolved:
			solved += 1
			solvedCnt += count

		else:
			unSolved += 1
			unSolvedCnt += count

	print("solved : %.2f %%, avg cnt : %.2f"% (float(solved)/1000*100, float(solvedCnt)/solved))
	print("unsolved : %.2f %%, avg cnt : %.2f"% (float(unSolved)/1000*100, float(unSolvedCnt)/unSolved))


