#include "tilemap.h"
#include "TextureManager.h"
#include <iostream>
#include <tinyxml2.h>
using namespace tinyxml2;

constexpr float MAP_SIZE{ 1.5 };

TileMap::TileMap(std::string filename)
{
	this->load_map(filename.c_str());
}

TileMap::~TileMap()
{
	m_gid.clear();
	m_destination.clear();
	t_source.clear();

}

void TileMap::draw_map()
{
	for (size_t i = 0; i < (m_size.x * m_size.y); i++) {
		TextureManager::getInstance()->DrawTile(t_source[m_gid[i]].tileset_id,
			&t_source[m_gid[i]].src_rects,
			&m_destination[i]);
	}
}

void TileMap::load_map(const char* fname)
{
	XMLDocument doc;
	XMLError errn = doc.LoadFile(fname);
	if (errn != XML_SUCCESS) {
		doc.PrintError();
	}

	XMLElement* mNode = doc.FirstChildElement("map");

	mNode->QueryIntAttribute("width", &m_size.x);
	mNode->QueryIntAttribute("height", &m_size.y);
	mNode->QueryIntAttribute("tilewidth", &m_size.mWidth);
	mNode->QueryIntAttribute("tileheight", &m_size.mHeight);

	calculate_destination_rects();
	XMLElement* mTileset = mNode->FirstChildElement("tileset");
	if (mTileset != nullptr) {
		while (mTileset) {

			std::string tileset_id(mTileset->Attribute("name"));
			std::string srcname(mTileset->FirstChildElement("image")->Attribute("source"));
			std::string fullpath("assets/");
			fullpath.append(srcname);

			TextureManager::getInstance()->Load(fullpath, tileset_id);
			/* getting specific tileset properties */
			mTileset->QueryIntAttribute("tilewidth", &m_tileset.tilewidth);
			mTileset->QueryIntAttribute("tileheight", &m_tileset.tileheight);
			mTileset->QueryIntAttribute("tilecount", &m_tileset.tileCount);
			mTileset->FirstChildElement("image")->QueryIntAttribute("width", &m_tileset.w_size);
			mTileset->FirstChildElement("image")->QueryIntAttribute("height", &m_tileset.h_size);

			for (int i{ 0 }; i < m_tileset.tileCount; i++) {
				static SDL_Rect temp_src;
				temp_src.x = (i * m_tileset.tilewidth) % m_tileset.w_size;
				temp_src.w = m_tileset.tilewidth;
				temp_src.h = m_tileset.tileheight;

				t_source[i + 1].tileset_id = tileset_id;
				t_source[i + 1].src_rects = temp_src;
				if (temp_src.x == (m_tileset.w_size - m_tileset.tilewidth)) {
					temp_src.y += m_tileset.tileheight;
				}

			}

			m_tileset.clear();
			mTileset = mTileset->NextSiblingElement("tileset");
		}
	}

	XMLElement* mLayer = mNode->FirstChildElement("layer");
	if (mLayer != nullptr) {
		while (mLayer) {
			XMLElement* mData = mLayer->FirstChildElement("data");
			if (mData != nullptr) {
				while (mData) {
					XMLElement* mTile = mData->FirstChildElement("tile");
					if (mTile != nullptr) {
						while (mTile) {
							if (mTile->IntAttribute("gid") == 0) {
								m_gid.push_back(0);
							}
							else {
								static int temp_gid;
								mTile->QueryIntAttribute("gid", &temp_gid);
								m_gid.push_back(temp_gid);
							}

							/* next tile node */
							mTile = mTile->NextSiblingElement("tile");
						}
					}
					mData = mData->NextSiblingElement("data");
				}
			}
			mLayer = mLayer->NextSiblingElement("layer");
		}
	}

	std::cout << "gid size: " << m_gid.size() << "\ndest size: " << m_destination.size() << "\n";
}

void TileMap::calculate_destination_rects()
{
	SDL_Rect temp_dst_rect;
	for (int yy{ 0 }; yy < m_size.y; yy++) {
		for (int xx{ 0 }; xx < m_size.x; xx++) {
			temp_dst_rect.x = xx * m_size.mWidth * MAP_SIZE;
			temp_dst_rect.y = yy * m_size.mHeight * MAP_SIZE;
			temp_dst_rect.w = m_size.mWidth * MAP_SIZE;
			temp_dst_rect.h = m_size.mHeight * MAP_SIZE;
			
			this->m_destination.push_back(temp_dst_rect);
		}
	}
}
