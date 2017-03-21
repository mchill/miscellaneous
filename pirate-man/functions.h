void Initialize(player &pacman, enemy &inky, enemy &pinky, enemy &clyde, enemy &blinky, int pellet_array[240][3], int big_pellet_array[4][3]) //Initializes pacman and ghost member variables
{
    pacman.PosX = 216;
    pacman.PosY = 384;
    pacman.cur_dir = LEFT;
    pacman.next_dir = LEFT;

    inky.ghost_state = BASE;
    inky.LastPosX = 0;
    inky.LastPosY = 0;
    inky.PosX = 184;
    inky.PosY = 240;
    inky.cur_dir = UP;
    inky.next_dir = UP;
    inky.ghost_timer = 0;
    inky.offsets[0] = 56;
    inky.offsets[1] = 79;
    inky.offsets[2] = 47;
    inky.offsets[3] = 74;

    pinky.ghost_state = BASE;
    pinky.LastPosX = 0;
    pinky.LastPosY = 0;
    pinky.PosX = 216;
    pinky.PosY = 240;
    pinky.cur_dir = UP;
    pinky.next_dir = UP;
    pinky.ghost_timer = 0;
    pinky.offsets[0] = 56;
    pinky.offsets[1] = 79;
    pinky.offsets[2] = 83;
    pinky.offsets[3] = 110;

    clyde.ghost_state = BASE;
    clyde.LastPosX = 0;
    clyde.LastPosY = 0;
    clyde.PosX = 248;
    clyde.PosY = 240;
    clyde.cur_dir = UP;
    clyde.next_dir = UP;
    clyde.ghost_timer = 0;
    clyde.offsets[0] = 56;
    clyde.offsets[1] = 79;
    clyde.offsets[2] = 127;
    clyde.offsets[3] = 154;

    blinky.ghost_state = RETREAT;
    blinky.LastPosX = 0;
    blinky.LastPosY = 0;
    blinky.PosX = 216;
    blinky.PosY = 192;
    blinky.cur_dir = LEFT;
    blinky.next_dir = LEFT;
    blinky.ghost_timer = 0;
    blinky.offsets[0] = 56;
    blinky.offsets[1] = 79;
    blinky.offsets[2] = 163;
    blinky.offsets[3] = 190;
}

void ChangeState(int &state, int newState)  //Changes game state, displays message
{
     if(state == MENU)
     {
          //std::cout << "Leaving the MENU state\n";
     }
     else if(state == GAMEINFO)
     {
          //std::cout << "Leaving the GAMEINFO state\n";
     }
     else if(state == NEWLEVEL)
     {
          //std::cout << "Leaving the NEWLEVEL state\n";
     }
     else if(state == PLAY)
     {
          //std::cout << "Leaving the PLAY state\n";
     }
     else if(state == LOSE)
     {
          //std::cout << "Leaving the LOSE state\n";
     }
     else if(state == WIN)
     {
          //std::cout << "Leaving the WIN state\n";
     }

     state = newState;

     if(state == MENU)
     {
          //std::cout << "Now in MENU\n";
     }
     else if(state == GAMEINFO)
     {
          //std::cout << "Now starting GAMEINFO\n";
     }
     else if(state == NEWLEVEL)
     {
          //std::cout << "Now starting NEWLEVEL\n";
     }
     else if(state == PLAY)
     {
          //std::cout << "Beginning to PLAY\n";
     }
     else if(state == LOSE)
     {
          //std::cout << "You LOSE\n";
     }
     else if(state == WIN)
     {
          //std::cout << "You WIN\n";
     }
}

