#include <iostream>
#include "PanelSize.h"
const int ROW = PANELSIZE;
const int COL = PANELSIZE;
class Panel
{
private:
	char content[ROW][COL];								// Panel content
	char fillchar;										// Fill character
	void copyArrays(char[ROW][COL]);					// Copies passed array into
														// panel content
public:
	Panel();											// Default constructor, fills the
														//content with ‘.’ character
	Panel(char);										// Overloaded constructor fills the
														// content with the passed character
	void disp();										// Displays the contents of
														// the Panel on the screen
	char getfillchar();									// Returns the fill character
	void setfillchar(char f);							// sets the fill character
	void fillPanel();									// Fills the panel with the
														// fill character
	void fillDiagLtoR(char f);							// Fills the diagonal (top left to
														// bottom right with the passed
														// character
	void fillDiagRtoL(char f);							// Fills the diagonal (top right to
														// bottom left with the passed
														// character
	void flipVert();									// Flips the contents of the Panel
														// along the vertical axis
	void flipHorz();									// Flips the contents of the Panel
														// along the horizontal axis
	void rotateRight();									// Rotates the contents of the Panel 90
														// degrees clockwise (to the right)
	void rotateLeft();									// Rotates the contents of the Panel 90
														// degrees counterclockwise (to the
														// left)
	void copyPanel(const char[ROW][COL]);				// copies the contents of the passed
														// array into the contents of the Panel
};
