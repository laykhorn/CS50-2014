//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {    //double velocity =  3.0;
            // TODO
           // initial velocity
            
            // bounce forever
           /*  while (true)
            {
                
                // move circle along (x, y) axis.   */
                double velocity = 3.0;
                move(ball, 2.0, velocity); 
                
                
        // follow mouse forever
        while (true)
        {
            // check for mouse event
            GEvent event = getNextEvent(MOUSE_EVENT);

            // if we heard one
            if (event != NULL)
            {
                // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                {   double y = 520;
                    // ensure circle follows top cursor
                    double x = getX(event) - getWidth(paddle) / 2;
                    //double y = getY(event) - getWidth(paddle);
                    setLocation(paddle, x, y);
                }
            }
        }   

                // bounce off right edge of window
                if (getX(ball) + getWidth(ball) >= getWidth(window))
                {
                    velocity = -velocity;
                }

                // bounce off left edge of window
                else if (getX(ball) <= 0)
                {
                    velocity = -velocity;
                }   

                // linger before moving again
                pause(10);
                return 0;
            } 
        
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

   /*     // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
                double x = getX(event) - getWidth(paddle) / 2;
                double y = 15;
                setLocation(paddle, x, y);
            }
        }
     
    //}
  
    // wait for click before exiting    
    waitForClick();         */

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{   int y = 20;
    // TODO
    for (int r = 0; r < ROWS; r++)
    {  int x = 20; 
        for (int c = 0; c < COLS; c++)
            { 
            GRect bricks = newGRect(x, y, 30, 12);
            setFilled(bricks, true);
                if ( r == 0)
                { setColor(bricks, "BLACK"); }
                else if (r == 1)
                { setColor(bricks, "BLUE"); }
                else if ( r == 2)
                { setColor(bricks, "GREEN"); }
                else if ( r ==3)
                { setColor(bricks, "YELLOW"); }
                else 
                setColor(bricks, "RED");
                add(window, bricks);
            x = x + 37;         
             }      
     y = y + 18;   
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH/2, HEIGHT/2, 25, 25);
    setFilled(ball, true);
    setColor(ball, "RED");
    add(window, ball);
    return ball;
 }

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
        {
            // TODO
            GRect paddle = newGRect(WIDTH/2, 520, 60, 15);
            setFilled(paddle, true);
            setColor(paddle, "BLACK");
            add(window, paddle);
            return paddle;
         }

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
