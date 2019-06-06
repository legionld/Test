/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:57:42 by jschille          #+#    #+#             */
/*   Updated: 2019/06/06 20:59:01 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 1920
#define HIGHT 1080
#define unint unsigned int

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

static int		mabs(int n)
{
	if (n == -2147483648)
		return (2147483647);
	if (n < 0)
		return (n * -1);
	return (n);
}

void setPixel(unint *data, int x, int y)
{
	data[x * WIDTH + y] = 0xFFFFFFF;
}

void drawLine(unint *data, t_point a, t_point b) {
    const int deltaX = mabs(b.x - a.x);
    const int deltaY = mabs(b.y - a.y);
    const int signX = a.x < b.x ? 1 : -1;
    const int signY = a.y < b.y ? 1 : -1;
    int error = deltaX - deltaY;

    setPixel(data, b.x, b.y);
    while(a.x != b.x || a.y != b.y) 
   {
        setPixel(data, a.x, a.y);
        const int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            a.x += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            a.y += signY;
        }
    }

}