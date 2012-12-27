#pragma once

class Stage{
public:
	Stage();
	void checkID();
	
	void draw();
	void drawStage();
	void drawObject();

	static void setBrightPoints(int x, int y, int color);
	static bool getBrightPoints(int x, int y);
	static void eraseBrightPoints();
	static int getID(int x, int y);

private:
	static const int width = 10;
	static const int height = 10;

	int current_map;
	static int map[height][width];


	struct Cell{
		int id;
		int color;
		bool can_move_object;

		//あとで別のファイルに書く。
		int mapchip_color;
	};
	static Cell cell[height*width];
};