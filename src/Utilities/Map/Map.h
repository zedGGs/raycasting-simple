#pragma once

typedef struct {
    int* blocks;
    int numBlocks;
    int numRows;
    int numColumns;
} Map;

Map   InitEmptyMap    ();
Map   AppendMapTile   (Map map, int newTile);
void  RemoveMap       (Map map);
int   GetMapTile      (Map map, int x, int y);
void  OutputMap       (Map map);
Map   CreateMap       (char* mapFileName);