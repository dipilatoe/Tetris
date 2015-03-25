#include "model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Constructor initializes the object
Model::Model(int h, int w) {
    ended = false;
    height = h;
    width = w;
<<<<<<< HEAD
    piece = (Tetrominoe)(time(0)%7);
    //pieces.push_back(piece);
    this->spawn(piece);
=======
    // Seed random number generator with time
    srand(time(0));
	// Spawn piece
    this->spawn();
>>>>>>> 15666118749690cf83be8488fd1337d86b1a4330
    // making a boolean grid to check where blocks are
    grid = new bool*[height+1];
    for (int i=0; i <= height; i++) {
        grid[i] = new bool[width];
        for (int j=0; j<width; j++) {
            if (i==height) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
    }
    delete grid;
}

bool Model::gameOver() {
    return false;
}

<<<<<<< HEAD
void Model::randomPiece() {
    piece = (Tetrominoe)(time(0)%7);
    //pieces.push_back(piece);
    this->spawn(piece);
}

void Model::spawn(Tetrominoe shape) {
    switch (shape) {
        case I:
            block1.x = 6;
            block2.x = 7;
            block3.x = 8;
            block4.x = 9;
            block1.y = 0;
            block2.y = block1.y;
            block3.y = block1.y;
            block4.y = block1.y;
            break;
        case O:
            block1.x = 7;
            block2.x = 8;
            block3.x = 7;
            block4.x = 8;
            block1.y = 0;
            block2.y = block1.y;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        case T:
            block1.x = 7;
            block2.x = 6;
            block3.x = 7;
            block4.x = 8;
            block1.y = 0;
            block2.y = block1.y+1;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        case S:
            block1.x = 7;
            block2.x = 8;
            block3.x = 6;
            block4.x = 7;
            block1.y = 0;
            block2.y = block1.y;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        case Z:
            block1.x = 6;
            block2.x = 7;
            block3.x = 7;
            block4.x = 8;
            block1.y = 0;
            block2.y = block1.y;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        case J:
            block1.x = 6;
            block2.x = 6;
            block3.x = 7;
            block4.x = 8;
            block1.y = 0;
            block2.y = block1.y+1;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        case L:
            block1.x = 8;
            block2.x = 6;
            block3.x = 7;
            block4.x = 8;
            block1.y = 0;
            block2.y = block1.y+1;
            block3.y = block1.y+1;
            block4.y = block1.y+1;
            break;
        default:
            break;
    }
=======
// Create a new piece
void Model::spawn() {
    shape = (Tetrominoe)(rand()%7);
	orientation = DOWN;
	location.x = 7;
	location.y = 0;
}

Coordinate * Model::block() {
	// All blocks by orientation and shape
	// block[orientation][shape]
	// Treat as a constant
	static Coordinate blocks[4][7][4] = {
	{ // UP
		{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // I
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, // O
		{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }, // T
		{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // S
		{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }, // Z
		{ {0, 1}, {0, 0}, {1, 0}, {2, 0} }, // J
		{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	},
	{ // DOWN
		{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // I
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, // O
		{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }, // T
		{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // S
		{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }, // Z
		{ {0, 1}, {0, 0}, {1, 0}, {2, 0} }, // J
		{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	},
	{ // LEFT
		{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // I
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, // O
		{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }, // T
		{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // S
		{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }, // Z
		{ {0, 1}, {0, 0}, {1, 0}, {2, 0} }, // J
		{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	},
	{ // RIGHT
		{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // I
		{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, // O
		{ {0, 1}, {1, 1}, {2, 1}, {1, 0} }, // T
		{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // S
		{ {0, 1}, {1, 1}, {1, 0}, {2, 0} }, // Z
		{ {0, 1}, {0, 0}, {1, 0}, {2, 0} }, // J
		{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	},
};

    // Building blocks for Tetrominoes
	return blocks[orientation][shape];
>>>>>>> 15666118749690cf83be8488fd1337d86b1a4330
}

// This should build up the pile structure (and do collision detection)
void Model::build() {
	/*
    switch (shape) {
        case I:
            block[1].y = block[0].y;
            block[2].y = block[0].y;
            block[3].y = block[0].y;
            break;
        case O:
            block[1].y = block[0].y;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        case T:
            block[1].y = block[0].y+1;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        case S:
            block[1].y = block[0].y;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        case Z:
            block[1].y = block[0].y;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        case J:
            block[1].y = block[0].y+1;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        case L:
            block[1].y = block[0].y+1;
            block[2].y = block[0].y+1;
            block[3].y = block[0].y+1;
        default:
            break;
    }
	*/
}

void Model::fall() {
	if (location.y < 22) {
	location.y++;
	cout << location.y << endl;
	} else {
        build();
	}
}

void Model::go(Direction d) {
    if (d == LEFT) {
        if (location.x > 0) {
            location.x--;
        }
    }
    if (d == RIGHT) {
        if (location.x < 15) {
            location.x++;
        }
    }
	if (d == UP) {
		orientation = (Direction)((((int)orientation) + 1) % 4);
	}
}