class player {
        public:
            int PosX;
            int PosY;
            int cur_dir;
            int next_dir;
            int cur_tile[2];

            static void PacmanMove(player &pacman, int map_array[41][29]);
};

class enemy {
    public:
        int ghost_state;
        int PosX;
        int PosY;
        int LastPosX;
        int LastPosY;
        int cur_dir;
        int next_dir;
        int cur_tile[2];
        int target_tile[2];
        int offsets[4];
        int ghost_timer;

        static void find_target_tile(enemy &some_enemy, enemy &blinky, player &pacman, enemy* enemy_array[4]);
        static void GhostMove(enemy &some_enemy, int map_array[41][29]);
};

class mouse {
    public:
        int PosX;
        int PosY;
        bool button1;
        bool button2;
};
