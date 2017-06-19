# Platformer

After following a tutorial to program my first game in C++, I decided to
practice by recreating parts of the game MapleStory. I built the graphics and
physics engines from scratch. I also began to implement logic for quests and
skills. Eventually, my lack of experience caught up with me, and the code became
too unmanageable to continue.

I'll leave you with one line from the physics engine:

```
if(!((*MapList[CurMap]).Platforms[CurPlatform][0] < Player.PosX &&
     (*MapList[CurMap]).Platforms[CurPlatform][2] > Player.PosX) &&
   CurPlatform < ((*MapList[CurMap]).NumPlat-1) &&
   (*MapList[CurMap]).Platforms[CurPlatform][2] == (*MapList[CurMap]).Platforms[CurPlatform+1][0] &&
   (*MapList[CurMap]).Platforms[CurPlatform][3] == (*MapList[CurMap]).Platforms[CurPlatform+1][1])
```

In case you're wondering, that if statement determines if the player has stepped
on a new platform.
