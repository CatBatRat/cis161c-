#include <curses.h>

//Trying to get ncurses to work.
//Having a little trouble getting
//the linker to see that I have ncurses
//installed.

int main()
  {
  initscr();

  addstr( "Hello world!\n\n" );

  addstr( "\nPress a key to continue..." );
  cbreak();    /* turn off line-buffering */
  noecho();    /* turn off character echo */

  getch();     /* read and discard a single character (caveats!) */

  echo();      /* turn echo back on */
  nocbreak();  /* turn line-buffering back on */

  endwin();
  return 0;
  }
