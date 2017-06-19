class Players {
    public:
        float PosX;     //Player's x position
        float PosY;     //Player's y position
        float VelX;       //Player's x velocity
        float VelY;      //Player's y velocity
        float AccX;       //Player's x acceleration
        float AccY;     //Player's y acceleration

        float MaxVelX;    //Maximum horizontal player velocity

        float LastPosX;   //Archives player's last x position
        float LastPosY;   //Archives player's last y position
    };

class Maps {    //Class for Maps
    public:
        float StartX;
        float StartY;

        int NumPlat;
        std::vector< std::vector< int > > Platforms;
        int NumBarrier;
        std::vector< std::vector< int > > Barriers;
        int NumPortal;
        std::vector< std::vector< int > > Portals;
        int NumRope;
        std::vector< std::vector< int > > Ropes;
        int NumObjects;
        std::vector< std::vector< int > > Objects;
        int NumObjectTypes;
        std::vector< int > ObjectTypes;
        int NumNPCs;
        std::vector< std::vector< int > > NPCs;

        int MapWidth;
        int MapHeight;
        const char* BackgroundName;
        ALLEGRO_BITMAP *Background;
    };

Maps * MapList[1001];   //Array of pointers to Maps objects

class Objects { //Class for Objects
    public:
        const char* Name;
        ALLEGRO_BITMAP *Image;
    };

Objects * ObjectList[50];   //Array of pointers to Objects objects

class NPCs {    //Class for NPCs
    public:
        const char* Name;
        const char* ImageText;
        ALLEGRO_BITMAP *Image;
        const char* Bubble1;
        const char* Bubble2;
        const char* Say;
        int bubble_timer;
        int show_bubble;
        int walk_timer;
        int direction;
    };

NPCs * NPCList[50];     //Array of pointers to NPCs objects

class Quests {  //Class for Quests
    public:
        const char* Name;
        int NPC;
        const char* Text;
    };

Quests * QuestList[50]; //Array of pointers to Quests objects
