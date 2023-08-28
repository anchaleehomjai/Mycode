#Library
import copy # for copy.deepcopy()
import random # for random.choice()
import heapq # for heap to used as priority queue

random.seed()

# Set DEBUG to True to see debug message
DEBUG = True
goal = [[[0,1,2],[3,4,5],[6,7,8]], [0, 0]]

def printBoard(state, indent=0):
  ''' Print board from state, with indent level of indentation '''
  board = state[0]
  for row in range(3):
    print("\t" * indent, end="")
    print("| ", end="")
    for col in range(3):
      print(board[row][col], "", end="")
    print("|")

def stateToString(state):
  ''' return string version of the state '''
  return "Board=" + str(state[0])
  

def isEq(state1, state2):
  ''' check if the board in state 1 is equal to the board in state2 '''
  board1 = state1[0]
  board2 = state2[0]

  for row in range(3):
   for col in range(3):
     if(board1[row][col] != board2[row][col]):
       return False
  return True

def performAction(state, action):
  ''' return a new state after perform action (string) on state, 
  return old state if action cannot be perform'''
  # extract board, position of empty tile
  # Using deepcopy to create new instances to return
  board = copy.deepcopy(state[0])
  rowEmpty, columnEmpty = copy.deepcopy(state[1])

  # perform action, if possible
  if (action == "left"):
    # can perform left if columnEmpty > 0
    if(columnEmpty > 0):
      # swap tile from left (columnEmpty - 1)
      board[rowEmpty][columnEmpty] = board[rowEmpty][columnEmpty - 1]
      board[rowEmpty][columnEmpty - 1] = 0
      columnEmpty -= 1
  elif (action == "right"):
    # can perform right if columnEmpty < 2
    if(columnEmpty < 2):
      # swap tile from right (columnEmpty + 1)
      board[rowEmpty][columnEmpty] = board[rowEmpty][columnEmpty + 1]
      board[rowEmpty][columnEmpty + 1] = 0
      columnEmpty += 1
  elif (action == "up"):
    # can perform up if rowEmpty > 0
    if(rowEmpty > 0):
      # swap tile from up (rowEmpty - 1)
      board[rowEmpty][columnEmpty] = board[rowEmpty - 1][columnEmpty]
      board[rowEmpty - 1][columnEmpty] = 0
      rowEmpty -= 1
  elif (action == "down"):
    # can perform down if rowEmpty < 2
    if(rowEmpty < 2):
      # swap tile from down (rowEmpty + 1)
      board[rowEmpty][columnEmpty] = board[rowEmpty + 1][columnEmpty]
      board[rowEmpty + 1][columnEmpty] = 0
      rowEmpty += 1

  # return new state
  return [board, [rowEmpty, columnEmpty]]
    
def possibleActions(state):
  ''' return a list of possible actions (string) in that state '''
  actionList = [] # list of possible action
  # possible actions are determined by where the empty tile is
  rowEmpty, columnEmpty = state[1]

  # appending performable action into the list
  if(rowEmpty > 0):
    # not row 0, can perform up
    actionList.append("up")
  if(rowEmpty < 2):
    # not row 2, can perform down
    actionList.append("down")
  if(columnEmpty > 0):
    # column not 0, can perform left
    actionList.append("left")
  if(columnEmpty < 2):
    # column not 0, can perform right
    actionList.append("right")

  return actionList

def generateState(state, nMove):
  ''' generate a new state by perform nMove actions on input state '''
  newState = state
  for i in range(nMove):
    actionList = possibleActions(newState)
    action = random.choice(actionList)  # select an action from action list
    newState = performAction(newState, action)

    if(DEBUG):
      print(action, end="\t")
  if(DEBUG):
    print()
  return newState

def printSolution(solution):
  ''' print solution, which is a sequence(list) of search nodes '''
  # Printing Solution
  if(solution is not None):
    for i in solution:
      state = i[1]
      action = i[2]
      if (action is not None):
        print("\t", i[2])
      printBoard(i[1],1)
    print("Cost:{0:4d}".format(cost))