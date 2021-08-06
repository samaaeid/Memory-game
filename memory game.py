import random
import time
N= 6
counter = 0
a, b = -1, -1
grid = [[0 for x in range(N)] for y in range(N)]


# This function prints the grid of Gomoku as the game progresses
def print_grid(x1,y1,x2,y2):
    print('--' + '---' * N + '--')
    for i in range(N):
        print(end='|  ')
        for j in range(N):
            if (i==x1 and j==y1):
                print( grid[i][j] , end='  ')
            elif (i==x2 and j==y2):
                print( grid[i][j] , end='  ')
            elif grid[i][j]:
                print( '#' , end='  ')
            else :
                print( ' ' , end='  ')
        print(end='|')
        print()
    print('--' + '---' * N + '--')


# This function checks if the game has a win state or not
def check_win():
    c = 1
    for i in range(N):
        for j in range(N):
            if grid[i][j] != 0 :
                c=0
    if c == 1:
        return True
    else:
        return False

# This function checks if the game has a tie state or not for the given mark
def check_lose(s1):
    s2=time.time()
    if s2-s1 >= 60 :
        return True
    else :
       return False           #time

# This function generates numbers
def generate_numbers():
    for i in range(N):
        for j in range(N):
            sum=0
            n = random.randint(1, 18)
            for l in grid:
               sum+=l.count(n)
            while sum>=2 :
                n = random.randint(1, 18)
                sum=0
                for l in grid:
                    sum+=l.count(n)
            grid[i][j] = n

# This function checks if given position is valid or not
def check_valid_position(x1,y1,x2,y2):
    valid=  0<=x1<N  and   0 <= y1 <N and 0<=x2<N  and   0 <= y2 <N and (x1 != x2 or y1 != y2)
    return valid

def check_memory(x1,y1,x2,y2):
    global counter
    if grid[x1][y1] == grid[x2][y2]:
        grid[x1][y1] = grid[x2][y2] = 0
        counter+=1
        return True
    else:
        return False

# This function clears the game structures
def grid_clear():
    global grid
    grid = [[0 for x in range(N)] for y in range(N)]
    global counter
    counter = 0

# This function reads a valid position input
def read_input():
    x1,y1,x2,y2 =  map(int, input('Enter the row index and column index: ').split())
    while not check_valid_position(x1,y1,x2,y2):
       x1,y1,x2,y2 = map(int, input('Enter a valid row index and a valid column index: ').split())
    return x1,y1,x2,y2


# MAIN FUNCTION
def play_game(s1):
    print("Memory Game!")
    print("Welcome...")
    print("============================")
    while True:
        # Prints the grid
        print_grid(-1,-1,-1,-1)
        print("Your score is : ",counter)
        x1,y1,x2,y2 = read_input()
        # Check if the grid has a tie state
        if check_lose(s1):
            # Prints the grid
            print_grid(-1,-1,-1,-1)
            # Announcement of the final statement
            print("GAME OVER!")
            break
        else:
           print_grid(x1,y1,x2,y2)
           c=check_memory(x1,y1,x2,y2)
        # Check if the state of the grid has a win state
        if check_win():
            # Prints the grid
            print_grid(x1,y1,x2,y2)
            # Announcement of the final statement
            print("Congrats, you won!\n")
            break


while True:
    s1 = time.time()
    grid_clear()
    generate_numbers()
    #print(grid)
    play_game(s1)
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
