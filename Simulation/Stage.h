#pragma once
#include <vector>
using namespace std;

class Stage{
public:
	Stage();
	void initialize();
	void initID();
	void initMap();
	
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

private:
	static const int width = 10;
	static const int height = 10;

	static int map[height][width];
	int current_map;

	FILE* fp;
	int ret;
	int mapid;

	struct MapchipStatus{
		MapchipStatus(int id){ this-> id = id; }
		int id;
		int mapchip_color;
		int resistance;
	};

	struct Mapchip{
		int mapchip_color;
		int resistance;
		int bright_color;
		bool can_move_object;
	};

	vector<MapchipStatus> mapchipStatus;
	static Mapchip mapchip[height][width];
};