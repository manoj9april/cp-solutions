if (in_set[events_h[j].ind] == 1) //Horizontal sweep line for active rectangle
{
    if (events_h[j].type == 0) //If it is a bottom edge of rectangle
    {
        if (cnt == 0)
            begin_y = rects[events_h[j].ind][0].y; // Block starts
        ++cnt;                                     //incrementing number of overlapping rectangles
    }
    else //If it is a top edge
    {
        --cnt;        //the rectangle is no more overlapping, so remove it
        if (cnt == 0) //Block ends
        {
            int delta_y = (rects[events_h[j].ind][13].y - begin_y); //length of the vertical sweep line cut by rectangles
            area += delta_x * delta_y;
        }
    }
}
