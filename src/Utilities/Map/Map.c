#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Map.h"
#include "../Strings/StringLib.h"

Map InitEmptyMap() {
    Map map;
    map.blocks = (int*)malloc(0);
    map.numBlocks = 0;
    map.numRows = 0;
    map.numColumns = 0;
    return map;
}

Map AppendMapTile(Map map, int newBlock) {
    map.blocks = (int*)realloc(map.blocks, (map.numBlocks+1)*sizeof(int));
    map.blocks[map.numBlocks] = newBlock;
    map.numBlocks++;
    return map;
}

void RemoveMap(Map map) {
    free(map.blocks);
}

int GetMapTile(Map map, int x, int y) {
    return map.blocks[y*map.numColumns+x];
}
void OutputMap(Map map) {

    printf("Rows: %d, Columns: %d\n", map.numRows, map.numColumns);
    for (int i = map.numRows-1; i >= 0; i--) {
        for (int j = 0; j < map.numColumns; j++) {
            printf("%d", map.blocks[i*map.numColumns+j]);
        }
        printf("\n");
    }
}

Map CreateMap(char* mapFileName) {
    FILE* mapFile = fopen(mapFileName, "r");

    if (mapFile == NULL) {
        printf("Map file could not be read.\n");
        exit(1);
    }

    Map map = InitEmptyMap();

    char* currCellString = strdup("");
    bool cellReadInProgress = false;

    while (true) {
        char currentChar = fgetc(mapFile);

        bool isComma    = currentChar == ',';
        bool isNewLine  = currentChar == '\r' || currentChar == '\n';
        bool isEOF      = currentChar == EOF;

        if (isComma) {
            goto PushCurrentTileInfo;
        } else if (isNewLine) {
            if (cellReadInProgress == true) {
                map.numRows++;
                goto PushCurrentTileInfo;
            } else {
                continue;
            }
        } else if (isEOF) {
            map.numRows++;
            fclose(mapFile);
            goto PushCurrentTileInfoAndExitLoop;
        } else if (cellReadInProgress == true) {
            currCellString = AppendCharToString(currCellString, currentChar);
        } else {
            cellReadInProgress = true;
            currCellString = AppendCharToString(currCellString, currentChar);
            if (map.numRows == 0) {
                map.numColumns++;
            }
        }

        goto LoopEnd;

        PushCurrentTileInfo: {
            cellReadInProgress = false;
            map = AppendMapTile(map, currCellString[0] - '0');
            currCellString = ClearString(currCellString);
            goto LoopEnd;
        }

        PushCurrentTileInfoAndExitLoop : {
            cellReadInProgress = false;
            map = AppendMapTile(map, currCellString[0]-'0');
        }
            goto Exit;

        LoopEnd: {}
    }
    Exit: {}
    free(currCellString);

    Map FlippedMap = InitEmptyMap();
        FlippedMap.numRows = map.numRows;
        FlippedMap.numColumns = map.numColumns;

    for (int i = map.numRows-1; i >= 0; i--) {
        for (int j = 0; j < map.numColumns; j++) {
            FlippedMap = AppendMapTile(FlippedMap, map.blocks[i*map.numColumns+j]);
        }
    }
    RemoveMap(map);

    return FlippedMap;
}
