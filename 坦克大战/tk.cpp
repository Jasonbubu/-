#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <conio.h>
#pragma comment (lib, "Winmm.lib")  //导入声音库
#define NEMY_NUM 3


int map[26][26] = { //定义地图数组
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
	{ 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


enum DIRECTTON {
	UP,      //上
	DOWN,    //下
	LEFT,    //左
	RIGHT,   //右
};

//我方坦克结构体
struct tank_s {
	int x;  //坦克在地图数组中所在的 列
	int y;  //坦克在地图数组中所在的 行
	DIRECTTON dir;//坦克的方向，
	int live;//是否生存 1：活着 2：挂了
};


//子弹结构体
struct bullet_s {
	int pos_x;  //子弹在‘戏台’上的横坐标
	int pos_y;  //子弹在‘戏台’上的纵坐标
	DIRECTTON dire; //子弹的方向
	int status; //子弹的状态
};





void menu();
void init_map();
void play();
int tank_walk(tank_s *tank, DIRECTTON dire, IMAGE *img, int step);
void set_prop_map(int x, int y, int val);
void bullet_action(bullet_s *bullet);
void enemy_catk(void);

int main(void) {

	initgraph(650, 650); //初始化图形界面，大小

	menu();              //游戏开始界面 
						
	init_map();			//游戏界面
	//init_map( &map[0][0], 26, 26);  

	play();             //我方坦克

	    

	system("pause");
	return 0 ;
}


/*************************************************
 *控制坦克按相应的的方向前进一步
 *返回值 失败-0  成功 --1
*/

int tank_walk(tank_s *tank, DIRECTTON dire, IMAGE *img, int step) {

	int nex_x = tank->x;
	int nex_y = tank->y;

	if (step) {
		if (dire == UP) {
			nex_y -= 1;
		}
		else if (dire == DOWN) {
			nex_y += 1;
		}
		else if (dire == LEFT) {
			nex_x -= 1;
		}
		else if (dire == RIGHT) {
			nex_x += 1;
		}
		else {
			return 0;
		}
		set_prop_map(tank->x, tank->y, 0);
	}

	setfillcolor(BLACK);                //设则当前画框内的颜色
	solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);

	if (step ) {
		set_prop_map(nex_x, nex_y, 200);

		tank->x = nex_x;
		tank->y = nex_y;
	}
	putimage(tank->x * 25, tank->y * 25, img);


	return 1;
}

//实现游戏场景
void play() {
	bullet_s my_bullet;
	tank_s my_tank;                //坦克结构体变量
	my_tank.x = 8;
	my_tank.y = 24;
	my_tank.live = 1;
	int i = 1;
	
	my_bullet.status = 0;       //子弹当前不存在

	int key;
	IMAGE my_tank_img[4];           //定义坦克图形变量4个

	loadimage(&my_tank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("tank_right.jpg"), 50, 50);

	set_prop_map(my_tank.x, my_tank.y, 200);

	my_tank.dir = UP;
	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.dir]);
	
	while (true) {
		if (_kbhit()) {

			key = _getch();

			switch (key) {
			case 'a':  //坦克向左移动	
				if (my_tank.dir == LEFT &&(my_tank.x-1) >= 0 && map[my_tank.y][my_tank.x-1] == 0 && map[my_tank.y+1][my_tank.x-1] == 0) {
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.dir], 1);
				}
				else if(my_tank.dir != LEFT){
					my_tank.dir = LEFT;
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.dir], 0);
				}
				break; 
			case 'w':  //坦克向上移动
				if (my_tank.dir == UP && (my_tank.y - 1) >= 0 && map[my_tank.y-1][my_tank.x] == 0 && map[my_tank.y-1 ][my_tank.x+1] == 0) {
					
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.dir], 1);
				}
				else if (my_tank.dir != UP) {
					my_tank.dir = UP;
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 's':  //坦克向下移动
				if (my_tank.dir == DOWN &&(my_tank.y + 2) <= 25 && map[my_tank.y+2 ][my_tank.x] == 0 && map[my_tank.y+2][my_tank.x+1] == 0) {
					
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.dir], 1);

				} else if(my_tank.dir != DOWN){
					my_tank.dir = DOWN;
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 'd':  //坦克向右移动
				if (my_tank.dir == RIGHT &&(my_tank.x + 2) <=25 && map[my_tank.y][my_tank.x+2] == 0 && map[my_tank.y+1][my_tank.x+2] == 0) {
					
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.dir], 1);
				}
				else if (my_tank.dir != RIGHT) {
					my_tank.dir = RIGHT;
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 'j':  //开火
				if (my_bullet.status == 0) {
					//PlaySound(_T("paoji.wav"), NULL, SND_FILENAME | SND_ASYNC); 
					if (my_tank.dir == UP) {
						my_bullet.pos_x = my_tank.x * 25 + 23;
						my_bullet.pos_y = my_tank.y * 25 - 3;
					}
					else if (my_tank.dir ==	LEFT) {
						my_bullet.pos_x = my_tank.x * 25 - 3;
						my_bullet.pos_y = my_tank.y * 25 +23;
					}
					else if (my_tank.dir == DOWN) {
						my_bullet.pos_x = my_tank.x * 25 + 23;
						my_bullet.pos_y = my_tank.y * 25 + 50;
					}
					else if (my_tank.dir == RIGHT) {
						my_bullet.pos_x = my_tank.x * 25 + 50;
						my_bullet.pos_y = my_tank.y * 25 + 23;
					}

					my_bullet.dire = my_tank.dir;
					my_bullet.status = 1;
				}
				break;
			case 'p':  //暂停
				system("pause");
				break;
			default:
				break; 

			}
		}

		if (my_bullet.status == 1) {

			bullet_action(&my_bullet);
		}

		if (i < 2) {
			enemy_catk();
		}
		Sleep(100);

	}

}

