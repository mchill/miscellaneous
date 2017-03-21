#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <math.h>

#include "globals.h"
#include "classes.h"
#include "functions.h"

int main(int argc, char **argv)
{
	//==============================================
	//SHELL VARIABLES
	//==============================================
	bool done = false;  //End the game loop when done is set to true
	bool render = false;    //Only render if render is set to true

	float gameTime = 0; //Keeps track of game time
	int frames = 0; //Keeps track of number of frames per second
	int gameFPS = 60;  //Set FPS

	//==============================================
	//PROJECT VARIABLES
	//==============================================
    int map_array[41][29] = {
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                            {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
                            {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
                            {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                            {1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1},
                            {1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1},
                            {1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
                            {1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                            {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
                            {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
                            {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1},
                            {1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
                            {1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
                            {1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1},
                            {1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
                            {1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                            };

    int pellet_array[240][3] =  {       //TileX, TileY, State
                                {2,3,1},{3,3,1},{4,3,1},{5,3,1},{6,3,1},{7,3,1},{8,3,1},{9,3,1},{10,3,1},{11,3,1},
                                {12,3,1},{13,3,1},{16,3,1},{17,3,1},{18,3,1},{19,3,1},{20,3,1},{21,3,1},{22,3,1},{23,3,1},
                                {24,3,1},{25,3,1},{26,3,1},{27,3,1},{2,4,1},{7,4,1},{13,4,1},{16,4,1},{22,4,1},{27,4,1},
                                {7,5,1},{13,5,1},{16,5,1},{22,5,1},{2,6,1},{7,6,1},{13,6,1},{16,6,1},{22,6,1},{27,6,1},
                                {2,7,1},{3,7,1},{4,7,1},{5,7,1},{6,7,1},{7,7,1},{8,7,1},{9,7,1},{10,7,1},{11,7,1},
                                {12,7,1},{13,7,1},{14,7,1},{15,7,1},{16,7,1},{17,7,1},{18,7,1},{19,7,1},{20,7,1},{21,7,1},
                                {22,7,1},{23,7,1},{24,7,1},{25,7,1},{26,7,1},{27,7,1},{2,8,1},{7,8,1},{10,8,1},{19,8,1},
                                {22,8,1},{27,8,1},{2,9,1},{7,9,1},{10,9,1},{19,9,1},{22,9,1},{27,9,1},{2,10,1},{3,10,1},
                                {4,10,1},{5,10,1},{6,10,1},{7,10,1},{10,10,1},{11,10,1},{12,10,1},{13,10,1},{16,10,1},{17,10,1},
                                {18,10,1},{19,10,1},{22,10,1},{23,10,1},{24,10,1},{25,10,1},{26,10,1},{27,10,1},{7,11,1},{22,11,1},
                                {7,12,1},{22,12,1},{7,13,1},{22,13,1},{7,14,1},{22,14,1},{7,15,1},{22,15,1},{7,16,1},{22,16,1},
                                {7,17,1},{22,17,1},{7,18,1},{22,18,1},{7,19,1},{22,19,1},{7,20,1},{22,20,1},{7,21,1},{22,21,1},
                                {2,22,1},{3,22,1},{4,22,1},{5,22,1},{6,22,1},{7,22,1},{8,22,1},{9,22,1},{10,22,1},{11,22,1},
                                {12,22,1},{13,22,1},{16,22,1},{17,22,1},{18,22,1},{19,22,1},{20,22,1},{21,22,1},{22,22,1},{23,22,1},
                                {24,22,1},{25,22,1},{26,22,1},{27,22,1},{2,23,1},{7,23,1},{13,23,1},{16,23,1},{22,23,1},{27,23,1},
                                {2,24,1},{7,24,1},{13,24,1},{16,24,1},{22,24,1},{27,24,1},{3,25,1},{4,25,1},{7,25,1},{8,25,1},
                                {9,25,1},{10,25,1},{11,25,1},{12,25,1},{13,25,1},{16,25,1},{17,25,1},{18,25,1},{19,25,1},{20,25,1},
                                {21,25,1},{22,25,1},{25,25,1},{26,25,1},{4,26,1},{7,26,1},{10,26,1},{19,26,1},{22,26,1},{25,26,1},
                                {4,27,1},{7,27,1},{10,27,1},{19,27,1},{22,27,1},{25,27,1},{2,28,1},{3,28,1},{4,28,1},{5,28,1},
                                {6,28,1},{7,28,1},{10,28,1},{11,28,1},{12,28,1},{13,28,1},{16,28,1},{17,28,1},{18,28,1},{19,28,1},
                                {22,28,1},{23,28,1},{24,28,1},{25,28,1},{26,28,1},{27,28,1},{2,29,1},{13,29,1},{16,29,1},{27,29,1},
                                {2,30,1},{13,30,1},{16,30,1},{27,30,1},{2,31,1},{3,31,1},{4,31,1},{5,31,1},{6,31,1},{7,31,1},
                                {8,31,1},{9,31,1},{10,31,1},{11,31,1},{12,31,1},{13,31,1},{14,31,1},{15,31,1},{16,31,1},{17,31,1},
                                {18,31,1},{19,31,1},{20,31,1},{21,31,1},{22,31,1},{23,31,1},{24,31,1},{25,31,1},{26,31,1},{27,31,1},
                                };

    int big_pellet_array[4][3] ={
                                {2,5,1},
                                {27,5,1},
                                {2,25,1},
                                {27,25,1}
                                };

    int state_timer = 0;
    int wait_timer = 240;
    int render_timer_pacman = 0;
    int render_timer_ghost = 0;

    int game_state = MENU;

    int num_pellets = 0;
    int last_score = 0;
    int score = 0;
    int lives = 3;

    int ghost_dir_offset = 0;

	mouse mouse;
	mouse.button1 = false;
	mouse.button2 = false;
	mouse.PosX = 0;
	mouse.PosY = 0;

    player pacman;
    enemy inky;
    enemy pinky;
    enemy clyde;
    enemy blinky;

    Initialize(pacman, inky, pinky, clyde, blinky, pellet_array, big_pellet_array);

    enemy* enemy_array[4] = {&inky, &pinky, &clyde, &blinky};

	//==============================================
	//ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;
	ALLEGRO_FONT *font36;

	ALLEGRO_BITMAP *map = NULL;
	ALLEGRO_BITMAP *pacman_image_1 = NULL;
	ALLEGRO_BITMAP *pacman_image_2 = NULL;
	ALLEGRO_BITMAP *sprite_sheet = NULL;

	ALLEGRO_SAMPLE *sample_extrapac = NULL;
	ALLEGRO_SAMPLE *sample_eatghost = NULL;
	ALLEGRO_SAMPLE *sample_eatfruit = NULL;
	ALLEGRO_SAMPLE *sample_intermission = NULL;
	ALLEGRO_SAMPLE *sample_beginning = NULL;
	ALLEGRO_SAMPLE *sample_chomp = NULL;
	ALLEGRO_SAMPLE *sample_death = NULL;

	ALLEGRO_SAMPLE_INSTANCE *instance_beginning = NULL;

	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if(!display)										//test display object
		return -1;

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_audio();
    al_init_acodec_addon();

	//==============================================
	//PROJECT INIT
	//==============================================
	font18 = al_load_font("times.ttf", 18, 0);
	font36 = al_load_font("times.ttf", 36, 0);

	map = al_load_bitmap("map.jpg");
	pacman_image_1 = al_load_bitmap("pirate1.png");
	pacman_image_2 = al_load_bitmap("pirate2.png");
	sprite_sheet = al_load_bitmap("sprite_sheet.png");

	al_reserve_samples(10);

	sample_extrapac = al_load_sample("sound_extrapac.wav");
	sample_eatghost = al_load_sample("sound_eatghost.wav");
	sample_eatfruit = al_load_sample("sound_cash.wav");
	sample_intermission = al_load_sample("sound_intermission.wav");
	sample_beginning = al_load_sample("sound_beginning.wav");
	sample_chomp = al_load_sample("sound_coin.wav");
	sample_death = al_load_sample("sound_argh.wav");

	instance_beginning = al_create_sample_instance(sample_beginning);
	al_set_sample_instance_playmode(instance_beginning, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance_beginning, al_get_default_mixer());


	//==============================================
	//TIMER INIT AND STARTUP
	//==============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / gameFPS);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);
	gameTime = al_current_time();
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

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
				pacman.next_dir = LEFT;
				break;
			case ALLEGRO_KEY_RIGHT:
				pacman.next_dir = RIGHT;
				break;
			case ALLEGRO_KEY_UP:
				pacman.next_dir = UP;
				break;
			case ALLEGRO_KEY_DOWN:
				pacman.next_dir = DOWN;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            mouse.PosX = ev.mouse.x;
            mouse.PosY = ev.mouse.y;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(ev.mouse.button & 2)
            {
                mouse.button2 = true;
            }
            else if(ev.mouse.button & 1)
            {
                mouse.button1 = true;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(ev.mouse.button & 2)
            {
                mouse.button2 = false;
            }
            else if(ev.mouse.button & 1)
            {
                mouse.button1 = false;
            }
        }
		//==============================================
		//GAME UPDATE
		//==============================================
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;

			//UPDATE FPS===========
			frames++;
			if(al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;
			}
			//=====================
            if(game_state == MENU)
            {
                if(mouse.button1 && mouse.PosX>=190 && mouse.PosX<=258 && mouse.PosY>=300 && mouse.PosY<=340)
                {
                    al_hide_mouse_cursor(display);
                    ChangeState(game_state, NEWLEVEL);
                    Initialize(pacman, inky, pinky, clyde, blinky, pellet_array, big_pellet_array);
                }
                else if(mouse.button1 && mouse.PosX>=90 && mouse.PosX<=358 && mouse.PosY>=350 && mouse.PosY<=390)
                {
                    ChangeState(game_state, GAMEINFO);
                }
            }
            else if(game_state == GAMEINFO)
            {
                if(mouse.button1 && mouse.PosX>=170 && mouse.PosX<=278 && mouse.PosY>=450 && mouse.PosY<=490)
                {
                    ChangeState(game_state, MENU);
                }
            }
            else if(game_state == NEWLEVEL)
            {
                if(wait_timer++ > 120)
                {
                    al_play_sample_instance(instance_beginning);

                    if(state_timer++ > 240)
                    {
                        state_timer = 0;
                        wait_timer = 0;
                        ChangeState(game_state, PLAY);
                    }
                }
            }
            else if(game_state == PLAY)
            {
                last_score = score;

                player::PacmanMove(pacman, map_array);

                for(int i=0; i<240; i++)
                {
                    if(pellet_array[i][2]==1 && pacman.cur_tile[0]==pellet_array[i][0]-1 && pacman.cur_tile[1]==pellet_array[i][1]-1)
                        {
                            al_play_sample(sample_chomp, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pellet_array[i][2] = 0;
                            num_pellets += 1;
                            score += 10;
                        }
                }

                for(int i=0; i<4; i++)
                {
                    if(big_pellet_array[i][2]==1 && pacman.cur_tile[0]==big_pellet_array[i][0]-1 && pacman.cur_tile[1]==big_pellet_array[i][1]-1)
                    {
                        al_play_sample(sample_eatfruit, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        big_pellet_array[i][2] = 0;
                        score += 50;
                        for(int j=0; j<4; j++)
                        {
                            (*enemy_array[j]).ghost_timer = 0;

                            if((*enemy_array[j]).ghost_state == CHASE || (*enemy_array[j]).ghost_state == RETREAT)
                                ChangeState(game_state, BLUE, *enemy_array[j]);
                            else if((*enemy_array[j]).ghost_state == BASE)
                                ChangeState(game_state, BLUEBASE, *enemy_array[j]);
                        }
                    }
                }

                if(num_pellets>=30 && inky.ghost_state==BASE)
                    inky.ghost_state = LEAVEBASE;
                else if(num_pellets>=60 && clyde.ghost_state==BASE)
                    clyde.ghost_state = LEAVEBASE;
                else if(num_pellets==240)
                {
                    al_play_sample(sample_intermission, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

                    al_show_mouse_cursor(display);
                    ChangeState(game_state, WIN);

                    num_pellets = 0;
                    score = 0;
                    lives = 3;
                    state_timer = 0;

                    for(int i=0; i<240; i++)
                    {
                        pellet_array[i][2] = 1;
                    }
                    for(int i=0; i<4; i++)
                    {
                        big_pellet_array[i][2] = 1;
                    }
                }

                if((last_score%2000)!=0 && (score%2000)==0 && lives!=3)
                {
                    al_play_sample(sample_extrapac, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    lives++;
                }

                state_timer++;

                for(int i=0; i<4; i++)
                {
                    (*enemy_array[i]).LastPosX = (*enemy_array[i]).PosX;
                    (*enemy_array[i]).LastPosY = (*enemy_array[i]).PosY;

                    if((*enemy_array[i]).ghost_state == BLUEBASE || (*enemy_array[i]).ghost_state == BLUE)
                    {
                        (*enemy_array[i]).ghost_timer++;

                        if((*enemy_array[i]).ghost_timer > 720)
                        {
                            if((*enemy_array[i]).ghost_state == BLUE && (*enemy_array[i]).PosX%2==0 && (*enemy_array[i]).PosY%2==0)
                            {
                                (*enemy_array[i]).ghost_timer = 0;
                                ChangeState(game_state, CHASE, *enemy_array[i]);
                            }
                            else if((*enemy_array[i]).ghost_state == BLUEBASE)
                            {
                                (*enemy_array[i]).ghost_timer = 0;
                                ChangeState(game_state, BASE, *enemy_array[i]);
                            }
                        }
                    }
                    else if(state_timer > 720)
                    {
                        if(i==3)
                            state_timer = 0;
                        if((*enemy_array[i]).ghost_state == RETREAT)
                            ChangeState(game_state, CHASE, *enemy_array[i]);
                        else if((*enemy_array[i]).ghost_state == CHASE)
                            ChangeState(game_state, RETREAT, *enemy_array[i]);
                    }

                    enemy::find_target_tile(*enemy_array[i], blinky, pacman, enemy_array);
                    enemy::GhostMove(*enemy_array[i], map_array);

                    if(pacman.PosX<=(*enemy_array[i]).PosX+16 && pacman.PosX>=(*enemy_array[i]).PosX-16 && pacman.PosY<=(*enemy_array[i]).PosY+16 && pacman.PosY>=(*enemy_array[i]).PosY-16)
                    {
                        if((*enemy_array[i]).ghost_state == BLUE)
                        {
                            al_play_sample(sample_eatghost, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            ChangeState(game_state, RETURN, *enemy_array[i]);
                        }
                        else if(!keys[SPACE] && (*enemy_array[i]).ghost_state != RETURN)
                        {
                            al_play_sample(sample_death, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

                            al_rest(1);

                            lives--;
                            ChangeState(game_state, NEWLEVEL);
                            state_timer = 0;

                            Initialize(pacman, inky, pinky, clyde, blinky, pellet_array, big_pellet_array);
                        }
                    }

                    if(lives == 0)
                    {
                        al_show_mouse_cursor(display);
                        ChangeState(game_state, LOSE);

                        num_pellets = 0;
                        score = 0;
                        lives = 3;
                        state_timer = 0;

                        for(int i=0; i<240; i++)
                        {
                            pellet_array[i][2] = 1;
                        }
                        for(int i=0; i<4; i++)
                        {
                            big_pellet_array[i][2] = 1;
                        }
                    }
                }
            }
            else if(game_state == LOSE)
            {
                if(mouse.button1 && mouse.PosX>=110 && mouse.PosX<=338 && mouse.PosY>=450 && mouse.PosY<=490)
                    ChangeState(game_state, MENU);
            }
            else if(game_state == WIN)
            {
                if(mouse.button1 && mouse.PosX>=110 && mouse.PosX<=338 && mouse.PosY>=450 && mouse.PosY<=490)
                    ChangeState(game_state, MENU);
            }
		}

		//==============================================
		//RENDER
		//==============================================
		if(render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			//BEGIN PROJECT RENDER================
            if(game_state == MENU)
            {
                al_draw_bitmap_region(sprite_sheet, 0, 300, 400, 58, 24, 100, 0);
                al_draw_text(font36, al_map_rgb(255, 255, 0), 224, 300, ALLEGRO_ALIGN_CENTRE, "Play");
                al_draw_text(font36, al_map_rgb(255, 255, 0), 224, 350, ALLEGRO_ALIGN_CENTRE, "Game Information");
            }
            else if(game_state == GAMEINFO)
            {
                al_draw_bitmap_region(sprite_sheet, 0, 300, 400, 58, 24, 100, 0);
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 260, ALLEGRO_ALIGN_CENTRE, "This game is meant to be a parody of Namco's Pacman.");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 290, ALLEGRO_ALIGN_CENTRE, "Images and sounds in this game are not owned by us.");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 320, ALLEGRO_ALIGN_CENTRE, "Redistribution of this game for profit is strictly forbidden.");
                al_draw_text(font36, al_map_rgb(255, 255, 0), 224, 450, ALLEGRO_ALIGN_CENTRE, "Return");
            }
            else if(game_state == NEWLEVEL)
            {
                al_draw_bitmap(map, 0, -32, 0);   //Draw background

                for(int i=0; i<240; i++)
                {
                    if(pellet_array[i][2])
                    {
                        al_draw_bitmap_region(sprite_sheet, 2, 1, 6, 6, pellet_array[i][0]*16-12, pellet_array[i][1]*16-11, 0);
                    }
                }

                for(int i=0; i<4; i++)
                {
                    if(big_pellet_array[i][2])
                    {
                        al_draw_bitmap_region(sprite_sheet, 10, 26, 19, 19, big_pellet_array[i][0]*16-18, big_pellet_array[i][1]*16-17, 0);
                    }
                }

                al_draw_bitmap(pacman_image_1, pacman.PosX-5, pacman.PosY-10, 0);  //Draw pacman

                for(int i=0; i<4; i++)  //Draw all 4 ghosts
                {
                    al_draw_bitmap_region(sprite_sheet, (*enemy_array[i]).offsets[0], (*enemy_array[i]).offsets[2], (*enemy_array[i]).offsets[1]-(*enemy_array[i]).offsets[0], (*enemy_array[i]).offsets[3]-(*enemy_array[i]).offsets[2], (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                }

                al_draw_textf(font36, al_map_rgb(255, 255, 255), 0, 530, 0, "SCORE: %i", score);
                al_draw_text(font36, al_map_rgb(255, 255, 255), 224, 530, 0, "LIVES");
                if(lives>2)
                    al_draw_bitmap(pacman_image_1, 390, 530, 0);
                if(lives>1)
                    al_draw_bitmap(pacman_image_1, 360, 530, 0);
                if(lives>0)
                    al_draw_bitmap(pacman_image_1, 330, 530, 0);
            }
            else if(game_state == PLAY)
            {
                al_draw_bitmap(map, 0, -32, 0);   //Draw background

                /*
                for(int i=0; i<28; i++)
                {
                    al_draw_line(16*i,0,16*i,576,al_map_rgb(255,0,0),0);
                }
                for(int i=0; i<36; i++)
                {
                    al_draw_line(0,16*i,448,16*i,al_map_rgb(255,0,0),0);
                }
                for(int i=0; i<28; i++)
                {
                    for(int j=0; j<41; j++)
                    {
                        if(map_array[j][i])
                        {
                            al_draw_filled_rectangle(16*i,16*j,16*(i+1),16*(j+1),al_map_rgb(255,0,0));
                        }
                    }
                }
                */

                for(int i=0; i<240; i++)
                {
                    if(pellet_array[i][2])
                    {
                        al_draw_bitmap_region(sprite_sheet, 2, 1, 6, 6, pellet_array[i][0]*16-12, pellet_array[i][1]*16-11, 0);
                    }
                }

                for(int i=0; i<4; i++)
                {
                    if(big_pellet_array[i][2])
                    {
                        al_draw_bitmap_region(sprite_sheet, 10, 26, 19, 19, big_pellet_array[i][0]*16-18, big_pellet_array[i][1]*16-17, 0);
                    }
                }

                render_timer_pacman++;
                if(render_timer_pacman<=30)
                {
                    al_draw_bitmap(pacman_image_1, pacman.PosX-5, pacman.PosY-10, 0);  //Draw pacman
                }
                else
                {
                    if(render_timer_pacman>=60)
                        render_timer_pacman = 0;
                    al_draw_bitmap(pacman_image_2, pacman.PosX-5, pacman.PosY-10, 0);  //Draw pacman
                }

                render_timer_ghost++;
                if(render_timer_ghost<=30)
                {
                    for(int i=0; i<4; i++)  //Draw all 4 ghosts
                    {
                        if((*enemy_array[i]).LastPosY > (*enemy_array[i]).PosY)
                            ghost_dir_offset = 0;
                        else if((*enemy_array[i]).LastPosY < (*enemy_array[i]).PosY)
                            ghost_dir_offset = 53;
                        else if((*enemy_array[i]).LastPosX > (*enemy_array[i]).PosX)
                            ghost_dir_offset = 106;
                        else if((*enemy_array[i]).LastPosX < (*enemy_array[i]).PosX)
                            ghost_dir_offset = 159;

                        if((*enemy_array[i]).ghost_state==BLUE || (*enemy_array[i]).ghost_state==BLUEBASE)
                        {
                            if(((*enemy_array[i]).ghost_timer>=510 && (*enemy_array[i]).ghost_timer<=540) || ((*enemy_array[i]).ghost_timer>=570 && (*enemy_array[i]).ghost_timer<=600) || ((*enemy_array[i]).ghost_timer>=630 && (*enemy_array[i]).ghost_timer<=660) || ((*enemy_array[i]).ghost_timer>=690 && (*enemy_array[i]).ghost_timer<=720))
                                al_draw_bitmap_region(sprite_sheet, 57, 206, 23, 28, (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                            else
                                al_draw_bitmap_region(sprite_sheet, 109, 206, 23, 28, (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                        }
                        else if((*enemy_array[i]).ghost_state==RETURN)
                            al_draw_bitmap_region(sprite_sheet, 162, 216, 9, 4, (*enemy_array[i]).PosX+4, (*enemy_array[i]).PosY+6, 0);
                        else
                            al_draw_bitmap_region(sprite_sheet, (*enemy_array[i]).offsets[0]+ghost_dir_offset, (*enemy_array[i]).offsets[2], (*enemy_array[i]).offsets[1]-(*enemy_array[i]).offsets[0], (*enemy_array[i]).offsets[3]-(*enemy_array[i]).offsets[2], (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                    }
                }
                else
                {
                    if(render_timer_ghost>=60)
                        render_timer_ghost = 0;
                    for(int i=0; i<4; i++)  //Draw all 4 ghosts
                    {
                        if((*enemy_array[i]).LastPosY > (*enemy_array[i]).PosY)
                            ghost_dir_offset = 0;
                        else if((*enemy_array[i]).LastPosY < (*enemy_array[i]).PosY)
                            ghost_dir_offset = 53;
                        else if((*enemy_array[i]).LastPosX > (*enemy_array[i]).PosX)
                            ghost_dir_offset = 106;
                        else if((*enemy_array[i]).LastPosX < (*enemy_array[i]).PosX)
                            ghost_dir_offset = 159;

                        if((*enemy_array[i]).ghost_state==BLUE || (*enemy_array[i]).ghost_state==BLUEBASE)
                        {
                            if(((*enemy_array[i]).ghost_timer>=510 && (*enemy_array[i]).ghost_timer<=540) || ((*enemy_array[i]).ghost_timer>=570 && (*enemy_array[i]).ghost_timer<=600) || ((*enemy_array[i]).ghost_timer>=630 && (*enemy_array[i]).ghost_timer<=660) || ((*enemy_array[i]).ghost_timer>=690 && (*enemy_array[i]).ghost_timer<=720))
                                al_draw_bitmap_region(sprite_sheet, 82, 206, 23, 28, (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                            else
                                al_draw_bitmap_region(sprite_sheet, 135, 206, 23, 28, (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                        }
                        else if((*enemy_array[i]).ghost_state==RETURN)
                            al_draw_bitmap_region(sprite_sheet, 162, 216, 9, 4, (*enemy_array[i]).PosX+4, (*enemy_array[i]).PosY+6, 0);
                        else
                            al_draw_bitmap_region(sprite_sheet, (*enemy_array[i]).offsets[0]+27+ghost_dir_offset, (*enemy_array[i]).offsets[2], (*enemy_array[i]).offsets[1]-(*enemy_array[i]).offsets[0], (*enemy_array[i]).offsets[3]-(*enemy_array[i]).offsets[2], (*enemy_array[i]).PosX-4, (*enemy_array[i]).PosY-6, 0);
                    }
                }

                al_draw_textf(font36, al_map_rgb(255, 255, 255), 0, 530, 0, "SCORE: %i", score);
                al_draw_text(font36, al_map_rgb(255, 255, 255), 224, 530, 0, "LIVES");
                if(lives>2)
                    al_draw_bitmap(pacman_image_1, 390, 530, 0);
                if(lives>1)
                    al_draw_bitmap(pacman_image_1, 360, 530, 0);
                if(lives>0)
                    al_draw_bitmap(pacman_image_1, 330, 530, 0);
            }
            else if(game_state == LOSE)
            {
                al_draw_bitmap_region(sprite_sheet, 0, 300, 400, 58, 24, 100, 0);
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 260, ALLEGRO_ALIGN_CENTRE, "Sorry, you lost the game.");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 290, ALLEGRO_ALIGN_CENTRE, "Try again, and don't give up!");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 320, ALLEGRO_ALIGN_CENTRE, "Tip - Try to avoid the ghosts.");
                al_draw_text(font36, al_map_rgb(255, 255, 0), 224, 450, ALLEGRO_ALIGN_CENTRE, "Return to Menu");
            }
            else if(game_state == WIN)
            {
                al_draw_bitmap_region(sprite_sheet, 0, 300, 400, 58, 24, 100, 0);
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 260, ALLEGRO_ALIGN_CENTRE, "Congratulations! You have won the game!");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 290, ALLEGRO_ALIGN_CENTRE, "If you would like to unlock the last 255 levels, please");
                al_draw_text(font18, al_map_rgb(255, 255, 0), 224, 320, ALLEGRO_ALIGN_CENTRE, "make the game yourself. Thank you for playing.");
                al_draw_text(font36, al_map_rgb(255, 255, 0), 224, 450, ALLEGRO_ALIGN_CENTRE, "Return to Menu");
            }

			//FLIP BUFFERS========================
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	//==============================================
	//DESTROY PROJECT OBJECTS
	//==============================================

	//SHELL OBJECTS=================================
	al_destroy_font(font18);
	al_destroy_font(font36);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	al_destroy_bitmap(map);
	al_destroy_bitmap(pacman_image_1);
	al_destroy_bitmap(pacman_image_2);
	al_destroy_bitmap(sprite_sheet);

	al_destroy_sample(sample_extrapac);
	al_destroy_sample(sample_eatghost);
	al_destroy_sample(sample_eatfruit);
	al_destroy_sample(sample_intermission);
	al_destroy_sample(sample_beginning);
	al_destroy_sample(sample_chomp);
	al_destroy_sample(sample_death);

	al_destroy_sample_instance(instance_beginning);

	return 0;
}
