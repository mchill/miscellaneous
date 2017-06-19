const int WIDTH = 1000;     //Width of screen
const int HEIGHT = 800;     //Height of screen

bool keys[] = {false, false, false, false, false, false};   //Array of key values
enum KEYS{UP, DOWN, LEFT, RIGHT, ALT, LCTRL};               //Array of keys

bool game_states[] = {false, false};
enum GAME_STATES{CONTROL, QUEST};

int game_state = CONTROL;
int mode_timer = 0;

int CurMap;                 //Current map's ID
int NewMap;                 //New map's ID

int CurPlatform;            //Current platform
int CurRope;                //Current rope

int CurNPC = 0;             //Current NPC being chatted

int PortalWait = 0;         //Portal delay

float DBP;                  //Used in finding TargetY
float Hypotenuse;           //Used in finding TargetY
float BigHypotenuse;        //Used in finding TargetY

float TargetY;              //Variable for where highest platform is underneath falling player
float PlatformY;            //Variable for where platform is underneath falling player

bool onGround = false;      //Variable for if player is on the ground
bool onRope = false;        //Variable for if player is on a rope

int Direction = 0;          //Used for rendering
int render_timer = 0;       //Used for rendering
float BackX = 0;              //Used for rendering
float BackY = 0;              //Used for rendering

int CursorState = 0;

int CursorPosX = 0;
int CursorPosY = 0;

std::string line;                           //String that holds save file lines
std::vector<std::string> contents_of_file;  //Array of save file lines
