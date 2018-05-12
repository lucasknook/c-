/*Yes, it is useless, but I was bored, so I threw my mouse all over the desk, so I thought, 
why not make a program that tells me how far (in x and y positions) I moved it, so I can do it all day :D */

#include <iostream>
#include <Windows.h>
#include <math.h>

int main(int argc, char** argv) {
	POINT cursPos;
	POINT tempPos;
	POINT traveledPoint;
	long traveled;
	bool end = false;
	
	GetCursorPos(&cursPos);
	
	while(!end){
		tempPos = cursPos;
		
		GetCursorPos(&cursPos);
		
		traveledPoint.x = abs(cursPos.x - tempPos.x);
		traveledPoint.y = abs(cursPos.y - tempPos.y);
		
		if(sqrt(pow(traveledPoint.x, 2) + pow(traveledPoint.y, 2)) != 0){
			traveled += sqrt(pow(traveledPoint.x, 2) + pow(traveledPoint.y, 2));
			std::cout << traveled;
			std::cout << std::endl;
		}
	}
	
	return 0;
}
