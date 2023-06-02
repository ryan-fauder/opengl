// https://letsboard.co/boards/DztRezkjpYsbDECcGWfoKy2RAPPMAivfDY4G
// https://github.com/hanrell/bresenham-rasterization
function octantLineDraw0(p1, p2)
  x1 = p1(1);
  y1 = p1(2);
  x2 = p2(1);
  y2 = p2(2);

  dx = x2 - x1;
  dy = y2 - y1;
  
  abs_dy_less_than_abs_dx = false;
  dx_negative = false;
  dy_negative = false;
  
  if abs(dy) <= abs(dx)            
    abs_dy_less_than_abs_dx = true;
  endif
  
  if dx < 0
    dx_negative = true;
    dx = -dx;
  endif
  
  if dy < 0
    dy_negative = true;
    dy = -dy;
  endif
  
  if !abs_dy_less_than_abs_dx
    tmp = dy;
    dy = dx;
    dx = tmp;    
  endif

  
  a = dy / dx;
    
  plotPixel(x1, y1);  
 
  fraction = 0.5 + a;
  disp(fraction);  
   
  while (dx_negative && (x1 > x2) || !dx_negative && (x1 < x2) || dy_negative && (y1 > y2) || !dy_negative && (y1 < y2))        
    
    if !(fraction < 1)
      if abs_dy_less_than_abs_dx            
        if dy_negative
          y1 = y1 - 1;
        else
          y1 = y1 + 1;
        endif      
      else      
        if dx_negative
          x1 = x1 - 1;
        else
          x1 = x1 + 1;
        endif         
      endif
    endif

    if abs_dy_less_than_abs_dx      
      if dx_negative
        #octant 3 and 4        
        x1 = x1 - 1;
      else
        # octant 0 and 7        
        x1 = x1 + 1;          
      endif 
    else 
      if dy_negative
        # octant 1 and 2        
        y1 = y1 - 1;
      else
        # octant 5 and 6        
        y1 = y1 + 1;
      endif
    endif
    
    if fraction < 1
      fraction = fraction + a;
    else        
      fraction = fraction + a - 1;
    endif
    plotPixel(x1, y1);    
  endwhile              
endfunction





      
x1 = 100;
y1 = 100;
x_offset = 0;
y_offset = 0;
dx = 10;
dy = 5;

# octant 7
p1 = [x1+x_offset,y1+y_offset];
p2 = [p1(1)+dx, p1(2)+dy];

h1 = plotPixelGrid();
#lineDraw0(p1, p2);
octantLineDraw0(p1, p2);
plotLine(p1, p2);

# octant 0
p3 = [x1+x_offset,y1-y_offset];
p4 = [p3(1)+dx, p3(2)-dy];
#octantLineDraw0(p3, p4);
plotLine(p3, p4);

# octant 4
p5 = [x1-x_offset,y1+y_offset];;
p6 = [p5(1)-dx, p5(2)+dy];
#octantLineDraw0(p5, p6);
plotLine(p5, p6);

# octant 3
p7 = [x1-x_offset,y1-y_offset];;
p8 = [p7(1)-dx, p7(2)-dy];
#octantLineDraw0(p7, p8);
plotLine(p7, p8);

# octant 6
p9 = [x1+x_offset,y1+y_offset];;
p10 = [p9(1)+dy, p9(2)+dx];
#octantLineDraw0(p9, p10);
plotLine(p9, p10);

# octant 1
p11 = [x1+x_offset,y1-y_offset];;
p12 = [p11(1)+dy, p11(2)-dx];
#octantLineDraw0(p11, p12);
plotLine(p11, p12);

# octant 2
p13 = [x1-x_offset,y1-y_offset];;
p14 = [p13(1)-dy, p13(2)-dx];
#octantLineDraw0(p13, p14);
plotLine(p13, p14);

# octant 5
p15 = [x1-x_offset,y1+y_offset];;
p16 = [p15(1)-dy, p15(2)+dx];
#octantLineDraw0(p15, p16);
plotLine(p15, p16);
