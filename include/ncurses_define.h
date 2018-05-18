/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** ncurses_define
*/

#ifndef NCURSES_DEFINE_H_
	#define NCURSES_DEFINE_H_

// move the cursor
#define	cursorbackward(x)	printf("\033[%dD", (x))
#define	cursorforward(x)	printf("\033[%dC", (x))

// define for the keys
#define	LEFT_KEY	68
#define RIGHT_KEY	67
#define	DOWN_KEY	66
#define	UP_KEY		65
#define	ARROW		27

#define	ENTER_KEY	13
#define	TAB		9

// define catch ctr+
#define	CTR_L		12
#define	CTR_R		18
#define	CTR_Y		25
#define	CTR_U		21
#define	CTR_K		11

#endif /* !NCURSES_DEFINE_H_ */
