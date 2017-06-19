//Adjust BackY calculations

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "globals.h"
#include "classes.h"
#include "functions.h"


//==============================================
//GAME LOOP TABLE OF CONTENTS
//==============================================
/*
Input
    Key Up
    Key Down
    Display Close
    Mouse Axes
    Mouse Button Down
    Mouse Button Up
Game Update
    Update FPS
    Control Mode
        Change Mode
        Jump
        Climb Rope
        Change Maps
        Teleport
    Dialogue Mode
        Change Mode
    Archive Variables
    Adjust Horizontal Acceleration
    Adjust Horizontal Velocity
    Adjust Horizontal Position
    Detect Collision with Barriers
    Detect New CurPlatform
    Find TargetY
    Adjust Vertical Velocity
    Adjust Vertical Position
    Detect Collision with Ground
    Detect Collision with Bottom of Map
    Move NPCs
    Calculate Rendering Variables
Render
    Render Background
    Render Objects
    Render NPCs
    Render Player
    Flip Buffer
*/


//==============================================
//MAIN
//==============================================
int main(int argc, char **argv)
{
	//==============================================
	//SHELL VARIABLES
	//==============================================
	bool done = false;
	bool render = false;

	float gameTime = 0;
	int frames = 0;
	int gameFPS = 0;


	//==============================================
	//ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;
	ALLEGRO_SAMPLE *music = NULL;

    ALLEGRO_BITMAP *cursor_0 = NULL;
    ALLEGRO_BITMAP *cursor_1 = NULL;

    ALLEGRO_BITMAP *stand1_0 = NULL;
    ALLEGRO_BITMAP *stand1_1 = NULL;
    ALLEGRO_BITMAP *stand1_2 = NULL;
    ALLEGRO_BITMAP *stand1_3 = NULL;
    ALLEGRO_BITMAP *walk1_0 = NULL;
    ALLEGRO_BITMAP *walk1_1 = NULL;
    ALLEGRO_BITMAP *walk1_2 = NULL;
    ALLEGRO_BITMAP *walk1_3 = NULL;
    ALLEGRO_BITMAP *jump_0 = NULL;
    ALLEGRO_BITMAP *prone_0 = NULL;
    ALLEGRO_BITMAP *rope_0 = NULL;
    ALLEGRO_BITMAP *rope_1 = NULL;


	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create display object

	if(!display)										//test display object
		return -1;

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_install_audio();
    al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();


	//==============================================
	//PROJECT INIT
	//==============================================
	font18 = al_load_font("times.ttf", 18, 0);

	al_reserve_samples(1);
    music = al_load_sample("Sound/NLCtown.wav");

	cursor_0 = al_load_bitmap("UI/cursor_0.png");
	cursor_1 = al_load_bitmap("UI/cursor_1.png");


	//==============================================
	//MAP LIST
	//==============================================
    #include "maps.h"

    //==============================================
	//OBJECT LIST
	//==============================================
    #include "objects.h"

    //==============================================
	//NPC LIST
	//==============================================
    #include "npcs.h"

    //==============================================
	//CHARACTER DATA
	//==============================================
    #include "character_data.h"

    //==============================================
	//PLAYER
	//==============================================
    #include "players.h"


	//==============================================
	//GAME INIT
	//==============================================
    std::fstream a_file ("save.txt");   //Opens save file
    if(a_file.is_open())    //Tests if file opened properly
        {
            while(std::getline(a_file, line))  //Loops through each line
            {
                contents_of_file.push_back(line);   //Stores lines in dynamically sized vector
            }

        }
    else
        return -1;  //Return error if file did not open
    a_file.close();     //Closes save file

    const char * init_map = contents_of_file[0].c_str();    //Converts contents_of_file to const char*
	CurMap = atoi(init_map);    //Sets current map to integer version of init_map
	std::string init_player = contents_of_file[1].c_str(); //Converts contents_of_file to const char*

	(*MapList[CurMap]).Background = al_load_bitmap((*MapList[CurMap]).BackgroundName);  //Loads current map background

    for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)      //Loops through all object types
        (*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Image = al_load_bitmap((*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Name);     //Loads object types

    for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)      //Loops through all object types
        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image = al_load_bitmap((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).ImageText);     //Loads NPCs

    stand1_0 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/stand1_0.png").c_str());
    stand1_1 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/stand1_1.png").c_str());
    stand1_2 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/stand1_2.png").c_str());
    stand1_3 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/stand1_3.png").c_str());
    walk1_0 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/walk1_0.png").c_str());
    walk1_1 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/walk1_1.png").c_str());
    walk1_2 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/walk1_2.png").c_str());
    walk1_3 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/walk1_3.png").c_str());
    jump_0 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/jump_0.png").c_str());
    prone_0 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/prone_0.png").c_str());
    rope_0 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/rope_0.png").c_str());
    rope_1 = al_load_bitmap(("Player/" + init_player + "/default/frame 0/rope_1.png").c_str());

    std::vector< std::vector< int > > PlayerOffset;

    {
    int k = 0;
    for(int i=0; i<22; i++)
    {
        PlayerOffset.push_back(std::vector<int>());
        for(int j=0; j<2; j++)
            PlayerOffset[i].push_back(k++);
    }
    for(int i=0; i<2; i++)
    {
        for(int f=0; f<22; f++)
        {
            if(init_player == "QuickJumper7")
                PlayerOffset[f][i] = QuickJumper7[f][i];
            else if(init_player == "inairdrowned")
                PlayerOffset[f][i] = inairdrowned[f][i];
            else if(init_player == "eddy2edsmexy")
                PlayerOffset[f][i] = eddy2edsmexy[f][i];
        }
    }
    }

	//==============================================
	//TIMER INIT AND STARTUP
	//==============================================
	event_queue = al_create_event_queue();  //Creates event queue
	timer = al_create_timer(1.0 / 100);     //Sets game to 100 FPS

	al_register_event_source(event_queue, al_get_display_event_source(display));//Get events from close button
	al_register_event_source(event_queue, al_get_timer_event_source(timer));    //Get events from timer
	al_register_event_source(event_queue, al_get_keyboard_event_source());      //Get events from keyboard
	al_register_event_source(event_queue, al_get_mouse_event_source());         //Get events from mouse

	al_hide_mouse_cursor(display);  //Hide default mouse

	al_start_timer(timer);
	gameTime = al_current_time();


	//==============================================
	//GAME LOOP
	//==============================================
	while(!done)
	{
		ALLEGRO_EVENT ev;                       //Creates variable to handle current event
		al_wait_for_event(event_queue, &ev);    //Loads event from event_queue into ev

		//==============================================
		//INPUT
		//==============================================
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_ALT:
				keys[ALT] = true;
				break;
            case ALLEGRO_KEY_LCTRL:
                keys[LCTRL] = true;
                break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_ALT:
				keys[ALT] = false;
				break;
            case ALLEGRO_KEY_LCTRL:
                keys[LCTRL] = false;
                break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
             done = true;
        }
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
             CursorPosX = ev.mouse.x;
             CursorPosY = ev.mouse.y;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(ev.mouse.button & 1)
                CursorState = 1;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(ev.mouse.button & 1)
                CursorState = 0;
        }
		//==============================================
		//GAME UPDATE
		//==============================================
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			al_play_sample(music, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

			render = true;  //Allow rendering

			//UPDATE FPS===========
			frames++;
			if(al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;
			}
			//=====================

            ////////////////////////////////////////CONTROL MODE////////////////////////////////////////
            if(game_state == CONTROL)
            {
                ////////////////////////////////////////CHANGE MODE////////////////////////////////////////
                mode_timer++;
                for(int i=0;i<(*MapList[CurMap]).NumNPCs;i++)
                {
                    if(abs(CursorPosX-(*MapList[CurMap]).NPCs[i][1]-BackX-25)<20 && abs(CursorPosY-(*MapList[CurMap]).NPCs[i][2]+BackY-40)<40 && CursorState && mode_timer>=100)
                    {
                        mode_timer = 0;
                        game_state = QUEST;
                        CurNPC = i;
                        break;
                    }
                }

                ////////////////////////////////////////JUMP////////////////////////////////////////
                if(!onRope && onGround && keys[ALT] && keys[DOWN])  //If player is jumping down
                {
                    TargetY = (*MapList[CurMap]).MapHeight+1;       //Sets target y to a point below any possible platform
                    for(int i=0; i<(*MapList[CurMap]).NumPlat; i++) //Loops through current map's platforms
                    {
                        if((*MapList[CurMap]).Platforms[i][0] <= Player.PosX && (*MapList[CurMap]).Platforms[i][2] >= Player.PosX)    //If Player is within platform's X range
                        {
                            DBP = (*MapList[CurMap]).Platforms[i][2]-(*MapList[CurMap]).Platforms[i][0];    //Find X distance of platform
                            BigHypotenuse = sqrt(pow(DBP,2) + pow((*MapList[CurMap]).Platforms[i][1]-(*MapList[CurMap]).Platforms[i][3],2));    //Find total length of platform
                            Hypotenuse = BigHypotenuse * (Player.PosX - (*MapList[CurMap]).Platforms[i][0] + 25) / DBP;  //Find total distance between left point of platform and player

                            if((*MapList[CurMap]).Platforms[i][1] == (*MapList[CurMap]).Platforms[i][3])    //If the platform is flat
                                PlatformY = (*MapList[CurMap]).Platforms[i][1];     //Find Y coordinate of platform at current Player.PosX
                            else if((*MapList[CurMap]).Platforms[i][3] < (*MapList[CurMap]).Platforms[i][1])    //If the platform slopes up (left to right)
                                PlatformY = 715 - sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[i][0]+25,2));    //Find Y coordinate of platform at current Player.PosX
                            else if((*MapList[CurMap]).Platforms[i][3] > (*MapList[CurMap]).Platforms[i][1])    //If the platform slopes down (left to right)
                                PlatformY = 695 - (*MapList[CurMap]).Platforms[i][3] + (*MapList[CurMap]).Platforms[i][1] + sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[i][0]+25,2));  //Find Y coordinate of platform at current Player.PosX
                            if(PlatformY >= Player.PosY+1 && PlatformY < TargetY)    //If PlatformY is below player and above the bottom of the screen
                                {
                                    onGround = false;   //Jumping down succeeds
                                    Player.PosY += 1;    //Prevents snapping back to platform
                                    Player.VelX = 0;     //No movement to right or left

                                    break;  //No longer need to check the rest of the platforms
                                }
                        }
                    }
                }
                else if(!onRope && onGround && keys[ALT] && !keys[DOWN])    //If player is jumping up
                {
                    onGround = false;   //Jump
                    Player.VelY = 8.5;   //Upward vertical velocity
                    Player.VelX = 0;     //Resets horizontal velocity
                    if(keys[RIGHT] && Player.PosX > Player.LastPosX)     //Adjusts horizontal velocity
                        Player.VelX += 2;
                    if(keys[LEFT] && Player.PosX < Player.LastPosX)      //Adjusts horizontal velocity
                        Player.VelX -= 2;
                    if((*MapList[CurMap]).Platforms[CurPlatform][1] != (*MapList[CurMap]).Platforms[CurPlatform][3])    //If player is on a sloped platform
                        Player.VelX += (float((*MapList[CurMap]).Platforms[CurPlatform][3])-float((*MapList[CurMap]).Platforms[CurPlatform][1]))/(float((*MapList[CurMap]).Platforms[CurPlatform][2])-float((*MapList[CurMap]).Platforms[CurPlatform][0]));  //Adjust horizontal velocity
                }

                ////////////////////////////////////////CLIMB ROPE////////////////////////////////////////
                if(!onRope) //If player is not already on a rope
                {
                    for(int i=0; i<(*MapList[CurMap]).NumRope; i++) //Loops through all ropes
                    {
                        if(keys[UP] && Player.PosX+10 > (*MapList[CurMap]).Ropes[i][0] && Player.PosX-10 < (*MapList[CurMap]).Ropes[i][0] && Player.PosY > (*MapList[CurMap]).Ropes[i][1] && Player.PosY <= (*MapList[CurMap]).Ropes[i][2]+50) //If player is trying to get on rope
                        {
                            Player.PosX = (*MapList[CurMap]).Ropes[i][0];
                            Player.PosY -= 10;
                            onGround = false;
                            onRope = true;
                            CurRope = i;
                        }
                        else if(keys[DOWN] && Player.PosX+10 > (*MapList[CurMap]).Ropes[i][0] && Player.PosX-10 < (*MapList[CurMap]).Ropes[i][0] && Player.PosY >= (*MapList[CurMap]).Ropes[i][1] && Player.PosY < (*MapList[CurMap]).Ropes[i][2])  //If player is trying to get on rope (excludes top pixel of rope)
                        {
                            Player.PosX = (*MapList[CurMap]).Ropes[i][0];
                            onGround = false;
                            onRope = true;
                            CurRope = i;
                        }
                    }
                }

                if(onRope)  //If player is already on a rope
                {
                    if(keys[LEFT] && keys[ALT]) //If player is jumping off rope
                    {
                        onRope = false;
                        Player.VelX = -2;
                        Player.VelY = 5;
                    }
                    else if(keys[RIGHT] && keys[ALT])   //If player is jumping off rope
                    {
                        onRope = false;
                        Player.VelX = 2;
                        Player.VelY = 5;
                    }
                    else if(Player.PosY > (*MapList[CurMap]).Ropes[CurRope][2]+49)  //If player has reached bottom of rope
                    {
                        onRope = false;
                        Player.VelX = 0;
                        Player.VelY = 0;
                    }
                    else if(Player.PosY < (*MapList[CurMap]).Ropes[CurRope][1])  //If player has reached top of rope
                    {
                        onRope = false;
                        Player.VelX = 0;
                        Player.VelY = 0;
                    }
                }

                ////////////////////////////////////////CHANGE MAPS////////////////////////////////////////
                PortalWait++;   //Increments portalwait
                if(keys[UP] && PortalWait > 100)
                {
                    for(int i=0; i<(*MapList[CurMap]).NumPortal; i++) //Loops through all portals
                    {
                        if(Player.PosX>=(*MapList[CurMap]).Portals[i][0]-50 && Player.PosX<=(*MapList[CurMap]).Portals[i][0]+50 && Player.PosY>=(*MapList[CurMap]).Portals[i][1]-100 && Player.PosY<=(*MapList[CurMap]).Portals[i][1])
                        {
                            change_map((*MapList[CurMap]).Portals[i][2], Player);
                            Player.PosX = 150;
                            Player.PosY = 100;
                            PortalWait = 0;
                        }
                    }
                }

                ////////////////////////////////////////TELEPORT////////////////////////////////////////    //NEED TO DELETE
                if(onGround && !onRope && keys[LCTRL] && keys[RIGHT] && PortalWait > 60)
                {
                    Player.PosX += Player.VelX*50;
                    Player.LastPosX = Player.PosX;
                    PortalWait = 0;
                }
                else if(onGround && !onRope && keys[LCTRL] && keys[LEFT] && PortalWait > 60)
                {
                    Player.PosX -= -Player.VelX*50;
                    Player.LastPosX = Player.PosX;
                    PortalWait = 0;
                }
            }

            ////////////////////////////////////////DIALOGUE MODE////////////////////////////////////////
            else if(game_state == QUEST)
            {
                ////////////////////////////////////////CHANGE MODE////////////////////////////////////////
                mode_timer++;
                if(abs(CursorPosX-(*MapList[CurMap]).NPCs[CurNPC][1]-BackX-25)<20 && abs(CursorPosY-(*MapList[CurMap]).NPCs[CurNPC][2]+BackY-40)<40 && CursorState && mode_timer>=100)
                {
                    mode_timer = 0;
                    game_state = CONTROL;
                }
            }

            ////////////////////////////////////////ARCHIVE VARIABLES////////////////////////////////////////
            Player.LastPosX = Player.PosX;
            Player.LastPosY = Player.PosY;

            ////////////////////////////////////////ADJUST HORIZONTAL ACCELERATION////////////////////////////////////////
            if(onGround && !onRope) //If player is on ground
            {
                if(keys[LEFT] && !keys[RIGHT])  //If player is trying to go left
                    Player.AccX = -.25;  //Add force with the player
                else if(keys[RIGHT] && !keys[LEFT]) //If player is trying to go right
                    Player.AccX = .25;   //Add force with the player
                else if(Player.VelX > 0) //If player is going left but not pressing arrow keys
                    Player.AccX = -.25;  //Add force against the player
                else if(Player.VelX < 0) //If player is going right but not pressing arrow keys
                    Player.AccX = .25;   //Add force against the player
                else                    //If the player is not moving
                    Player.AccX = 0;     //Add no force
            }
            else if(onRope)    //If player is on rope
                Player.AccX = 0; //Add no force
            else if(Player.VelY>0)    //If player is in the air
            {
                if(keys[LEFT] && !keys[RIGHT])  //If player is trying to go left
                    Player.AccX = -.002;  //Add force with the player
                else if(keys[RIGHT] && !keys[LEFT]) //If player is trying to go right
                    Player.AccX = .002;   //Add force with the player
                else if(Player.VelX > 0) //If player is going left but not pressing arrow keys
                    Player.AccX = -.002;  //Add force against the player
                else if(Player.VelX < 0) //If player is going right but not pressing arrow keys
                    Player.AccX = .002;   //Add force against the player
                else                    //If the player is not moving
                    Player.AccX = 0;     //Add no force
            }
            else
                Player.AccX = 0;

            ////////////////////////////////////////ADJUST HORIZONTAL VELOCITY////////////////////////////////////////
            Player.VelX += Player.AccX;   //Add Acceleration to Velocity

            if(keys[RIGHT] && (*MapList[CurMap]).Platforms[CurPlatform][1] > (*MapList[CurMap]).Platforms[CurPlatform][3])  //If CurPlatform is sloped up (left to right) and player is going right
                Player.MaxVelX = 2+(float((*MapList[CurMap]).Platforms[CurPlatform][3])-float((*MapList[CurMap]).Platforms[CurPlatform][1]))/(float((*MapList[CurMap]).Platforms[CurPlatform][2])-float((*MapList[CurMap]).Platforms[CurPlatform][0]))*0.8;  //Set Max VelX higher than 2
            else if(keys[LEFT] && (*MapList[CurMap]).Platforms[CurPlatform][1] < (*MapList[CurMap]).Platforms[CurPlatform][3])  //If CurPlatform is sloped down (left to right) and player is going left
                Player.MaxVelX = 2-(float((*MapList[CurMap]).Platforms[CurPlatform][3])-float((*MapList[CurMap]).Platforms[CurPlatform][1]))/(float((*MapList[CurMap]).Platforms[CurPlatform][2])-float((*MapList[CurMap]).Platforms[CurPlatform][0]))*0.8;  //Set Max VelX higher than 2
            else    //If CurPlatform is flat
                Player.MaxVelX = 2;  //Set Max VelX at 2

            if(Player.VelX < -Player.MaxVelX && onGround) //If Player.VelX is beyond limit to left
                Player.VelX = -Player.MaxVelX;    //Set Player.VelX to limit
            else if(Player.VelX > Player.MaxVelX && onGround) //If Player.VelX is beyond limit to right
                Player.VelX = Player.MaxVelX; //Set Player.VelX to limit

            if(onGround && ((!keys[RIGHT] && !keys[LEFT]) || (keys[RIGHT] && keys[LEFT])) && (Player.VelX < 0.25 || Player.VelX > -0.25)) //If Player.VelX is very small
                Player.VelX = 0; //Set Player.VelX to 0
            if(game_state == QUEST)
                Player.VelX = 0;

            ////////////////////////////////////////ADJUST HORIZONTAL POSITION////////////////////////////////////////
            if(!onRope) //Don't adjust Player.PosX if player is on a rope
                Player.PosX += Player.VelX;   //Adds Player.VelX to Player.PosX

            ////////////////////////////////////////DETECT COLLISION WITH BARRIER////////////////////////////////////////
            for(int i=0; i<(*MapList[CurMap]).NumBarrier; i++)  //Loops through all barriers in the map
            {
                if(Player.VelX > 0 && Player.PosX > (*MapList[CurMap]).Barriers[i][0] && Player.LastPosX <= (*MapList[CurMap]).Barriers[i][0] && Player.PosY > (*MapList[CurMap]).Barriers[i][1] && Player.PosY <= (*MapList[CurMap]).Barriers[i][2]) //If player is passing barrier from left
                    Player.PosX = (*MapList[CurMap]).Barriers[i][0]-1;   //Put player back on left side
                else if(Player.VelX < 0 && Player.PosX < (*MapList[CurMap]).Barriers[i][0] && Player.LastPosX >= (*MapList[CurMap]).Barriers[i][0] && Player.PosY > (*MapList[CurMap]).Barriers[i][1] && Player.PosY <= (*MapList[CurMap]).Barriers[i][2])    //If player is passing barrier from right
                    Player.PosX = (*MapList[CurMap]).Barriers[i][0]+1;   //Put player back on right side
            }

            ////////////////////////////////////////DETECT NEW CURPLATFORM////////////////////////////////////////
            if(onGround)    //If player is on the ground
            {
                if(Player.LastPosX < Player.PosX) //If player is moving right
                {
                    if(!((*MapList[CurMap]).Platforms[CurPlatform][0] < Player.PosX && (*MapList[CurMap]).Platforms[CurPlatform][2] > Player.PosX) && CurPlatform < ((*MapList[CurMap]).NumPlat-1) && (*MapList[CurMap]).Platforms[CurPlatform][2] == (*MapList[CurMap]).Platforms[CurPlatform+1][0] && (*MapList[CurMap]).Platforms[CurPlatform][3] == (*MapList[CurMap]).Platforms[CurPlatform+1][1])   //If player is on a new platform
                        CurPlatform ++; //Change CurPlatform
                    else if(!((*MapList[CurMap]).Platforms[CurPlatform][0] < Player.PosX && (*MapList[CurMap]).Platforms[CurPlatform][2] > Player.PosX))  //If player walked off platform
                        onGround = false;   //Player is no longer on ground
                }
                if(Player.LastPosX > Player.PosX) //If player is moving left
                {
                    if(!((*MapList[CurMap]).Platforms[CurPlatform][0] < Player.PosX && (*MapList[CurMap]).Platforms[CurPlatform][2] > Player.PosX) && CurPlatform > 0 && (*MapList[CurMap]).Platforms[CurPlatform][0] == (*MapList[CurMap]).Platforms[CurPlatform-1][2] && (*MapList[CurMap]).Platforms[CurPlatform][1] == (*MapList[CurMap]).Platforms[CurPlatform-1][3])    //If player is on a new platform
                        CurPlatform --; //Change CurPlatform
                    else if(!((*MapList[CurMap]).Platforms[CurPlatform][0] < Player.PosX && (*MapList[CurMap]).Platforms[CurPlatform][2] > Player.PosX))  //If player walked off platform
                        onGround = false;   //Player is no longer on ground
                }
            }

            ////////////////////////////////////////FIND TARGETY////////////////////////////////////////
            if(!onGround)   //If player is not on the ground
            {
                TargetY = (*MapList[CurMap]).MapHeight+1;   //Sets target y to a point below any possible platform
                for(int i=0; i<(*MapList[CurMap]).NumPlat; i++) //Loops through all platforms on the map
                {
                    if((*MapList[CurMap]).Platforms[i][0] <= Player.PosX && (*MapList[CurMap]).Platforms[i][2] >= Player.PosX)    //If player is within platform's X range
                    {
                        DBP = (*MapList[CurMap]).Platforms[i][2]-(*MapList[CurMap]).Platforms[i][0];    //Finds horizontal distance of platform
                        BigHypotenuse = sqrt(pow(DBP,2) + pow((*MapList[CurMap]).Platforms[i][1]-(*MapList[CurMap]).Platforms[i][3],2));    //Finds total length of platform
                        Hypotenuse = BigHypotenuse * (Player.PosX - (*MapList[CurMap]).Platforms[i][0]) / DBP;  //Finds total distance between left point of platform and player

                        if((*MapList[CurMap]).Platforms[i][1] == (*MapList[CurMap]).Platforms[i][3])    //If the platform is flat
                            PlatformY = (*MapList[CurMap]).Platforms[i][1];
                        else if((*MapList[CurMap]).Platforms[i][3] < (*MapList[CurMap]).Platforms[i][1])    //If the platform is sloped up (left to right)
                            PlatformY = (*MapList[CurMap]).Platforms[i][1] - sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[i][0],2));    //Find Y coordinate of platform at current Player.PosX
                        else if((*MapList[CurMap]).Platforms[i][3] > (*MapList[CurMap]).Platforms[i][1])    //If the platform is sloped down (left to right)
                            PlatformY = (*MapList[CurMap]).Platforms[i][1] + sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[i][0],2));  //Find Y coordinate of platform at current Player.PosX
                        if(PlatformY >= Player.PosY && PlatformY < TargetY)  //If PlatformY is below player and above the bottom of the screen
                        {
                            TargetY = PlatformY;    //Set TargetY to platform's Y coordinate
                            CurPlatform = i;    //Sets CurPlatform as the platform being tested
                        }
                    }
                }
            }
            else    //If player is on the ground
            {
                DBP = (*MapList[CurMap]).Platforms[CurPlatform][2]-(*MapList[CurMap]).Platforms[CurPlatform][0];    //Finds horizontal distance of platform
                BigHypotenuse = sqrt(pow(DBP,2) + pow((*MapList[CurMap]).Platforms[CurPlatform][1]-(*MapList[CurMap]).Platforms[CurPlatform][3],2));    //Finds total length of platform
                Hypotenuse = BigHypotenuse * (Player.PosX - (*MapList[CurMap]).Platforms[CurPlatform][0]) / DBP;  //Finds total distance between left point of platform and player

                if((*MapList[CurMap]).Platforms[CurPlatform][1] == (*MapList[CurMap]).Platforms[CurPlatform][3])    //If the current platform is flat
                    TargetY = (*MapList[CurMap]).Platforms[CurPlatform][1];
                else if((*MapList[CurMap]).Platforms[CurPlatform][3] < (*MapList[CurMap]).Platforms[CurPlatform][1])    //If the current platform is sloped up (left to right)
                    TargetY = (*MapList[CurMap]).Platforms[CurPlatform][1] - sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[CurPlatform][0],2));    //Find TargetY
                else if((*MapList[CurMap]).Platforms[CurPlatform][3] > (*MapList[CurMap]).Platforms[CurPlatform][1])    //If the current platform is sloped down (left to right)
                    TargetY = (*MapList[CurMap]).Platforms[CurPlatform][1] + sqrt(pow(Hypotenuse,2) - pow(Player.PosX-(*MapList[CurMap]).Platforms[CurPlatform][0],2));  //Find TargetY
            }

            ////////////////////////////////////////ADJUST VERTICAL VELOCITY AND POSITION////////////////////////////////////////
            if(!onGround && !onRope)    //If player is in the air
            {
                if(Player.VelY > -20)    //Sets limit to Player.VelY
                    Player.VelY += Player.AccY;   //Increases Player.VelY by Player.AccY
                Player.PosY -= Player.VelY;   //Increases Player.PosY by Player.VelY
            }
            else if(!onRope)    //If player is on the ground
            {
                Player.VelY = 0; //Sets Player.VelY to 0
                Player.PosY = TargetY;   //Puts player on TargetY according to CurPlatform
            }
            else if(keys[UP] && !keys[DOWN])    //If player is on a rope and moving up
                Player.PosY -= 2;
            else if(keys[DOWN] && !keys[UP])    //If player is on a rope and moving down
                Player.PosY += 2;

            ////////////////////////////////////////DETECT COLLISION WITH GROUND////////////////////////////////////////
            if(!onGround && !onRope)    //If player is in the air
            {
                if((Player.PosY - Player.VelY) > TargetY) //If the player has fallen beneath the platform
                {
                    Player.PosY = TargetY;   //Puts player on platform
                    onGround = true;    //Player is now on ground
                    Player.VelY = 0;     //Player is no longer falling
                }
            }

            ////////////////////////////////////////DETECT COLLISION WITH BOTTOM OF MAP////////////////////////////////////////
            if(Player.PosY > (*MapList[CurMap]).MapHeight)   //If player has fallen beneath the bottom of the map
            {
                Player.PosX = 150;
                Player.PosY = 100;
                Player.VelX = 0;
                Player.VelY = -5;
                Player.AccX = 0;
                onGround = 0;
                Direction = 0;
            }

            ////////////////////////////////////////MOVE NPCS////////////////////////////////////////
            for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)
			{
			    (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).walk_timer++;
			    if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).walk_timer>100)
			    {
			        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).walk_timer = 0;
			        if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction==0 || (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction==1)
                        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction = rand()%4+2;
                    else
                        (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction = rand()%6;
			    }
			    if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction==0 && (*MapList[CurMap]).NPCs[i][1]<=(*MapList[CurMap]).NPCs[i][4])
                    (*MapList[CurMap]).NPCs[i][1]++;
			    else if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).direction==1 && (*MapList[CurMap]).NPCs[i][1]>=(*MapList[CurMap]).NPCs[i][3])
                    (*MapList[CurMap]).NPCs[i][1]--;
			}

            ////////////////////////////////////////CALCULATE RENDERING VARIABLES////////////////////////////////////////
            //Determines BackX
			if(Player.PosX-BackX > WIDTH)
                BackX += 100;
			else if(Player.PosX-BackX > 600)
                BackX += (Player.PosX-BackX-600)/100;
            else if(Player.PosX-BackX < 0)
                BackX -= 100;
            else if(Player.PosX-BackX < 400)
                BackX += (Player.PosX-BackX-400)/100;
            //Sets BackX limits
			if(BackX > (*MapList[CurMap]).MapWidth - WIDTH)
                BackX = (*MapList[CurMap]).MapWidth - WIDTH;
            else if(BackX < 0)
                BackX = 0;

            //Determines BackY
            if(Player.PosY-BackY > 700 && Player.VelY >= 0)
                BackY += 100;
            else if(Player.PosY-BackY > 700)
                BackY -= Player.VelY;
			else if(Player.PosY-BackY > 550)
                BackY += 2;
            else if(Player.PosY-BackY < 100 && Player.VelY <= 0)
                BackY -= 100;
            else if(Player.PosY-BackY < 100)
                BackY -= Player.VelY;
            else if(Player.PosY-BackY < 400)
                BackY -= 2;
			//Sets BackY limits
			if(BackY > (*MapList[CurMap]).MapHeight - HEIGHT)
                BackY = (*MapList[CurMap]).MapHeight - HEIGHT;
            else if(BackY < 0)
                BackY = 0;

            if(keys[RIGHT] && !keys[LEFT] && game_state==CONTROL)      //Determines if player is turned right
                    Direction = 0;
			else if(keys[LEFT] && !keys[RIGHT] && game_state==CONTROL) //Determines if player is turned left
                    Direction = 1;

            render_timer++;     //Increments render timer
            if(render_timer >= 50 && onRope)   //Resets render timer if in rope mode
                render_timer = 0;
            else if(render_timer >= 72 && Player.PosX != Player.LastPosX)   //Resets render timer if in walking mode
                render_timer = 0;
            else if(render_timer >= 200) //Resets render timer if in standing mode
                render_timer = 0;
		}


		//==============================================
		//RENDER
		//==============================================
		if(render && al_is_event_queue_empty(event_queue))  //Only render when no other event is ready to be processed
		{
			//BEGIN PROJECT RENDER================

			render = false; //Turns off rendering until next timer event

			//Renders background, uses functions that relate the map size with the background size and BackX/BackY
			al_draw_bitmap((*MapList[CurMap]).Background, -BackX*(1/(float((*MapList[CurMap]).MapWidth)-999))*(float(al_get_bitmap_width((*MapList[CurMap]).Background))-1000), -BackY*(1/(float((*MapList[CurMap]).MapHeight)-799))*(float(al_get_bitmap_height((*MapList[CurMap]).Background))-800), 0);

            for(int i=0; i<(*MapList[CurMap]).NumObjects; i++)  //Renders all objects in the map
            {
                al_draw_bitmap((*ObjectList[(*MapList[CurMap]).Objects[i][2]]).Image,(*MapList[CurMap]).Objects[i][0]-BackX*(*MapList[CurMap]).Objects[i][3]/100,(*MapList[CurMap]).Objects[i][1]-BackY*(*MapList[CurMap]).Objects[i][3]/100,0);
            }

			for(int i=0; i<(*MapList[CurMap]).NumPlat; i++) //Renders all platforms in the map
			{
			    al_draw_line((*MapList[CurMap]).Platforms[i][0]-BackX,(*MapList[CurMap]).Platforms[i][1]-BackY,(*MapList[CurMap]).Platforms[i][2]-BackX,(*MapList[CurMap]).Platforms[i][3]-BackY,al_map_rgb(0,0,255),1);
			}

			for(int i=0; i<(*MapList[CurMap]).NumBarrier; i++)  //Renders all barriers in the map
			{
			    al_draw_line((*MapList[CurMap]).Barriers[i][0]-BackX,(*MapList[CurMap]).Barriers[i][1]-BackY,(*MapList[CurMap]).Barriers[i][0]-BackX,(*MapList[CurMap]).Barriers[i][2]-BackY,al_map_rgb(0,255,0),1);
			}

			for(int i=0; i<(*MapList[CurMap]).NumRope; i++)     //Renders all ropes in the map
			{
			    al_draw_line((*MapList[CurMap]).Ropes[i][0]-BackX,(*MapList[CurMap]).Ropes[i][1]-BackY,(*MapList[CurMap]).Ropes[i][0]-BackX,(*MapList[CurMap]).Ropes[i][2]-BackY,al_map_rgb(255,0,0),1);
			}

			for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)     //Renders all NPCs in the map
			{
			    (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).bubble_timer++;
                if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).bubble_timer>300)
                {
                    (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).bubble_timer = 0;
                    (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).show_bubble = rand()%3;
                }

			    al_draw_bitmap((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image,(*MapList[CurMap]).NPCs[i][1]-BackX,(*MapList[CurMap]).NPCs[i][2]-BackY,0);
			    if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).show_bubble == 1)
			    {
                    al_draw_filled_rectangle((*MapList[CurMap]).NPCs[i][1]-50-BackX, (*MapList[CurMap]).NPCs[i][2]-60-BackY,(*MapList[CurMap]).NPCs[i][1]+100-BackX, (*MapList[CurMap]).NPCs[i][2]-BackY,al_map_rgb(0,0,0));
                    al_draw_textf(font18, al_map_rgb(255, 255, 255), (*MapList[CurMap]).NPCs[i][1]+30-BackX, (*MapList[CurMap]).NPCs[i][2]-40-BackY, ALLEGRO_ALIGN_CENTRE, "%s", (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Bubble1);
			    }
			    else if((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).show_bubble == 2)
			    {
			        al_draw_filled_rectangle((*MapList[CurMap]).NPCs[i][1]-50-BackX, (*MapList[CurMap]).NPCs[i][2]-60-BackY,(*MapList[CurMap]).NPCs[i][1]+100-BackX, (*MapList[CurMap]).NPCs[i][2]-BackY,al_map_rgb(0,0,0));
                    al_draw_textf(font18, al_map_rgb(255, 255, 255), (*MapList[CurMap]).NPCs[i][1]+30-BackX, (*MapList[CurMap]).NPCs[i][2]-40-BackY, ALLEGRO_ALIGN_CENTRE, "%s", (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Bubble2);
			    }
			    al_draw_textf(font18, al_map_rgb(0, 0, 0), (*MapList[CurMap]).NPCs[i][1]+30-BackX, (*MapList[CurMap]).NPCs[i][2]+100-BackY, ALLEGRO_ALIGN_CENTRE, "%s", (*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Name);
			}

            if(onRope)  //If player is on rope
            {
                if(render_timer >= 25 && Player.PosY != Player.LastPosY)
                    al_draw_bitmap(rope_1, Player.PosX-BackX+PlayerOffset[21][0], Player.PosY-BackY+PlayerOffset[21][1], 0);
                else if(render_timer >= 0)
                     al_draw_bitmap(rope_0, Player.PosX-BackX+PlayerOffset[21][0], Player.PosY-BackY+PlayerOffset[21][1], 0);
            }
            else if(Direction == 0) //If player is turned right
            {
                if(onGround && keys[DOWN] && !keys[LEFT] && !keys[RIGHT])  //If player laying down
                {
                    al_draw_bitmap(prone_0, Player.PosX-BackX-al_get_bitmap_width(prone_0)-PlayerOffset[15][0], Player.PosY-BackY+PlayerOffset[15][1], ALLEGRO_FLIP_HORIZONTAL);
                }
                else if(onGround && Player.PosX != Player.LastPosX)   //If player is walking
                {
                    if(render_timer >= 54)
                        al_draw_bitmap(walk1_3, Player.PosX-BackX-al_get_bitmap_width(walk1_3)-PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 36)
                        al_draw_bitmap(walk1_2, Player.PosX-BackX-al_get_bitmap_width(walk1_2)-PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 18)
                        al_draw_bitmap(walk1_1, Player.PosX-BackX-al_get_bitmap_width(walk1_1)-PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 0)
                        al_draw_bitmap(walk1_0, Player.PosX-BackX-al_get_bitmap_width(walk1_0)-PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], ALLEGRO_FLIP_HORIZONTAL);
                }
                else if(onGround)   //If player is standing
                {
                    if(render_timer >= 150)
                        al_draw_bitmap(stand1_3, Player.PosX-BackX-al_get_bitmap_width(stand1_3)-PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 100)
                        al_draw_bitmap(stand1_2, Player.PosX-BackX-al_get_bitmap_width(stand1_2)-PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 50)
                        al_draw_bitmap(stand1_1, Player.PosX-BackX-al_get_bitmap_width(stand1_1)-PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], ALLEGRO_FLIP_HORIZONTAL);
                    else if(render_timer >= 0)
                        al_draw_bitmap(stand1_0, Player.PosX-BackX-al_get_bitmap_width(stand1_0)-PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], ALLEGRO_FLIP_HORIZONTAL);
                }
                else    //If player is jumping
                    al_draw_bitmap(jump_0, Player.PosX-BackX-al_get_bitmap_width(jump_0)-PlayerOffset[18][0], Player.PosY-BackY+PlayerOffset[18][1], ALLEGRO_FLIP_HORIZONTAL);
            }
            else if(Direction == 1) //If player is turned left
            {
                if(onGround && keys[DOWN] && !keys[LEFT] && !keys[RIGHT])  //If player laying down
                {
                    al_draw_bitmap(prone_0, Player.PosX-BackX+PlayerOffset[15][0], Player.PosY-BackY+PlayerOffset[15][1], 0);
                }
                else if(onGround && Player.PosX != Player.LastPosX)   //If player is walking
                {
                    if(render_timer >= 54)
                        al_draw_bitmap(walk1_3, Player.PosX-BackX+PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], 0);
                    else if(render_timer >= 36)
                        al_draw_bitmap(walk1_2, Player.PosX-BackX+PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], 0);
                    else if(render_timer >= 18)
                        al_draw_bitmap(walk1_1, Player.PosX-BackX+PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], 0);
                    else if(render_timer >= 0)
                        al_draw_bitmap(walk1_0, Player.PosX-BackX+PlayerOffset[0][0], Player.PosY-BackY+PlayerOffset[0][1], 0);
                }
                else if(onGround)   //If player is standing
                {
                    if(render_timer >= 150)
                        al_draw_bitmap(stand1_3, Player.PosX-BackX+PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], 0);
                    else if(render_timer >= 100)
                        al_draw_bitmap(stand1_2, Player.PosX-BackX+PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], 0);
                    else if(render_timer >= 50)
                        al_draw_bitmap(stand1_1, Player.PosX-BackX+PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], 0);
                    else if(render_timer >= 0)
                        al_draw_bitmap(stand1_0, Player.PosX-BackX+PlayerOffset[1][0], Player.PosY-BackY+PlayerOffset[1][1], 0);
                }
                else    //If player is jumping
                    al_draw_bitmap(jump_0, Player.PosX-BackX+PlayerOffset[18][0], Player.PosY-BackY+PlayerOffset[18][1], 0);
            }

            if(game_state == QUEST)
            {
                al_draw_filled_rectangle(100,100,500,300,al_map_rgb(255,255,255));
                al_draw_textf(font18, al_map_rgb(0,0,0), 110, 110, 0, "%s", (*NPCList[(*MapList[CurMap]).NPCs[CurNPC][0]]).Say);
            }

            al_draw_textf(font18, al_map_rgb(0, 0, 0), 5, 15, 0, "CursorPosX: %i", abs(CursorPosX-(*MapList[CurMap]).NPCs[0][1]-BackX-25)); //Displays Player.LastPosX
            al_draw_textf(font18, al_map_rgb(0, 0, 0), 5, 35, 0, "CursorPosY: %i", abs(CursorPosY-(*MapList[CurMap]).NPCs[0][2]+BackY-40));  //Displays Player.PosY

            if(CursorState == 0)
                al_draw_bitmap(cursor_0, CursorPosX, CursorPosY, 0);  //Draw cursor
            if(CursorState == 1)
                al_draw_bitmap(cursor_1, CursorPosX, CursorPosY, 0);  //Draw cursor


			//FLIP BUFFERS========================
			al_flip_display();  //Reveal renderings
			al_clear_to_color(al_map_rgb(0,0,0)); //Default background set to black
		}
	}

	//==============================================
	//DESTROY PROJECT OBJECTS
	//==============================================

	//SHELL OBJECTS=================================
	al_destroy_font(font18);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_destroy_sample(music);

	//IMAGES=================================
	al_destroy_bitmap(cursor_0);
	al_destroy_bitmap(cursor_1);

	al_destroy_bitmap(stand1_0);
	al_destroy_bitmap(stand1_1);
	al_destroy_bitmap(stand1_2);
	al_destroy_bitmap(stand1_3);
	al_destroy_bitmap(walk1_0);
	al_destroy_bitmap(walk1_1);
	al_destroy_bitmap(walk1_2);
	al_destroy_bitmap(walk1_3);
	al_destroy_bitmap(jump_0);
	al_destroy_bitmap(prone_0);
	al_destroy_bitmap(rope_0);
	al_destroy_bitmap(rope_1);

	for(int i=0; i<(*MapList[CurMap]).NumObjectTypes; i++)  //Destroys all map object images
        al_destroy_bitmap((*ObjectList[(*MapList[CurMap]).ObjectTypes[i]]).Image);
    for(int i=0; i<(*MapList[CurMap]).NumNPCs; i++)  //Destroys all NPC images
        al_destroy_bitmap((*NPCList[(*MapList[CurMap]).NPCs[i][0]]).Image);
	al_destroy_bitmap((*MapList[CurMap]).Background);

	return 0;
}
