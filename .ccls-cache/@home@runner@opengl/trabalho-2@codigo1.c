void interpolar(Pixel *inicial, Steps dist){
    inicial->red += dist.redStep;
    inicial->green += dist.greenStep;
    inicial->blue += dist.blueStep;
    inicial->alpha += dist.alphaStep;
}

void drawLine(Pixel inicial, Pixel final){
    int xi = inicial.x;
    int xf = final.x;
    int yi = inicial.y;
    int yf = final.y;
    int dx = abs(xf - xi);
    int dy = abs(yf - yi);
    int controle = 0;   //Controla se a direção menor vai crescer ou nao;
    int incX = 0;
    int incY = 0;

    //Define se Y e X estão indo nas direções positivas ou negativas
    if(xf > xi) incX = 1;
    else incX = -1;

    if(yf > yi) incY = 1;
    else incY = -1;

    Steps steps;
    setarDist(inicial,final,&steps);
    putPixel(inicial);
    Pixel linha = {inicial.x, inicial.y, inicial.red, inicial.green, inicial.blue, inicial.alpha};  
    if(dx == 0){
        if(yf > yi){    //linha pra baixo
            while(linha.y != yf)
            {

                linha.y++;
                interpolar(&linha,steps);
                putPixel(linha);

            }
        }
        else{           //linha pra cima
            while(linha.y != yf)
            {

                linha.y--;
                interpolar(&linha,steps);
                putPixel(linha);

            }
        }

    }
    else if(dy == 0){
        if(xf > xi){    //linha pra direita
            while(linha.x != xf)
            {

                linha.x++;
                interpolar(&linha,steps);
                putPixel(linha);

            }
        }
        else{           //linha pra esquerda
            while(linha.x != xf)
            {

                linha.x--;
                interpolar(&linha,steps);
                putPixel(linha);

            }
        }
    }
    else {
        if (dx >= dy) {

            controle = dx / 2;
            putPixel(inicial);
            while (linha.x != xf) {
                linha.x += incX;
                controle = controle - dy;
                if (controle < 0) {
                    linha.y += incY;
                    controle += dx;
                }
                interpolar(&linha,steps);
                putPixel(linha);
            }

        } else {
            controle = dy / 2;
            putPixel(inicial);
            while (linha.y != yf) {
                linha.y += incY;
                controle = controle - dx;
                if (controle < 0) {
                    linha.x += incX;
                    controle += dy;
                }
                interpolar(&linha,steps);
                putPixel(linha);
            }

        }
    }


}
