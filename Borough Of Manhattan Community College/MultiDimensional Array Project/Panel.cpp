#include "Panel.h"
#include <iostream>
using namespace std;

Panel::Panel()
{
	fillchar = ' ';
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			content[tooRow][tooCol] = fillchar;
		}
	}
}

Panel::Panel(char f)
{
	fillchar = f;
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			content[tooRow][tooCol] = f;
		}
	}
}

void Panel::copyArrays(char tooCopy[ROW][COL])
{
	for (int tooRow = 0; tooRow < ROW;)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			content[tooRow][tooCol] = tooCopy[tooRow][tooCol];
		}
	}
};

void Panel::disp()
{
	cout << endl;
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			cout << content[tooRow][tooCol];
		}
		cout << endl;
	}
};

char Panel::getfillchar()
{
	return fillchar;
}

void Panel::setfillchar(char f)
{
	fillchar = f;
}

void Panel::fillPanel()
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			content[tooRow][tooCol] = fillchar;
		}
	}
}

void Panel::fillDiagLtoR(char f)
{
	{
		for (int tooRow = 0; tooRow < ROW; tooRow++)
		{
			for (int tooCol = 0; tooCol < COL; tooCol++)
			{
				if (tooRow == tooCol)
					content[tooRow][tooCol] = f;
			}
		}
	}
}

void Panel::fillDiagRtoL(char f)
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = ROW - 1; tooCol >= 0; tooCol--)
		{
			if (tooRow == ((ROW - 1) - tooCol))
				content[tooRow][tooCol] = f;
		}
	}
}

void Panel::flipVert()
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < ROW; tooCol++)
		{
			int tooContent = content[tooRow][tooCol];
			content[tooRow][tooCol] = content[tooCol][tooRow];
			content[tooCol][tooRow] = tooContent;
		}
	}

	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < ROW / 2; tooCol++)
		{
			int tooContent = content[tooRow][tooCol];
			content[tooRow][tooCol] = content[tooRow][ROW - tooCol - 1];
			content[tooRow][ROW - 1 - tooCol] = tooContent;
		}
	}
}

void Panel::flipHorz()
{
	for (int tooRow = 0; tooRow < COL; tooRow++)
	{
		for (int tooCol = 0; tooCol < ROW / 2; tooCol++)
		{
			int tooContent = content[tooCol][tooRow];
			content[tooCol][tooRow] = content[ROW - 1 - tooCol][tooRow];
			content[ROW - 1 - tooCol][tooRow] = tooContent;
		}
	}
}

void Panel::rotateRight()
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = tooRow; tooCol < ROW; tooCol++)
		{
			int tooContent = content[tooRow][tooCol];
			content[tooRow][tooCol] = content[tooCol][tooRow];
			content[tooCol][tooRow] = tooContent;
		}
	}

	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < ROW / 2; tooCol++)
		{
			int tooContent = content[tooRow][tooCol];
			content[tooRow][tooCol] = content[tooRow][ROW - 1 - tooCol];
			content[tooRow][ROW - 1 - tooCol] = tooContent;
		}
	}
}

void Panel::rotateLeft()
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = tooRow; tooCol < ROW; tooCol++)
		{
			int tooContent = content[tooCol][tooRow];
			content[tooCol][tooRow] = content[tooRow][tooCol];
			content[tooRow][tooCol] = tooContent;
		}
	}

	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < ROW / 2; tooCol++)
		{
			int tooContent = content[tooCol][tooRow];
			content[tooCol][tooRow] = content[ROW - tooCol - 1][tooRow];
			content[ROW - tooCol - 1][tooRow] = tooContent;
		}
	}
}

void Panel::copyPanel(const char tooCopy[ROW][COL])
{
	for (int tooRow = 0; tooRow < ROW; tooRow++)
	{
		for (int tooCol = 0; tooCol < COL; tooCol++)
		{
			content[tooRow][tooCol] = tooCopy[tooRow][tooCol];
		}
	}
}
