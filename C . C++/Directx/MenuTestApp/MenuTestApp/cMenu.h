#pragma once

#include <windows.h>
#include <map>
#include <string>
/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>

class cMenu
{
public:
	cMenu(){MenuIndex = 0;}
	~cMenu(){}

	void DrawMenu();

private:
	typedef struct tMenuItem
	{
		std::string title;
		float *cVar;
		int Step;
		int Min;
		int Max;
		tMenuItem(std::string _title) : title(_title){}
	};

	typedef boost::shared_ptr<tMenuItem> MenuPtr;
	//typedef std::tl1::shared_ptr<tMenuItem> MenuPtr;           Use this instead of the boost shared ptr if you don't have boost libs installed

	std::vector<MenuPtr> vMenuItems;

	void AddMenuItem(std::string Label, float *cVar,int step, int min, int max);
	void DrawMenuBackground();
	void DrawMenuItems();
	void InitItems();
	bool KeyMenuEvent();

	int MenuIndex;
	bool bMenu;
};

extern cMenu m_Menu;