/************************
**子弹的运行
 */

void bullet_action(bullet_s *bullet ) {

	int x,x1;
	int y,y1;  //子弹当前在二维数组中的坐标

	x = bullet->pos_x / 25;
	y = bullet->pos_y / 25;

	//1.擦除上一次的绘制的子弹
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);



	//2.根据方向计算子弹在‘戏台’上的坐标

	if (bullet->dire == UP) {
		bullet->pos_y -= 2;
		x1 = x + 1;
		y1 = y;
	}
	else if (bullet->dire == DOWN) {
		bullet->pos_y += 2;
		x1 = x + 1;
		y1 = y;
	}
	else if (bullet->dire == LEFT) {
		bullet->pos_x -= 2;
		x1 = x;
		y1 = y + 1;
	}
	else if (bullet->dire == RIGHT) {
		bullet->pos_x += 2;
		x1 = x;
		y1 = y + 1;
	}
	else {
		return;
	}

	if((bullet->pos_x < 0 || bullet->pos_x > 650) || (bullet->pos_y < 0 || bullet->pos_y > 650 )){
		bullet->status = 0;
		return ;
	}

	//碰撞检查
	if (map[y][x] == 4 || map[y1][x1] == 4) {
		return;
	}

	if (map[y][x] == 1) {
		map[y][x] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x * 25, y * 25, x * 25 + 25, y * 25 + 25);
	}
	else if (map[y][x] == 2) {
		bullet->status = 0;
	}

	if (map[y1][x1] == 1) {
		map[y1][x1] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
	}
	else if (map[y1][x1] == 2) {
		bullet->status = 0;
	}

	//3.重新绘制子弹
	if (bullet->status == 1) {
		setfillcolor(WHITE);
		solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);
	}
}

