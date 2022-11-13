#ifndef _TILEMAP__H
#define _TILEMAP__H

#include "SDL2/SDL.h"
#include <string>
#include <vector>
#include <map>

class TileMap {
	struct MapSize {
		int x, y;
		int mWidth, mHeight;
	};
	struct TileSet {
		int tilewidth, tileheight;
		int w_size, h_size;
		int tileCount;
		void clear() {
			tilewidth = tileheight = w_size = h_size = tileCount = 0;
		}
	};
	struct source_from {
		std::string tileset_id;
		SDL_Rect src_rects;
	};
	MapSize m_size;
	TileSet m_tileset;
	std::vector<int> m_gid;
	std::vector<SDL_Rect> m_destination;
	/* contains id and src rectangle */
	std::map<int, source_from> t_source;

	void load_map(const char* fname);
	void calculate_destination_rects();
public:
	TileMap(std::string filename);
	~TileMap();
	void draw_map();
};

#endif