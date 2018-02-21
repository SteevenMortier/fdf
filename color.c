#include "fdf.h"

int		color(int alt)
{
	if (alt > 0)
	{
		if (alt <= 3)
			return (0x1caa1c);
		else if (alt <= 6)
			return (0xdcd700);
		else if (alt <= 9)
			return (0xc89121);
		else if (alt <= 12)
			return(0xa6741e);
		else if (alt <= 15)
			return (0x969f9e);
		else if (alt <= 18)
			return (0xc9e7df);
		else
			return (0xFFFFFF);
	}
	if (alt < 0)
		return (0x0000FF);
	return (0x00FF00);
}

/*
	vert clair (#45d33a)
	jaune (0xdcd700)
	brun clair (0xc89121)
	marron foncé (0xa6741e)
	gris (0x969f9e)
	bleu pâle (0xc9e7df)
	blanc (0xffffff)
 */