void menu() {  
	IMAGE logo_img;                     //定义log图形变量

						                //获取图像(变量地址，图片路径，图片大小)
	loadimage(&logo_img, _T("E:\\vs2015\\坦克大战\\坦克大战\\logo.bmp"), 432, 147);
	putimage(109, 20, &logo_img);       //显示图形

								        //实现导航
	setlinecolor(WHITE);                //设置画线的颜色
	setfillcolor(BLACK);                //设则当前画框内的颜色

	fillrectangle(230, 200, 310, 240);  //画一个矩形框（指定x,y,x,y坐标）
	settextstyle(25, 0, _T("微软雅黑"));//设置字体的大小和样式（高度，宽度，字体样式）
	outtextxy(252, 207, _T("说明"));    //在指定位置输出字符串 （x,y,坐标 ；字符串）


	fillrectangle(350, 200, 430, 240);
	settextstyle(25, 0, _T("微软雅黑"));
	outtextxy(372, 207, _T("开始"));


	MOUSEMSG mouse;            //定义了一个鼠标消息的变量

	IMAGE illustrate_img;      // 定义说明图形变量
	loadimage(&illustrate_img, _T("illustrate.jpg"), 300, 300);

	while (true) {
		mouse = GetMouseMsg(); //获取一次当前鼠标的消息（移动或按键）
		switch (mouse.uMsg) {  //mouse.uMsg鼠标当前的状态(鼠标实在移动或者在按键)
		case WM_MOUSEMOVE:     //windows的宏定义表示鼠标在移动
			if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
				putimage(150, 250, &illustrate_img); //显示说明图片
			}
			else {
               //设则当前画框内的颜色
				solidrectangle(150, 250, 450, 550); //绘制一个没有边框的图片
			}
			break;

		case WM_LBUTTONDOWN:                       //windows的宏定义表示鼠标左键消息
			if ((mouse.x > 350 && mouse.x < 430) && (mouse.y > 200 && mouse.y < 240)) {

				cleardevice();
				return ;
			}
		}

	}

}

void set_prop_map(int x, int y, int val) {

	map[y][x] = val;
	map[y][x+1] = val;
	map[y+1][x] = val;
	map[y+1][x+1] = val;

}


void init_map() {
	const int count = 4; //改变地图数组值（解决老鹰图片加载4次）
	int i, j;
	IMAGE ing_home, ing_wall_1, ing_wall_2;

	loadimage(&ing_home, _T("home.jpg"), 50, 50);   //老鹰
	loadimage(&ing_wall_1, _T("wall1.jpg"), 25, 25); //不可消除的墙
	loadimage(&ing_wall_2, _T("wall2.jpg"), 25, 25); //可消除的墙

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			if (map[i][j] == 1) {
				putimage(25 * j, 25 * i, &ing_wall_2);

			}
			else if (map[i][j] == 2) {
				putimage(25 * j, 25 * i, &ing_wall_1);

			}
			else if (map[i][j] == 3) {
				putimage(25 * j, 25 * i, &ing_home);
		
				set_prop_map(j, i, count);//老鹰加载一次运算

			}
		}
	}

}

/*
//初始化地图；可消除的墙为1；不可消除为2；老鹰3，4；
void init_map(int *map_t_p,int tmp_t1,int tmp_t2) {
const int count = 4; //改变地图数组值
int i, j;
IMAGE ing_home, ing_wall_1, ing_wall_2;

loadimage(&ing_home, _T("home.jpg"), 50, 50);   //老鹰
loadimage(&ing_wall_1, _T("wall1.jpg"), 25, 25); //不可消除的墙
loadimage(&ing_wall_2, _T("wall2.jpg"), 25, 25); //可消除的墙

for (i = 0; i < tmp_t1; i++) {
for (j = 0; j < tmp_t2; j++) {
if (*(map_t_p + tmp_t1*i + j )  == 1) {
putimage(25 * j, 25 * i, &ing_wall_2);

}else if (*(map_t_p + tmp_t1*i + j ) == 2) {
putimage(25 * j, 25 * i, &ing_wall_1);

}else if (*(map_t_p + i + j) == 3) {
putimage(25 * j, 25 * i, &ing_home);
*(map_t_p + tmp_t1*i + j)            = count;      //加载一次运算
*(map_t_p + tmp_t1*i + (j+1))     = count;
*(map_t_p + tmp_t1*(i+1) + j)     = count;
*(map_t_p + tmp_t1*(i+1) + (j+1)) = count;

}
}
}
system("pause");
}

*/
/*************************************
 * 敌方的坦克
 */
