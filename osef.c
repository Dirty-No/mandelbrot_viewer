		drawRectangle(buffers + i, (int []){new_xmin, new_ymin}, (int []){new_xmax, new_ymax});

void    drawRectangle(t_data *data, int top_left[2], int bot_right[2])
{
        int i;

        i = top_left[0];
        while (i <= bot_right[0])
        {
                my_mlx_pixel_put(data, i, top_left[1], 0x00FFFFFF);
                my_mlx_pixel_put(data, i, bot_right[1], 0x00FFFFFF);
                i++;
        }
        i = top_left[1];
        while (i >= bot_right[1])
        {
                my_mlx_pixel_put(data, top_left[0], i, 0x00FFFFFF);
                my_mlx_pixel_put(data, bot_right[0], i, 0x00FFFFFF);
                i--;
        }
}