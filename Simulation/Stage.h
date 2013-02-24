#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Position.h"
using namespace std;

class Stage{
public:
	Stage();
	void initialize();
	void initID();
	void initMap();
	
	void update();
	void draw();
	void drawMap();
	void drawBrightPoints();

	static void setBrightPoints(int x, int y, int color);
	static bool getBrightPoints(int x, int y);
	static void eraseBrightPoints();
	static bool canMove(int x, int y);
	static int getResistance(int x, int y);

	static int getWidth(){ return width; }
	static int getHeight(){ return height; }
	static int getLeftupPositionX(){ return leftup_positionX; }
	static int getLeftupPositionY(){ return leftup_positionY; }

private:
	int current_map;

	static int width;
	static int height;
	static int leftup_positionX;
	static int leftup_positionY;

	struct MapchipStatus{
		MapchipStatus(int id){ this-> id = id; }
		int id;
		int mapchip_color;
		int resistance;
	};

	struct Mapchip{
		Mapchip():varpos(0,0){};
		Position varpos;
		int id;
		int mapchip_color;
		int resistance;
		int bright_color;
		bool can_move_object;
	};

	vector<MapchipStatus> mapchipStatus;
	static Mapchip mapchip[100][100];	//予め100x100のメモリを確保

public:
	static Position pos(int x, int y){ return mapchip[x][y].varpos; }
};