void ChangeState(int &state, int newState, enemy &some_enemy)   //Changes ghost state, displays message
{
    if(some_enemy.ghost_state == BASE)
     {
          //std::cout << "Leaving the BASE state\n";
     }
     else if(some_enemy.ghost_state == RETREAT)
     {
          //std::cout << "Leaving the RETREAT state\n";
     }
     else if(some_enemy.ghost_state == CHASE)
     {
          //std::cout << "Leaving the CHASE state\n";
     }
     else if(some_enemy.ghost_state == BLUE)
     {
          //std::cout << "Leaving the BLUE state\n";
     }
     else if(some_enemy.ghost_state == BLUEBASE)
     {
          //std::cout << "Leaving the BLUEBASE state\n";
     }
     else if(some_enemy.ghost_state == RETURN)
     {
          //std::cout << "Leaving the RETURN state\n";
     }
     else if(some_enemy.ghost_state == LEAVEBASE)
     {
          //std::cout << "Leaving the LEAVEBASE state\n";
     }

     some_enemy.ghost_state = newState;

     if(some_enemy.ghost_state == BASE)
     {
          //std::cout << "Now in BASE state\n";
     }
     else if(some_enemy.ghost_state == RETREAT)
     {
          //std::cout << "Now in RETREAT state\n";
     }
     else if(some_enemy.ghost_state == CHASE)
     {
          //std::cout << "Now in CHASE state\n";
     }
     else if(some_enemy.ghost_state == BLUE)
     {
          //std::cout << "Now in BLUE state\n";
     }
     else if(some_enemy.ghost_state == BLUEBASE)
     {
          //std::cout << "Now in BLUEBASE state\n";
     }
     else if(some_enemy.ghost_state == RETURN)
     {
          //std::cout << "Now in RETURN state\n";
     }
     else if(some_enemy.ghost_state == LEAVEBASE)
     {
          //std::cout << "Now in LEAVEBASE state\n";
     }
}

void player::PacmanMove(player &pacman, int map_array[41][29])  //Controls pacman movement
{
    if(pacman.next_dir!=pacman.cur_dir && pacman.next_dir == RIGHT && pacman.PosY%16==0 && !map_array[pacman.PosY / 16][(pacman.PosX+16) / 16]) //If pacman wants to and can go right
    {
        pacman.PosX += 2;   //Go right
        pacman.cur_dir = pacman.next_dir;   //Is now going right
    }
    else if(pacman.next_dir!=pacman.cur_dir && pacman.next_dir == LEFT && pacman.PosY%16==0 && !map_array[pacman.PosY / 16][(pacman.PosX-16) / 16]) //If pacman wants to and can go left
    {
        pacman.PosX -= 2;   //Go left
        pacman.cur_dir = pacman.next_dir;   //Is now going left
    }
    else if(pacman.next_dir!=pacman.cur_dir && pacman.next_dir == UP && pacman.PosX%16==0 && !map_array[(pacman.PosY-16) / 16][pacman.PosX / 16])   //If pacman wants to and can go up
    {
        pacman.PosY -= 2;   //Go up
        pacman.cur_dir = pacman.next_dir;   //Is now going up
    }
    else if(pacman.next_dir!=pacman.cur_dir && pacman.next_dir == DOWN && pacman.PosX%16==0 && !map_array[(pacman.PosY+16) / 16][pacman.PosX / 16]) //If pacman wants to and can go down
    {
        pacman.PosY += 2;   //Go down
        pacman.cur_dir = pacman.next_dir;   //Is now going down
    }
    else if(pacman.cur_dir == RIGHT && !map_array[pacman.PosY / 16][(pacman.PosX+16) / 16]) //If pacman can and is going right
        pacman.PosX += 2;   //Go right
    else if(pacman.cur_dir == LEFT && !map_array[pacman.PosY / 16][(pacman.PosX-1) / 16])   //If pacman can and is going left
        pacman.PosX -= 2;   //Go left
    else if(pacman.cur_dir == UP && !map_array[(pacman.PosY-1) / 16][pacman.PosX / 16]) //If pacman can and is going up
        pacman.PosY -= 2;   //Go up
    else if(pacman.cur_dir == DOWN && !map_array[(pacman.PosY+16) / 16][pacman.PosX / 16])  //If pacman can and is going down
        pacman.PosY += 2;   //Go down

    if(pacman.PosX == -14)  //If pacman goes to far left
        pacman.PosX = WIDTH-2;  //Pacman comes from right
    else if(pacman.PosX == WIDTH)   //If pacman goes to far right
        pacman.PosX = -14;  //Pacman comes from left

    pacman.cur_tile[0] = pacman.PosX / 16;  //Finds pacman's current horizontal tile coordinate
    pacman.cur_tile[1] = pacman.PosY / 16;  //Finds pacman's current vertical tile coordinate

    return;
}

