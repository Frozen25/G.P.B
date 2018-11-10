


/* @desc	A driver program to test class Maze.
*  @auth	Richard Dunks richarddunks@gmail.com
*/

#include <iostream>
#include "common.h"
#include "Maze.h"


#include "interfaceFLTK/interfaz.h"
#include <thread>
#include <fstream> 
#include <string>

int interfaz();
void function_();

char maze_e[30][30];

int main()
{

	//interfaz();
	std::thread interfaceThread(interfaz);
   	interfaceThread.detach();

	std::thread functionThread(function_ );
    functionThread.detach();

    while(true){
    	;
    }
	
} //end function main



void function_(){
	//variable declaration
	bool setFlag = false; //sentinel value for while loop
	int row;
	int col;
	Maze maze1; //instantiate Maze object
	
	//begin program function
	maze1.printMaze(); //display Maze

	//set start position
	while ( setFlag == false )
	{
		//std::cout << "Enter your starting position by first entering the row number.\n"
			//<< "Enter the row from 0 to " << (ROWS - 1) << std::endl;
		//std::cin >> row;
			row =15;
		//std::cout << "Now enter the column from 0 to " << (COLUMNS - 1) << std::endl;
		//std::cin >> col;
			col=0;
		//std::cout << std::endl;
		//std::cout << "The value you entered was: " << row << ", " << col << std::endl;
		if ( maze1.getCell( row, col ) != '+' && maze1.getCell( row, col ) != 'E' )
		{
			maze1.setStart( row, col ); //set starting position on maze
			setFlag = true;
		}
		else //position is either a block or an exit
		{
			std::cout << "That position isn't open. Please select again." << std::endl;
			std::cout << std::endl;
		} //end if to set start position
	} //end while

	std::cout << std::endl;
	maze1.printMaze(); //display maze
	std::cout << "Starting backTrack..." << std::endl;
	std::cout << std::endl;
	if ( maze1.backTrack( row, col ) == true )
	{
		std::cout << "Congratulations!" << std::endl;
	}
	else
	{
		std::cout << "Sorry, you didn't find the exit." << std::endl;	
	}
	maze1.printMaze(); //display maze
	//return 1;
}
    