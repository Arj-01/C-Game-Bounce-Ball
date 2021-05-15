


// GAME RULES -->;

// rule 1 = with every bounce on cart , u will get plus 10 score;
// rule 2 = if ball hits ground -5;
// rule 3 = if your cart hits one of the wall then score -2 of current value;
// rule 4  = "Game over" if your total sum of score is less than or equal to zero;

// control --> use 'a' to move your cart leftward;
//             use 'b' to move your cart rightward;
            // press 'x' twice to exit the game;



#include<iostream>
#include<conio.h>
#include<stdlib.h>





using namespace std;


bool gameover;


class cgame{
 protected:

 int x,y,carx,cary,width,height,score,px,py;

 // trajectory followed by the objects;

 enum gdirectory {down,upleft,upright,up,left,right};
      gdirectory dir;

enum adirec {STOP, LEFT,RIGHT};

    adirec dir1;



public:

   cgame()
   {

   score=0;

   width =20;
   height = 25;

   x=width/2;

   y=1;

  carx = width/2;

  cary = height-1;

  gameover = false;


   }

    ////  below draw() function will create the environment of the game; Ex-> walls, objects etc ;

   void draw()
   {
        system("cls");


    for (int i = 0; i < width; i++)
        {cout << "#";}

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

             if(j == width-2)
                cout << "#";



             else if (j==carx && i==cary)
             {
                 cout<<"-";
             }
             else if (j==carx-1 && i==cary)
             {
                 cout<<"-";
             }
             else if (j==carx+1 && i==cary)
             {
                 cout<<"-";
             }

             else if (j==x && i==y)
             {

                 cout<<"0";

                 px = j;
                 py = i;
             }


            else {

                cout<<" ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
       {
           cout << "#";
       }

    cout << endl;



    cout<< " press 'x' twice to exit the game "<<endl;
    cout<< " your score should be always greater than zero: "<<endl;


}

 // here is the logic behind the game;

void logic()
{

                            // initially- down trajectory of the ball;
   if (px==x && py ==y)
  {

   dir = down;

  }

  if (x==carx && y==cary-1)
  {
      score+=10;

                               // random directory of ball after hitting the the cart;

     dir = (gdirectory)((rand()%3)+1);

      cout<<score;
  }
  else if(x==carx-1 && y==cary-1)
  {
        score+=10;

     dir = (gdirectory)((rand()%3)+1);
      cout<<score;
  }

  else if(x==carx+1 && y==cary-1)
  {
      score+=10;
                            //// random directory of ball after hitting the the cart;

     dir = (gdirectory)((rand()%3)+1);
      cout<<score;
  }

                       //// if ball hits right wall


  else if( x==width-2 )

  {

    dir = upleft;

  }

                      //// if ball hits left ball wall

  else if (x==0)
  {
      dir = upright;
  }

                        //////////////// if ball hits the ceiling;

  else if (y==0)
  {
      dir = down;
  }

                        /////////// if ball hits the ground;

  else if ( y == height)
  {
      score-=5;

      dir = (gdirectory)((rand()%3)+1);


  }

                      // right corner of the cart hits the right wall;
  else if (carx+1==width-2)
  {
      score -=2;
      dir1 = LEFT;
  }

                     // left corner of the cart hits the left wall;
  else if (carx-1==0 )
  {
      score -=2;

      dir1 = RIGHT;
  }

  else {cout<<" score: "<<score<<endl;}

                   // if score<0 game over;
  if (score<0)
  {
      gameover = true;

  }

}

                 // input given by keyboard for cart to move

void input()
{
   if(_kbhit())
{


    switch(_getch()){
case 'a':
    dir1=LEFT;
    break;
case 'd':
    dir1=RIGHT;
    break;


    case 'x':
    gameover=true;
    }

}

}

       // below are the trajectories given by specially adjusted directories;

void setup()
{

       switch (dir)
    {


    case upleft:
        x--;
        y--;

        break;
    case upright:
       x++;
       y--;
       break;
    case up:
       y--;
       break;
    case down :
        y++;
        break;

    default:
        break;
    }


switch (dir1)
{
    case LEFT:
        carx--;
        break;
       case RIGHT:
        carx++;
        break;

       case STOP:
        break;

       default :

        break;

}
}

};

int main()
{
    cgame player1;

  while(!gameover)
  {

     player1.draw();
     player1.setup();
     player1.logic();
     player1.input();


  }

  cout<<"*********************** GAME OVER !! ************************";


}