void enemy::GhostMove(enemy &some_enemy, int map_array[41][29]) //Controls ghost movement
{
    if(some_enemy.ghost_state == BASE || some_enemy.ghost_state == BLUEBASE)    //If the ghost is in the base
    {
        some_enemy.next_dir = some_enemy.cur_dir;   //By default, ghost goes same direction

        if(some_enemy.PosY == 192)  //If the ghost goes up enough
        {
            some_enemy.next_dir = LEFT; //Ghost now moves left
            ChangeState(some_enemy.PosX, CHASE, some_enemy);    //Ghost leaves base
        }
        else if(map_array[(some_enemy.PosY-1) / 16][some_enemy.PosX / 16] && some_enemy.cur_dir == UP && some_enemy.cur_tile[0]!=13)    //If ghost is not in the middle of base and can't go up, go down
        {
            some_enemy.next_dir = DOWN;
        }
        else if(map_array[(some_enemy.PosY+16) / 16][some_enemy.PosX / 16] && some_enemy.cur_dir == DOWN)   //If ghost can't go down, go up
        {
            some_enemy.next_dir = UP;
        }
    }
    else if(some_enemy.ghost_state == LEAVEBASE)    //If ghost is ready to leave the base
    {
        if(some_enemy.PosY < 240 && some_enemy.PosX!=216)   //Go to vertical middle of base
            some_enemy.next_dir = DOWN;
        else if(some_enemy.PosY > 240 && some_enemy.PosX!=216)  //Go to vertical middle of base
            some_enemy.next_dir = UP;
        else if(some_enemy.PosX < 216)  //Go to horizontal middle of base
            some_enemy.next_dir = RIGHT;
        else if(some_enemy.PosX > 216)  //Go to horizontal middle of base
            some_enemy.next_dir = LEFT;
        else if(some_enemy.PosY > 192)  //Go upwards out of base
            some_enemy.next_dir = UP;
        else
        {
            some_enemy.ghost_state = CHASE; //Ghost leaves base
            some_enemy.next_dir = LEFT; //Ghost goes left
        }
    }
    else    //If the ghost is neither in the base nor leaving the base
    {
        if(some_enemy.ghost_state==RETURN && some_enemy.cur_tile[0]==14 && some_enemy.cur_tile[1]==14)  //If the ghost is returning to the base and has arrived
        {
            some_enemy.next_dir = UP;   //Ghost goes up
            ChangeState(some_enemy.PosX, LEAVEBASE, some_enemy);    //Ghost leaves base
        }
        else if(some_enemy.PosX%16==0 && some_enemy.PosY%16==0) //If the ghost is not returning and arriving to base
        {
            float distance = 1000;  //Sets distance to impossibly large number, to be overwritten

            if(sqrt(pow(some_enemy.target_tile[0]-some_enemy.cur_tile[0],2)+pow(some_enemy.target_tile[1]-(some_enemy.cur_tile[1]-1),2)) < distance && (!map_array[(some_enemy.PosY-1) / 16][some_enemy.PosX / 16] || (some_enemy.cur_tile[0]==14 && some_enemy.cur_tile[1]==16)) && some_enemy.cur_dir != DOWN)    //If the distance from 1 tile up is smaller than previous distance, and that tile is open or the ghost is in the base, and ghost is not moving down
            {
                distance = sqrt(pow(some_enemy.target_tile[0]-some_enemy.cur_tile[0],2)+pow(some_enemy.target_tile[1]-(some_enemy.cur_tile[1]-1),2));   //Sets new distance
                some_enemy.next_dir = UP;   //Go up
            }
            if(sqrt(pow(some_enemy.target_tile[0]-some_enemy.cur_tile[0],2)+pow(some_enemy.target_tile[1]-(some_enemy.cur_tile[1]+1),2)) < distance && (!map_array[(some_enemy.PosY+16) / 16][some_enemy.PosX / 16] || (some_enemy.ghost_state==RETURN && some_enemy.cur_tile[0]==14 && some_enemy.cur_tile[1]==12)) && some_enemy.cur_dir != UP)   //If the distance from 1 tile down is smaller than previous distance, and that tile is open or the ghost is returning to base, and ghost is not moving up
            {
                distance = sqrt(pow(some_enemy.target_tile[0]-some_enemy.cur_tile[0],2)+pow(some_enemy.target_tile[1]-(some_enemy.cur_tile[1]+1),2));   //Sets new distance
                some_enemy.next_dir = DOWN; //Go down
            }
            if(sqrt(pow(some_enemy.target_tile[0]-(some_enemy.cur_tile[0]-1),2)+pow(some_enemy.target_tile[1]-some_enemy.cur_tile[1],2)) < distance && !map_array[some_enemy.PosY / 16][(some_enemy.PosX-1) / 16] && some_enemy.cur_dir != RIGHT)   //If the distance from 1 tile left is smaller than previous distance, and that tile is open, and ghost is not moving right
            {
                distance = sqrt(pow(some_enemy.target_tile[0]-(some_enemy.cur_tile[0]-1),2)+pow(some_enemy.target_tile[1]-some_enemy.cur_tile[1],2));   //Sets new distance
                some_enemy.next_dir = LEFT; //Go left
            }
            if(sqrt(pow(some_enemy.target_tile[0]-(some_enemy.cur_tile[0]+1),2)+pow(some_enemy.target_tile[1]-some_enemy.cur_tile[1],2)) < distance && !map_array[some_enemy.PosY / 16][(some_enemy.PosX+16) / 16] && some_enemy.cur_dir != LEFT)   //If the distance from 1 tile right is smaller than previous distance, and that tile is open, and ghost is not moving left
            {
                distance = sqrt(pow(some_enemy.target_tile[0]-(some_enemy.cur_tile[0]+1),2)+pow(some_enemy.target_tile[1]-some_enemy.cur_tile[1],2));   //Sets new distance
                some_enemy.next_dir = RIGHT;    //Go right
            }
        }
    }

    some_enemy.cur_dir = some_enemy.next_dir;   //Determine what direction ghost will go

    if(some_enemy.ghost_state == BLUE || some_enemy.ghost_state == RETURN)
    {
        if(some_enemy.cur_dir == RIGHT) //If going right
            some_enemy.PosX += 1;
        else if(some_enemy.cur_dir == LEFT) //If goign left
            some_enemy.PosX -= 1;
        else if(some_enemy.cur_dir == UP)   //If going up
            some_enemy.PosY -= 1;
        else if(some_enemy.cur_dir == DOWN) //If going down
            some_enemy.PosY += 1;
    }
    else
    {
        if(some_enemy.cur_dir == RIGHT) //If going right
            some_enemy.PosX += 2;
        else if(some_enemy.cur_dir == LEFT) //If goign left
            some_enemy.PosX -= 2;
        else if(some_enemy.cur_dir == UP)   //If going up
            some_enemy.PosY -= 2;
        else if(some_enemy.cur_dir == DOWN) //If going down
            some_enemy.PosY += 2;
    }

    if(some_enemy.PosX == -14)  //If ghost is too far left
        some_enemy.PosX = WIDTH-2;  //Ghost comes from right
    else if(some_enemy.PosX == WIDTH)   //If ghost is too far right
        some_enemy.PosX = -14;  //Ghost comes from left

    some_enemy.cur_tile[0] = some_enemy.PosX / 16;  //Set ghost's horizontal tile cooridnate
    some_enemy.cur_tile[1] = some_enemy.PosY / 16;  //Set ghost's vertical tile cooridnate

    return;
}

