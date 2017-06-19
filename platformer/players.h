Players Player;
    {
    Player.PosX = (*MapList[CurMap]).StartX;
    Player.PosY = (*MapList[CurMap]).StartY;
    Player.VelX = 0;
    Player.VelY = -5;
    Player.AccX = 0;
    Player.AccY = -.3;

    Player.MaxVelX = 2;

    Player.LastPosX = 0;
    Player.LastPosY = 0;
    }
