#include "fractol_bonus.h"

double  calc(double pixel, double max, double min, t_data *data)
{
    return (scale(pixel, max, min, WIDTH) * data->zoom);
}