void enemy_catk(void) {
	tank_s enemy_tank[NEMY_NUM]; //敌方坦克
	bullet_s enemy_bullet[NEMY_NUM];//敌方坦克发射的子弹

	IMAGE enemy_tank_img[4];
	//加载敌方坦克的图片
	loadimage(&enemy_tank_img[UP], _T("enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[DOWN], _T("enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[LEFT], _T("enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[RIGHT], _T("enemy_tank_right.jpg"), 50, 50);

	//设置敌方坦克出场的位置
	for (int i = 0; i<NEMY_NUM; i++) {
		if (i % 3 == 0) {
			enemy_tank[i].x = 0;
		}
		else if (i % 3 == 1) {
			enemy_tank[i].x = 12;
		}
		else if (i % 3 == 2) {
			enemy_tank[i].x = 24;
		}
		enemy_tank[i].dir = DOWN;
		enemy_tank[i].y = 0;
		enemy_tank[i].live = 1;
		set_prop_map(enemy_tank[i].x, enemy_tank[i].y, 100 + i);
		enemy_bullet[i].status = 0;  

	}

	//前3辆坦克闪亮登场
	tank_walk(&enemy_tank[0], DOWN, &enemy_tank_img[DOWN], 0);
	tank_walk(&enemy_tank[1], DOWN, &enemy_tank_img[DOWN], 0);
	tank_walk(&enemy_tank[2], DOWN, &enemy_tank_img[DOWN], 0);
}


/*
void enemy_catk(void) {

	tank_s enemy_tk;
	bullet_s enemy_bullet;

	enemy_tk.x = 12;
	enemy_tk.y = 0;
	enemy_tk.live = 1;

	enemy_bullet.status = 0;

	IMAGE enemy_tank_img[4];
	
	loadimage(&enemy_tank_img[UP], _T("enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[DOWN], _T("enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[LEFT], _T("enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[RIGHT], _T("enemy_tank_right.jpg"), 50, 50);


	set_prop_map(enemy_tk.x, enemy_tk.y, 300);
	enemy_tk.dir = DOWN;
	//putimage(enemy_tk.y * 25, enemy_tk.y* 25, &enemy_tank_img[enemy_tk.dir]);

	

		if (map[enemy_tk.y + 2][enemy_tk.x] == 0 && map[enemy_tk.y + 2][enemy_tk.x + 1] == 0 && enemy_tk.y < 26) {
			enemy_tk.dir = DOWN;
			tank_walk(&enemy_tk, DOWN, &enemy_tank_img[enemy_tk.dir], 1);
		}
		else if (map[enemy_tk.y ][enemy_tk.x+1] == 0 && map[enemy_tk.y + 1][enemy_tk.x + 1] == 0 && enemy_tk.x >=0) {
			enemy_tk.dir = LEFT;
			tank_walk(&enemy_tk, LEFT, &enemy_tank_img[enemy_tk.dir], 1);

		}
		else if (map[enemy_tk.y][enemy_tk.x + 2] == 0 && map[enemy_tk.y + 1][enemy_tk.x + 2] == 0 && enemy_tk.x < 26) {
			enemy_tk.dir = RIGHT;
			tank_walk(&enemy_tk, RIGHT, &enemy_tank_img[enemy_tk.dir], 1);

		}
	


}
*/