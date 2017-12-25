#ifndef LAB_H
# define LAB_H

# include "ipi.h"
# include "hmap.h"
# include "bitmap.h"
# include "breadth_search.h"

# define LAB_CHAR_EMPTY	('.')
# define LAB_CHAR_WALL	('X')

/** represente un téléporteur, avec ces 2 points */
typedef struct	s_teleporter {
	INDEX x1, y1;
	INDEX x2, y2;
}		t_teleporter;

/** represente une clef et une porte */
typedef struct	s_door {
	INDEX xkey, ykey;
	INDEX xdoor, ydoor;
}		t_door;

/** represente le labyrinthe */
typedef struct	s_lab {
	INDEX	l;	/* largeur == longueur du labyrinthe */
	char	* map;	/* les cases du labyrinthe */
	t_hmap	* teleporters;
	t_hmap	* doors;
}		t_lab;

/**
 *	NB : ce constructeur est relativement long, car on s'assure
 *		qu'il n'y ait pas de fuite mémoire en cas d'erreur
 *
 *	@require :	n : longueur (== largeur) du labyrinthe
 *	@ensure	 :	crée un nouveau labyrinthe de taille 'n'
 *	@assign  :	-------
 */
t_lab * lab_new(INDEX n);

/**
 *	@require :	lab : un labyrinthe alloué via 'lab_new()'
 *	@ensure	 :	supprime le labyrinthe du tas
 *	@assign  :	-------
 */
void lab_delete(t_lab * lab);

/**
 *	@require :	lab : un labyrinthe alloué via 'lab_new()'
 *	@ensure	 :	lit un labyrinthe sur l'entrée standart
 *	@assign  :	-------
 */
t_lab * lab_parse(FILE * stream);

void lab_solve(t_lab * lab, unsigned int timer);

#endif