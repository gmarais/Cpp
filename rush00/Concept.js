A_Printable:
|___A_Shape:
|	|___A_Physical:
|	|	|___A_Movable
|	|	|	|___A_Ship:
|	|	|	|	|___A_Player:
|	|	|	|	|	|___Type1: -concrete;
|	|	|	|	|	|___Type2: -concrete;
|	|	|	|	|___A_Enemy:
|	|	|	|		|___Type1: -concrete;
|	|	|	|		|___Type2: -concrete;
|	|	|	|___A_Projectile:
|	|	|		|___Type1: -concrete;
|	|	|		|___Type2: -concrete;
|	|	|___A_Obstacle:
|	|		|___Ground: -concrete;
|	|		|___YourMom: -concrete;
|	|___A_NON_Physical:
|		|___Flames: -concrete;
|		|___Clouds: -concrete;
|		|___Sky: -concrete;
|
ScreenDisplay: -concrete;
{
	GameStart();
	GameOver();
	GamePause();
	GameRun();
}

A_Squad:
|___EnemySquad: -concrete;
|___PlayerSquad: -concrete;
