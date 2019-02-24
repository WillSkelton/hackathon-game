# Tile Based Movement Game
### Created by:
- Bryce Turley
- Mitch Greer
- Will Skelton

## Workflow:
![Workflow](https://raw.githubusercontent.com/WillSkelton/hackathon-game/master/workflow.jpg)

## Libraries:
SDL2

## Objects
### Sprite:
```c++
class Sprite {
public:
	// CTOR
	Sprite();
	Sprite(int x, int y, char identifier);
	// CPY CTOR
	Sprite(Sprite &src);
	// DTOR
	~Sprite();
	// Getters
	char identifier;
	int coordinates[2];
};
```

### Player:
```c++
class Player : public Sprite {
public:
	// CTORs
	Player();
	Player(bool axe, bool pick, bool machete, bool plank);
	// DTOR
	~Player();
	// Setter
	void setPosition(int x, int y);	
	// Player Actions
	bool chopTree(MapElement *adjacentCell);
	bool breakRock(MapElement *adjacentCell);
	bool sliceGrass(MapElement *adjacentCell);
	bool throwPlank(MapElement *adjacentCell);
	bool analizeNextCell(MapElement *adjacentCell);
	// Items
	bool hasAxe;
	bool hasPick;
	bool hasMachete;
	bool hasPlank;
};
```

### MapElelement:
```c++
class MapElement : public Sprite {
public:
	MapElement();
	MapElement(int x, int y, char indentifier);
	void changeCoordinates(int x, int y);
	void brakeElement(void);
	bool canPass;
};
```

### Map:
```c++
class Map {
public:
	// CTORs
	Map();
	// DTOR
	~Map();
	// Fill Map
	void fillMap(Map *map);
	bool move(char direction);
	// Map
	MapElement grid[10][10];
	// Start and Finish Indices
	int startIndex[2];
	int endIndex[2];
	// Player
	Player player;
};
```

## Rendered Screenshot
![Screenshot](https://raw.githubusercontent.com/WillSkelton/hackathon-game/master/hackathon-game/screenshot.png)


