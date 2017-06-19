void setup_map(int PlatformsMap[][4], int BarriersMap[][3], int PortalsMap[][3], int RopesMap[][3], int ObjectsMap[][4], int ObjectTypes[], int NPCsMap[][5])  //Function used to initialize map object arrays
{
    ////////////////////////////////////////PLATFORM SETUP////////////////////////////////////////
    int k = 0;
	for(int i=0; i<(*MapList[CurMap]).NumPlat; i++)
	{
	    (*MapList[CurMap]).Platforms.push_back(std::vector<int>());
	    for(int j=0; j<4; j++)
            (*MapList[CurMap]).Platforms[i].push_back(k++);
	}
    for(int i=0; i<4; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumPlat; f++)
        {
            (*MapList[CurMap]).Platforms[f][i] = PlatformsMap[f][i];
        }
    }
    ////////////////////////////////////////BARRIER SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumBarrier; i++)
	{
	    (*MapList[CurMap]).Barriers.push_back(std::vector<int>());
	    for(int j=0; j<3; j++)
            (*MapList[CurMap]).Barriers[i].push_back(k++);
	}
    for(int i=0; i<3; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumBarrier; f++)
        {
            (*MapList[CurMap]).Barriers[f][i] = BarriersMap[f][i];
        }
    }
    ////////////////////////////////////////PORTAL SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumPortal; i++)
	{
	    (*MapList[CurMap]).Portals.push_back(std::vector<int>());
	    for(int j=0; j<3; j++)
            (*MapList[CurMap]).Portals[i].push_back(k++);
	}
    for(int i=0; i<3; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumPortal; f++)
        {
            (*MapList[CurMap]).Portals[f][i] = PortalsMap[f][i];
        }
    }
    ////////////////////////////////////////ROPE SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumRope; i++)
	{
	    (*MapList[CurMap]).Ropes.push_back(std::vector<int>());
	    for(int j=0; j<3; j++)
            (*MapList[CurMap]).Ropes[i].push_back(k++);
	}
    for(int i=0; i<3; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumRope; f++)
        {
            (*MapList[CurMap]).Ropes[f][i] = RopesMap[f][i];
        }
    }
    ////////////////////////////////////////OBJECT SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumObjects; i++)
	{
	    (*MapList[CurMap]).Objects.push_back(std::vector<int>());
	    for(int j=0; j<4; j++)
            (*MapList[CurMap]).Objects[i].push_back(k++);
	}
    for(int i=0; i<4; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumObjects; f++)
        {
            (*MapList[CurMap]).Objects[f][i] = ObjectsMap[f][i];
        }
    }
    ////////////////////////////////////////NUMBER OF OBJECTS SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)
	{
	    (*MapList[CurMap]).ObjectTypes.push_back(k++);
	}
    for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)
    {
        (*MapList[CurMap]).ObjectTypes[i] = ObjectTypes[i];
    }
    ///////////////////////////////////////NPC SETUP////////////////////////////////////////
    k = 0;
    for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)
	{
	    (*MapList[CurMap]).NPCs.push_back(std::vector<int>());
	    for(int j=0; j<5; j++)
            (*MapList[CurMap]).NPCs[i].push_back(k++);
	}
    for(int i=0; i<5; i++)
    {
        for(int f=0; f<(*MapList[CurMap]).NumNPCs; f++)
        {
            (*MapList[CurMap]).NPCs[f][i] = NPCsMap[f][i];
        }
    }
}


void change_map(int NewMap, Players Player) //Function used to change maps
{
    al_flip_display();  //Reveal renderings
	al_clear_to_color(al_map_rgb(0,0,0)); //Default background set to black

    al_destroy_bitmap((*MapList[CurMap]).Background);   //Destroy old map's barrier

    for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)  //Destroy old map's objects
    {
        al_destroy_bitmap((*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Image);
        (*ObjectList[(*MapList[CurMap]).ObjectTypes[0]]).Image = NULL;
    }

    for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)  //Destroys all NPC images
    {
        al_destroy_bitmap((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image);
        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image = NULL;
    }

    CurMap = NewMap;    //Changes CurMap to new map's ID

    std::ofstream a_file ("save.txt");  //Opens save file in append mode
    a_file << CurMap << std::endl << contents_of_file[1] << std::endl;      //Changes CurMap in save file
    a_file.close();                     //Closes save file

    (*MapList[CurMap]).Background = al_load_bitmap((*MapList[CurMap]).BackgroundName);  //Loads new map's background

    for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)  //Loads new map's objects
    {
        (*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Image = al_load_bitmap((*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Name);
    }

    for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)      //Loops through all NPCs
    {
        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image = al_load_bitmap((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).ImageText);     //Loads NPCs
    }

    onGround = false;   //Player enters new map in the air
    BackX = 0;
    BackY = 0;
    Player.VelX = 0;     //Default new map horizontal position
    Player.VelY = 0;     //Default new map vertical position
    Player.AccX = 0;

    al_rest(1.0);
}
