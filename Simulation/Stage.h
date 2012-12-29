#pragma once
#include <vector>

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

private:
	static const int width = 10;
	static const int height = 10;

	static int map[height][width];
	int current_map;

	struct MapchipStatus{
		MapchipStatus(int id){ this-> id = id; }
		int id;
		bool movable;
		int mapchip_color;
	};

	struct Mapchip{
		int mapchip_color;
		int bright_color;
		bool can_move_object;
	};

	std::vector<MapchipStatus> mapchipStatus;
	static Mapchip mapchip[height][width];
};