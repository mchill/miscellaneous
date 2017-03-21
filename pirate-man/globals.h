const int WIDTH = 448;  //Width of screen
const int HEIGHT = 576; //Height of screen

bool keys[] = {false, false, false, false, false};  //Array of key values, although only used for space
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};    //Array of keys

enum GAME_STATE{MENU, GAMEINFO, NEWLEVEL, PLAY, LOSE, WIN};   //Game states
enum GHOST_STATE{BASE, RETREAT, CHASE, BLUE, BLUEBASE, RETURN, LEAVEBASE};  //Ghost states