void enemy::find_target_tile(enemy &some_enemy, enemy &blinky, player &pacman, enemy* enemy_array[4])   //Determines where ghost wants to go to
{
    if(some_enemy.ghost_state == BASE || some_enemy.ghost_state == BLUEBASE)    //If the ghost is in the base
    {
        some_enemy.target_tile[0] = 14; //Uses preset destination horizontally centered
        some_enemy.target_tile[1] = 0;  //Uses preset destination above map
    }
    else if(some_enemy.ghost_state == RETREAT)  //If the ghost is retreating
    {
        if(&some_enemy == enemy_array[0])  //If enemy is inky
        {
            some_enemy.target_tile[0] = 27; //Inky goes to bottom right
            some_enemy.target_tile[1] = 40;
        }
        else if(&some_enemy == enemy_array[1]) //If enemy is pinky
        {
            some_enemy.target_tile[0] = 2;  //Pinky goes to top left
            some_enemy.target_tile[1] = 0;
        }
        else if(&some_enemy == enemy_array[2]) //If enemy is clyde
        {
            some_enemy.target_tile[0] = 0;  //Clyde goes to bottom left
            some_enemy.target_tile[1] = 40;
        }
        else if(&some_enemy == enemy_array[3]) //If enemy is blinky
        {
            some_enemy.target_tile[0] = 38; //Blinky goes to top right
            some_enemy.target_tile[1] = 0;
        }
    }
    else if(some_enemy.ghost_state == CHASE)    //If the ghost is chasing pacman
    {
        if(&some_enemy == enemy_array[0])  //If enemy is inky, find target tile using pacman's and blinky's current tile
        {
            if(pacman.cur_dir == UP)    //If pacman is facing upwards
            {
                some_enemy.target_tile[0] = 2*pacman.cur_tile[0]-blinky.cur_tile[0];
                some_enemy.target_tile[1] = 2*(pacman.cur_tile[1]-2)-blinky.cur_tile[1];
            }
            else if(pacman.cur_dir == DOWN) //If pacman is facing downwards
            {
                some_enemy.target_tile[0] = 2*pacman.cur_tile[0]-blinky.cur_tile[0];
                some_enemy.target_tile[1] = 2*(pacman.cur_tile[1]+2)-blinky.cur_tile[1];
            }
            else if(pacman.cur_dir == LEFT) //If pacman is facing left
            {
                some_enemy.target_tile[0] = 2*(pacman.cur_tile[0]-2)-blinky.cur_tile[0];
                some_enemy.target_tile[1] = 2*pacman.cur_tile[1]-blinky.cur_tile[1];
            }
            else if(pacman.cur_dir == RIGHT)    //If pacman is facing right
            {
                some_enemy.target_tile[0] = 2*(pacman.cur_tile[0]+2)-blinky.cur_tile[0];
                some_enemy.target_tile[1] = 2*pacman.cur_tile[1]-blinky.cur_tile[1];
            }
        }
        else if(&some_enemy == enemy_array[1]) //If enemy is pinky, set target tile to 4 tiles ahead of pacman
        {
            if(pacman.cur_dir == UP)    //If pacman is facing upwards
            {
                some_enemy.target_tile[0] = pacman.cur_tile[0];
                some_enemy.target_tile[1] = pacman.cur_tile[1]-4;
            }
            else if(pacman.cur_dir == DOWN) //If pacman is facing downwards
            {
                some_enemy.target_tile[0] = pacman.cur_tile[0];
                some_enemy.target_tile[1] = pacman.cur_tile[1]+4;
            }
            else if(pacman.cur_dir == LEFT) //If pacman is facing left
            {
                some_enemy.target_tile[0] = pacman.cur_tile[0]-4;
                some_enemy.target_tile[1] = pacman.cur_tile[1];
            }
            else if(pacman.cur_dir == RIGHT)    //If pacman is facing right
            {
                some_enemy.target_tile[0] = pacman.cur_tile[0]+4;
                some_enemy.target_tile[1] = pacman.cur_tile[1];
            }
        }
        else if(&some_enemy == enemy_array[2]) //If enemy is clyde
        {
            if(sqrt(pow(some_enemy.PosX-pacman.PosX,2)+pow(some_enemy.PosY-pacman.PosY,2)) > 128)   //If pacman is far away, set target tile to pacman's current tile
            {
                some_enemy.target_tile[0] = pacman.cur_tile[0];
                some_enemy.target_tile[1] = pacman.cur_tile[1];
            }
            else    //If pacman is too close, set target tile to a tile in the upper right
            {
                some_enemy.target_tile[0] = 38;
                some_enemy.target_tile[1] = 0;
            }
        }
        else if(&some_enemy == enemy_array[3]) //If enemy is blinky, set target tile to pacman's current tile
        {
            some_enemy.target_tile[0] = pacman.cur_tile[0];
            some_enemy.target_tile[1] = pacman.cur_tile[1];
        }
    }
    else if(some_enemy.ghost_state == BLUE) //If the ghost is frightened
    {
        some_enemy.target_tile[0] = rand()%28;  //Set random target tile
        some_enemy.target_tile[1] = rand()%40;  //Set random target tile
    }
    else if(some_enemy.ghost_state == RETURN)   //If the ghost is returning to base
    {
        some_enemy.target_tile[0] = 14; //Tile in the base
        some_enemy.target_tile[1] = 15; //Tile in the base
    }
}
