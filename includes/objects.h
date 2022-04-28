
#ifndef	OBJECTS_H
# define OBJECTS_H

#include	"point_vector.h"

typedef struct s_color
{
	int	r;	//[0 - 255]
	int	g;
	int	b;
}t_color;

typedef struct s_camera
{
	t_point	pos;	//Position
	t_vect	n_vec;	//Normalized Orientation Vector [-1.0 - 1.0]
	int	FOV; //Field Of View [0 - 180] Sin decimales
}t_camera;

typedef struct s_amb_light
{
	double	rate;	//[0.0 - 1.0]

	t_color	rgb;

}t_amb_light;


typedef struct s_light
{
	t_point	pos;	//Position

	double	glow;	//[0.0 - 1.0]

	t_color	rgb;	//[0 - 255]
}t_light;

typedef struct s_sphere
{
	t_point		pos;	//Centro de la esfera

	double		diameter;

	t_color	rgb;	//[0 - 255]
	struct s_sphere	*next;
}t_sphere;

typedef struct s_plane
{
	t_point	pos;	//Position
	
	t_vect	n_vec;	//Normalized Orientation Vector 
			//[-1.0 - 1.0]

	t_color	rgb;	//[0 - 255]
	struct s_plane	*next;
}t_plane;

typedef struct s_cylinder
{
	t_point	pos;	//Position

	t_vect	n_vec;	//Normalized Orientation Vector 
			//[-1.0 - 1.0]

	double	diameter;
	double	height;

	t_color	rgb;	//[0 - 255]
	struct s_cylinder	*next;
}t_cylinder;

typedef struct s_objects
{
	t_camera	cam;		//Solo puede haber una
	t_amb_light	a_light;	//Solo puede haber una
	t_light		light;		//Solo puede haber una
	t_sphere	*sphs;
	t_plane		*plns;
	t_cylinder	*cyls;
}t_objects;

t_camera	create_camera(char *s, t_objects *all);
t_amb_light	create_amblight(char *s, t_objects *all);
t_light	create_light(char *s, t_objects *all);
void	create_planes(char *s, t_objects *all);
void	create_spheres(char *s, t_objects *all);
void	create_cylinders(char *s, t_objects *all);


#endif
