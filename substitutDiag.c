	while (start_x != end_x)
	{
		tool.img_data[(start_x) + (start_y*y)] = tool.color;
		start_x++;
		if (start_y < end_y)
			y--;
		else
			y++;
	}
	