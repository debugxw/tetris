#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#define M 40		//x
#define N 21		//y        
int s[M][N],a[7], b[7], c[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int x5, y5, x6, y6, x7, y7, x8, y8, x9 = 0, x10 = 0, level = 1, n = 0, m = 0, d[4], k = 1;
int x1, y1, x2, y2, x3, y3, x4, y4, i, flag = 1, tag = 1, j;
void gotoxy(int x, int y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void putcharxy(int x, int y)
{
	gotoxy(x,y);
	printf("回");
	s[x][y] = 1;
} 

void putcharxy0(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
	s[x][y] = 0;
} 

//生成墙  
void wall()
{
	int x,y;
	for(x = 0; x < M+1; x++)
	for(y = 0; y < N+1; y++)
	{
	    s[x][y]=0;
		if((x == 0 || x== 22) && (y <= 20))
		{
			gotoxy(x, y);
			printf("回");
			s[x][y] == -1; 
		}
		if((y == 0 || y == N) && x <= 40)
		{
			gotoxy(x, y);
			printf("-"); 
			s[x][y] = -1;                              
		}
		if(y == 1 && x == 25)
		{
			gotoxy(x, y);
			printf("下一个:");
			s[x][y] = -1; 
		}
		if(y == 5 && x == 26)
		{
			gotoxy(x, y);
			printf("得分:"); 
		}
		if(y == 11 && x == 26)
		{
			gotoxy(x, y);
			printf("操作说明：");
			gotoxy(28, 14);
			printf("w:变化");
			gotoxy(28, 16);
			printf("a,d:左右移动");
			gotoxy(28, 18);
			printf("s:快速下移"); 
		}
	}
}

void draw()	   	   //画方块 
{
	if(s[x1][y1] != 1 && s[x2][y2] != 1 && s[x3][y3] != 1 && s[x4][y4] != 1) 
	putcharxy(x1, y1); putcharxy(x2, y2); putcharxy(x3, y3); putcharxy(x4, y4);	
}

void de()		//删方块 
{ 
	putcharxy0(x1, y1); putcharxy0(x2, y2); putcharxy0(x3, y3); putcharxy0(x4, y4);	
}

void del()		//删方块 
{ 
	putcharxy0(x5, y5); putcharxy0(x6, y6); putcharxy0(x7, y7); putcharxy0(x8, y8);	
}

void init0()		//0
{
	x1 = 8; y1 = 1; x2 = 10; y2 = 1; x3 = 12; y3 = 1; x4 =14; y4 = 1;
	draw();
}

void init1()		//1
{
	x1 = 10; y1 = 2; x2 = 12; y2 = 2; x3 = 10; y3 = 1; x4 =12; y4 = 1;
	draw();
}

void init2()		//2
{
	x1 = 10; y1 = 1; x2 = 12; y2 = 2; x3 = 14; y3 = 2; x4 =12; y4 = 1;
	draw();
}

void init3()		//3
{
	x1 = 10; y1 = 2; x2 = 12; y2 = 2; x3 = 14; y3 = 1; x4 =12; y4 = 1;
	draw();
}

void init4()		//4
{
	x1 = 10; y1 = 2; x2 = 12; y2 = 2; x3 = 14; y3 = 2; x4 =12; y4 = 1;
	draw();
}

void init5()		//5
{
	x1 = 10; y1 = 3; x2 = 12; y2 = 1; x3 = 10; y3 = 2; x4 =10; y4 = 1;
	draw();
}

void init6()		//6
{
	x1 = 10; y1 = 1; x2 = 12; y2 = 3; x3 = 12; y3 = 2; x4 =12; y4 = 1;
	draw();
}

int nexti()		//下一个方块 
{
	j = k;
	srand(time(NULL));
	k = rand()%7;
	switch(k)
	{
		case 0: del(); x5=x1 = 32; y5=y1 = 1; x6=x2 = 34; y6=y2 = 1; x7=x3 = 36; y7=y3 = 1; x8=x4 =38; y8=y4 = 1; draw(); break;
		case 1: del(); x5=x1 = 32; y5=y1 = 2; x6=x2 = 34; y6=y2 = 2; x7=x3 = 32; y7=y3 = 1; x8=x4 =34; y8=y4 = 1; draw(); break;
		case 2: del(); x5=x1 = 32; y5=y1 = 1; x6=x2 = 34; y6=y2 = 2; x7=x3 = 36; y7=y3 = 2; x8=x4 =34; y8=y4 = 1; draw(); break;
		case 3: del(); x5=x1 = 32; y5=y1 = 2; x6=x2 = 34; y6=y2 = 2; x7=x3 = 36; y7=y3 = 1; x8=x4 =34; y8=y4 = 1; draw(); break;
		case 4: del(); x5=x1 = 32; y5=y1 = 2; x6=x2 = 34; y6=y2 = 2; x7=x3 = 36; y7=y3 = 2; x8=x4 =34; y8=y4 = 1; draw(); break;
		case 5: del(); x5=x1 = 32; y5=y1 = 3; x6=x2 = 34; y6=y2 = 1; x7=x3 = 32; y7=y3 = 2; x8=x4 =32; y8=y4 = 1; draw(); break;
		case 6: del(); x5=x1 = 32; y5=y1 = 1; x6=x2 = 34; y6=y2 = 3; x7=x3 = 34; y7=y3 = 2; x8=x4 =34; y8=y4 = 1; draw(); break;
	}
	return j;
}

void init()    	   //随机生成方块 
{ 
	i = nexti();
	a[0]=100; a[1]=200; a[2]=a[3]=a[4]=0; a[5]=a[6]=1; b[0]=b[1]=b[2]=b[3]=b[4]=b[5]=b[6]=0;
	d[0]=d[1]=d[2]=d[3]=d[4]=0;
	gotoxy(32, 5);
	printf(" %d", n);
	gotoxy(26, 8);
	printf("等级:  %d", level); 
	switch(i)
	{
		case 0: init0(); break; case 1: init1(); break; case 2: init2(); break;
		case 3: init3(); break; case 4: init4(); break; case 5: init5(); break; 
		case 6: init6(); break;
	}
}  


void left()		//左移    
{   
	if(x1 != 2 && x2 != 2 && x3 != 2 && x4 != 2)
	{
		de();
		x1 -= 2; x2 -= 2; x3 -= 2; x4 -= 2;
		draw();	
	}
}

void right()		//右移 
{
	if(x1 != 20 && x2 != 20 && x3 != 20 && x4 != 20)
	{
		de();
		x1 += 2; x2 += 2; x3 += 2; x4 += 2;
		draw();	
	}
}

void change()		//变化 
{
	switch(i)
	{
		case 0: de();
				if(b[i] == 0) {x1 += 4; y1 += 2; x2 += 2; y2 += 1; x4 -= 2; y4 -= 1; b[i] = (b[i]+1) % 2;}
				else {x1 -= 4; y1 -= 2; x2 -= 2; y2 -= 1; x4 += 2; y4 += 1; b[i] = (b[i]+1) % 2;} 
				draw(); a[i]++; break;
		case 1: break;
		case 2: de();
				if(b[i] == 0) {x1 += 2; y1 += 2; x2 += 2; x3 -= 2; x4 += 2; b[i] = (b[i]+1) % 2;}
				else {x1 -= 2; y1 -= 2; x2 -= 2; x3 += 2; x4 -= 2; b[i] = (b[i]+1) % 2;}
				draw(); a[i]++; break; 
		case 3: de();
				if(b[i] == 0) {x1 += 4; y1 += 1; y3 += 1; b[i] = (b[i]+1) % 2;}
				else {x1 -= 4; y1 -= 1; y3 -= 1; b[i] = (b[i]+1) % 2;}
				draw(); a[i]++; break;
		case 4: de();
				if(b[i] == 0) {y2 += 1; x3 -= 2; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 1) {x3 += 2; y4 += 1; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 2) {x1 += 2; y1 += 1; x2 += 2; y2 -= 1; x3 -= 2; y4 -=1; b[i] = (b[i]+1) % 4;}
				else {x1 -= 2; y1 -= 1; x2 -= 2; x3 += 2; b[i] = (b[i]+1) % 4;}
				draw(); a[i]++; break;
		case 5: de();
				if(b[i] == 0) {y1 -= 1; y2 += 1; x3 += 4; y3 += 1; x4 += 4; y4 += 1; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 1) {y2 += 2; y1 += 2; x3 -= 2; x4 -= 2; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 2) {x3 += 2;y3 += 1; x4 -= 2; y4 += 1; b[i] = (b[i]+1) % 4;}
				else {y2 -= 2; x3 -= 4; y3 -= 1; y4 -= 1; b[i] = (b[i]+1) % 4;}
				draw(); a[i]++; break;
		case 6: de();
				if(b[i] == 0) {y1 += 1; x4 -= 2; y3 -= 1; x2 += 2; y2 -= 2; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 1) {y1 += 1; x3 -= 2; y3 += 1; x2 -= 2; y2 += 2; b[i] = (b[i]+1) % 4;}
				else if(b[i] == 2) {x3 += 4; y3 += 1; x4 += 4; y4 += 1; b[i] = (b[i]+1) % 4;}
				else {y1 -= 2; x3 -= 2; y3 -= 1; x4 -= 2; y4 -= 1; b[i] = (b[i]+1) % 4;}
				draw(); a[i]++; break;
	}
}

//判断是否可以下一移 
int comepare(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)		
{
	if(a[i] != 100 && a[i] != 101 && a[i] != 200) a[i] = a[i] % 2;
	else if(a[i] == 101 || a[i] == 100) a[i] = (a[i] - 100) % 2 + 100;
	else a[i] = 200;
	switch(a[i])
	{
		case 100: if(s[x1][y1+1] == -1 || s[x1][y1+1] == 1 || s[x2][y2+1] == -1 || s[x2][y2+1] == 1
				  || s[x3][y3+1] == -1 || s[x3][y3+1] == 1 || s[x4][y4+1] == -1 || s[x4][y4+1] == 1)
				    return 1; break;
		case 101: if(s[x1][y1+1] == -1 || s[x1][y1+1] == 1) return 1; break;
		case 200: if(s[x1][y1+1] == -1 || s[x1][y1+1] == 1 || s[x2][y2+1] == -1 || s[x2][y2+1] == 1)
					return 1; break;			
		case 0:   if(s[x1][y1+1] == -1 || s[x1][y1+1] == 1 || s[x2][y2+1] == -1 || s[x2][y2+1] == 1
				  || s[x3][y3+1] == -1 || s[x3][y3+1] == 1)
				    return 1; break;
		case 1:	  if(s[x1][y1+1] == -1 || s[x1][y1+1] == 1 || s[x2][y2+1] == -1 || s[x2][y2+1] == 1)
					return 1; break; 
	}
	return 0;
}

void clear()		//消除行
{
	int x, y, w = 1;
	if(m == 0) return;
	for(y = d[0]; y > w; y--)
	{
		while(c[y-w]%10 == 0 && c[y-w] != 0)
			w++;
		for(x = 2; x <= 20; x += 2)
		{
			if(s[x][y] == s[x][y-w] && s[x][y-w] == 0) ;
			else if(s[x][y] == s[x][y-w])
			{
				gotoxy(x, y-w); printf(" "); s[x][y-w] = 0;
			}
			else
			{
			s[x][y] = s[x][y-w];
			if(s[x][y] == 0) {gotoxy(x, y); printf(" ");}
 		    else{gotoxy(x, y); printf("回"); gotoxy(x, y-w); printf(" "); s[x][y-w] = 0;}
			}
		}
		c[y] = c[y-w];
		c[y-w] = 0;
	}
}

void shuzu()		//c[i]数组自加 + 判断是否得分 
{
	int v = 0;
	if(i == 0 && b[i] == 0) {c[y1] += 4; if(c[y1]%10 == 0) {m++;d[v++] = y1;} 
	}                                                                      
	else if(a[i] == 101 && b[i] == 1) {c[y1]++; c[y2]++; c[y3]++; c[y4]++;
	if(c[y1]%10 == 0) {m++;d[v++] = y1;} if(c[y2]%10 == 0) {m++;d[v++] = y2;}
	if(c[y3]%10 == 0) {m++;d[v++] = y3;} if(c[y4]%10 == 0) {m++;d[v++] = y4;} 
	}                                                                      
	else if(i >= 5 && b[i] == 2) {c[y2] += 2; c[y4]++; c[y3]++;
	if(c[y2]%10 == 0) {m++;d[v++] = y2;}
	if(c[y3]%10 == 0) {m++;d[v++] = y3;} if(c[y4]%10 == 0) {m++;d[v++] = y4;} 
	}                                                                         
	else if(i == 5 && b[i] == 0) {c[y1]++; c[y2] += 2; c[y3]++;  
	if(c[y1]%10 == 0) {m++;d[v++] = y1;} 
	if(c[y3]%10 == 0) {m++;d[v++] = y3;} if(c[y2]%10 == 0) {m++;d[v++] = y2;}
	}                                                                        
	else if((i == 4 && b[i] == 3) || (b[i] == 1 && (i == 3 || i == 2))){c[y2] += 2; c[y1]++; c[y4]++;      
	if(c[y1]%10 == 0) {m++;d[v++] = y1;} if(c[y2]%10 == 0) {m++;d[v++] = y2;}
	if(c[y4]%10 == 0) {m++;d[v++] = y4;}
	}                                                                 
	else if(i == 6 && b[i] == 0) {c[y1] += 2; c[y3]++; c[y2]++;
	if(c[y2]%10 == 0) {m++;d[v++] = y2;}
	if(c[y3]%10 == 0) {m++;d[v++] = y3;} if(c[y1]%10 == 0) {m++;d[v++] = y1;} 
	}                                                                 
	else if(i == 5 && b[i] == 1) {c[y1] += 3; c[y3]++;
	if(c[y3]%10 == 0) {m++;d[v++] = y3;} if(c[y1]%10 == 0) {m++;d[v++] = y1;}    
	}                                                                  
	else if(i == 6 && b[i] == 1) {c[y1]++; c[y3] += 3;
	if(c[y1]%10 == 0) {m++;d[v++] = y1;} if(c[y3]%10 == 0) {m++;d[v++] = y3;}  
	}                                                                  
	else if(i == 4 && b[i] == 1) {c[y1] += 2; c[y2]++; c[y4]++;
	if(c[y2]%10 == 0) {m++;d[v++] = y2;} if(c[y1]%10 == 0) {m++;d[v++] = y1;} 
	if(c[y4]%10 == 0) {m++;d[v++] = y4;}  
	}                                                           
	else if(i == 4 && b[i] == 2) {c[y1] += 3; c[y2]++;
	if(c[y2]%10 == 0) {m++;d[v++] = y2;} if(c[y1]%10 == 0) {m++;d[v++] = y1;} 
	}                                                     
	else if(i <= 3) {c[y2] += 2; c[y4] += 2;
	if(c[y2]%10 == 0) {m++;d[v++] = y2;} if(c[y4]%10 == 0) {m++;d[v++] = y4;}
	}                                              
	else{c[y1] += 3; c[y4]++;
	if(c[y1]%10 == 0) {m++;d[v++] = y1;} if(c[y4]%10 == 0) {m++;d[v++] = y4;}
	}
	if(m == 0) ;
	else if(m == 1) n += 20;
	else if(m == 2) n += 50;
	else if(m == 3) n += 90;
	else n += 140;
	clear();
	d[0]=d[1]=d[2]=d[3]=0;
	m = 0;
} 

void move()
{
	static char di = '0';
	while(flag)
	{
		de();
		y1++; y2++; y3++; y4++;
		draw();
		if(kbhit()!=0)
		   	di=getch();
		switch(di)
		{
	   	case 'a': left(); di = '0'; break;
	   	case 'd': right(); di = '0'; break;
	   	case 'w': change(); di = '0'; break;
	   	case 's': x9 = 1; di = '0'; break;
	    }	
		if(comepare(x1, x2, x3, x4, y1, y2, y3, y4))
			{
				flag = 0;
				x9 = 0;
				shuzu();
			}
		if(x9) Sleep(10);
		else if(x10 <= 20) Sleep(600);
		else if(x10 <= 40) {Sleep(450); level = 2;}
		else if(x10 <= 60) {Sleep(300); level = 3;} 
		else if(x10 <= 85) {Sleep(150); level = 4;}
		else {Sleep(100); level = 5;} 
		move(); 
	}
}

int main()
{
	//srand(time(NULL));
	//k = rand()%7; 
	wall(); 
	while(tag)
	{
		x10++; 
		init();
		move();
		flag = 1;
		if(s[8][2] == 1 || s[10][2] == 1 || s[12][2] == 1 || s[14][2] == 1)
		{
			gotoxy(8, 10);
			printf("GAME OVER!");
			tag = 0;
	 	}
		 gotoxy(M, N);  
	} 
	return 0;
 } 
