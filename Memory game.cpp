#include <iostream>
#include <cstdlib>
#include<ctime>
#include <algorithm>
using namespace std;

const int N = 6;
int grid[N][N];
int counter=0;

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid(int x1, int y1, int x2, int y2) {

    cout << " __";
    for (int i = 0; i < N; cout << "_", i++);
    cout << "   \n";
    cout << "   \n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            if (i==x1 && j==y1)
                {cout<<grid[i][j]<<"  ";}
            else if (i==x2 && j==y2)
                {cout<<grid[i][j]<<"  ";}
            else if (grid[i][j])
                {cout<<'#'<<"  ";}
            else 
                cout<<" "<<"  ";
        cout << "|";
        cout << "  ";
        for (int i = 0; i < N; cout << "  ", i++);
        cout << "  \n";}
     cout << " __";
     for (int i = 0; i < N; cout << "_", i++);
     cout << "   ";

}
//This function checks if the game has a win state or not
bool check_lose(time_t s1 ) {
    time_t s2;
	s2 = time(NULL);
    if ( s2-s1 >= 60 )
        {return true;}
    else 
       {return false ;} 
}

bool check_win() {
    int c = 1;
    for(int i=0 ; i<N ;i++){
        for(int j=0 ; j<N ;j++){
            if (grid[i][j] != 0 )
                {c=0;}}}
    if (c == 1)
        {return true;}
    else
        {return false;}

}

//This function generates pac man
void generate_numbers(){
    srand( (unsigned)time( NULL ) );
    for (int i =0 ; i<N ; i++){
        for (int j =0 ; j<N ; j++){
            int sum=0;
            int n = rand()%18 +1 ;
            for (int l = 0 ; l<N ; l++){
               sum+=std::count (grid[l], grid[l]+N, n);}
            while ( sum>=2 ){
                int n = rand()%18 +1 ;
                sum=0;
                for (int l = 0 ; l<N ; l++){
                   sum+=std::count (grid[l], grid[l]+N, n);}}
            grid[i][j] = n;}}
}


//This function checks if given position is valid or not
bool check_valid_position(int x1, int y1, int x2, int y2) {
    bool valid= 0<=x1 && x1<N  && 0<=y1 && y1<N && 0<=x2 && x2<N  && 0<=y2 && y2<N && (x1!=x2 || y1!=y2);
     return valid;
}

bool check_memory(int x1, int y1, int x2, int y2){
    if  (grid[x1][y1] == grid[x2][y2]){
        grid[x1][y1] = 0;
        grid[x2][y2] = 0;
        counter+=1;
        return true;}
    else{
        return false;}
}

//This function clears the game structures
void grid_clear() {

        for (int i =0 ; i<N; i++){
            for (int j =0 ; j<N; j++){
                grid[i][j]=0 ;
            }
        }
        counter =0;
}
//This function reads a valid position input
void read_input(int &x1, int &y1, int &x2, int &y2) {
	cout << "Enter the row index and column index: ";
	cin >> x1 >> y1 >> x2 >> y2 ;
    while (!check_valid_position(x1 ,y1 ,x2 ,y2)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> x1 >> y1 >> x2 >> y2 ;
	}
}
//MAIN FUNCTION
void play_game(time_t si) {
    cout << "Memory Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";

    while (true) {
        //Prints the grid
        cout<<"Your score is : "<< counter<<endl;
        print_grid(-1,-1,-1,-1);

        //Read an input position from the player
        int x1 ,y1 ,x2 ,y2;
		read_input(x1 ,y1 ,x2 ,y2);

		if (check_lose(si)){
            print_grid(-1,-1,-1,-1);
			//Announcement of the final statement
            cout << "Game over !\n";
            break;
		}
		else{
        //Set the player mark in the input position
        print_grid(x1,y1,x2,y2);
        bool c=check_memory(x1,y1,x2,y2);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid(x1,y1,x2,y2);
			//Announcement of the final statement
            cout << "Congrats, YOU WON";
            break;
        }}
    }
}
int main() {
    while (true) {
    	time_t s1 = time(NULL);
        grid_clear();
        generate_numbers();
        play_game(s1);
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
