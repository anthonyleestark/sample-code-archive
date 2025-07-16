#ifndef _FILE_H
#define _FILE_H

#include "Noname.h"
#include "Map.h"
#include "Snake.h"

static void getMapFile(string sf, Map *map, Snake *snake)
{
	fstream f;
	f.open(sf, ios::in);
	short x, y;
	
	// set map size
	f >> x >> y;
	(*map).setSize({ x, y });
	
	// set snake components
	f >> x >> y;

	list<Point> *pComponents = new list<Point>;
	for (short i = (*snake).getLength() - 1; i >= 0; i--)
	{
		Point p;
		p.setPosition({ x, y - i });
		if (i == 0)
		{
			p.setSymbol(SS_HEAD);
			p.setColor(SC_HEAD);
		}
		else
		{
			p.setColor(SC_BODY);
			if (i == (*snake).getLength() - 1)
				p.setSymbol(S_VER);
			else
				p.setSymbol(S_VVER);
		}
		(*pComponents).push_front(p);
	}
	
	// set map board
	f.ignore();
	Vec2DChar *pBoard = new Vec2DChar;

	for (short i = 0; i < (*map).getSize().X; i++)
	{
		string s;
		getline(f, s);
		
		vector<char> rowOfBoard;
		for (short j = 0; j < (*map).getSize().Y; j++)
			rowOfBoard.push_back(exchange(s[j]));
		(*pBoard).push_back(rowOfBoard);
	}
	
	// sign snake in map board
	for (list<Point>::iterator iComponents = (*pComponents).begin(); iComponents != (*pComponents).end(); iComponents++)
		(*pBoard)[(*iComponents).getPosition().X][(*iComponents).getPosition().Y] = SI_SNAKE;

	(*snake).setComponents(pComponents);
	pComponents = NULL;

	(*map).setBoard(pBoard);
	pBoard = NULL;

	f.close();
}

#endif // _FILE_H