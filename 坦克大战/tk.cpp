#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <conio.h>
#pragma comment (lib, "Winmm.lib")  //����������
#define NEMY_NUM 3


int map[26][26] = { //�����ͼ����
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
	UP,      //��
	DOWN,    //��
	LEFT,    //��
	RIGHT,   //��
};

//�ҷ�̹�˽ṹ��
struct tank_s {
	int x;  //̹���ڵ�ͼ���������ڵ� ��
	int y;  //̹���ڵ�ͼ���������ڵ� ��
	DIRECTTON dir;//̹�˵ķ���
	int live;//�Ƿ����� 1������ 2������
};


//�ӵ��ṹ��
struct bullet_s {
	int pos_x;  //�ӵ��ڡ�Ϸ̨���ϵĺ�����
	int pos_y;  //�ӵ��ڡ�Ϸ̨���ϵ�������
	DIRECTTON dire; //�ӵ��ķ���
	int status; //�ӵ���״̬
};





void menu();
void init_map();
void play();
int tank_walk(tank_s *tank, DIRECTTON dire, IMAGE *img, int step);
void set_prop_map(int x, int y, int val);
void bullet_action(bullet_s *bullet);
void enemy_catk(void);

int main(void) {

	initgraph(650, 650); //��ʼ��ͼ�ν��棬��С

	menu();              //��Ϸ��ʼ���� 
						
	init_map();			//��Ϸ����
	//init_map( &map[0][0], 26, 26);  

	play();             //�ҷ�̹��

	    

	system("pause");
	return 0 ;
}


/*************************************************
 *����̹�˰���Ӧ�ĵķ���ǰ��һ��
 *����ֵ ʧ��-0  �ɹ� --1
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

	setfillcolor(BLACK);                //����ǰ�����ڵ���ɫ
	solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);

	if (step ) {
		set_prop_map(nex_x, nex_y, 200);

		tank->x = nex_x;
		tank->y = nex_y;
	}
	putimage(tank->x * 25, tank->y * 25, img);


	return 1;
}

//ʵ����Ϸ����
void play() {
	bullet_s my_bullet;
	tank_s my_tank;                //̹�˽ṹ�����
	my_tank.x = 8;
	my_tank.y = 24;
	my_tank.live = 1;
	int i = 1;
	
	my_bullet.status = 0;       //�ӵ���ǰ������

	int key;
	IMAGE my_tank_img[4];           //����̹��ͼ�α���4��

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
			case 'a':  //̹�������ƶ�	
				if (my_tank.dir == LEFT &&(my_tank.x-1) >= 0 && map[my_tank.y][my_tank.x-1] == 0 && map[my_tank.y+1][my_tank.x-1] == 0) {
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.dir], 1);
				}
				else if(my_tank.dir != LEFT){
					my_tank.dir = LEFT;
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.dir], 0);
				}
				break; 
			case 'w':  //̹�������ƶ�
				if (my_tank.dir == UP && (my_tank.y - 1) >= 0 && map[my_tank.y-1][my_tank.x] == 0 && map[my_tank.y-1 ][my_tank.x+1] == 0) {
					
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.dir], 1);
				}
				else if (my_tank.dir != UP) {
					my_tank.dir = UP;
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 's':  //̹�������ƶ�
				if (my_tank.dir == DOWN &&(my_tank.y + 2) <= 25 && map[my_tank.y+2 ][my_tank.x] == 0 && map[my_tank.y+2][my_tank.x+1] == 0) {
					
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.dir], 1);

				} else if(my_tank.dir != DOWN){
					my_tank.dir = DOWN;
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 'd':  //̹�������ƶ�
				if (my_tank.dir == RIGHT &&(my_tank.x + 2) <=25 && map[my_tank.y][my_tank.x+2] == 0 && map[my_tank.y+1][my_tank.x+2] == 0) {
					
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.dir], 1);
				}
				else if (my_tank.dir != RIGHT) {
					my_tank.dir = RIGHT;
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.dir], 0);
				}
				break;
			case 'j':  //����
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
			case 'p':  //��ͣ
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
**�ӵ�������
 */

void bullet_action(bullet_s *bullet ) {

	int x,x1;
	int y,y1;  //�ӵ���ǰ�ڶ�ά�����е�����

	x = bullet->pos_x / 25;
	y = bullet->pos_y / 25;

	//1.������һ�εĻ��Ƶ��ӵ�
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);



	//2.���ݷ�������ӵ��ڡ�Ϸ̨���ϵ�����

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

	//��ײ���
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

	//3.���»����ӵ�
	if (bullet->status == 1) {
		setfillcolor(WHITE);
		solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);
	}
}

void menu() {  
	IMAGE logo_img;                     //����logͼ�α���

						                //��ȡͼ��(������ַ��ͼƬ·����ͼƬ��С)
	loadimage(&logo_img, _T("E:\\vs2015\\̹�˴�ս\\̹�˴�ս\\logo.bmp"), 432, 147);
	putimage(109, 20, &logo_img);       //��ʾͼ��

								        //ʵ�ֵ���
	setlinecolor(WHITE);                //���û��ߵ���ɫ
	setfillcolor(BLACK);                //����ǰ�����ڵ���ɫ

	fillrectangle(230, 200, 310, 240);  //��һ�����ο�ָ��x,y,x,y���꣩
	settextstyle(25, 0, _T("΢���ź�"));//��������Ĵ�С����ʽ���߶ȣ���ȣ�������ʽ��
	outtextxy(252, 207, _T("˵��"));    //��ָ��λ������ַ��� ��x,y,���� ���ַ�����


	fillrectangle(350, 200, 430, 240);
	settextstyle(25, 0, _T("΢���ź�"));
	outtextxy(372, 207, _T("��ʼ"));


	MOUSEMSG mouse;            //������һ�������Ϣ�ı���

	IMAGE illustrate_img;      // ����˵��ͼ�α���
	loadimage(&illustrate_img, _T("illustrate.jpg"), 300, 300);

	while (true) {
		mouse = GetMouseMsg(); //��ȡһ�ε�ǰ������Ϣ���ƶ��򰴼���
		switch (mouse.uMsg) {  //mouse.uMsg��굱ǰ��״̬(���ʵ���ƶ������ڰ���)
		case WM_MOUSEMOVE:     //windows�ĺ궨���ʾ������ƶ�
			if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
				putimage(150, 250, &illustrate_img); //��ʾ˵��ͼƬ
			}
			else {
               //����ǰ�����ڵ���ɫ
				solidrectangle(150, 250, 450, 550); //����һ��û�б߿��ͼƬ
			}
			break;

		case WM_LBUTTONDOWN:                       //windows�ĺ궨���ʾ��������Ϣ
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
	const int count = 4; //�ı��ͼ����ֵ�������ӥͼƬ����4�Σ�
	int i, j;
	IMAGE ing_home, ing_wall_1, ing_wall_2;

	loadimage(&ing_home, _T("home.jpg"), 50, 50);   //��ӥ
	loadimage(&ing_wall_1, _T("wall1.jpg"), 25, 25); //����������ǽ
	loadimage(&ing_wall_2, _T("wall2.jpg"), 25, 25); //��������ǽ

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
		
				set_prop_map(j, i, count);//��ӥ����һ������

			}
		}
	}

}

/*
//��ʼ����ͼ����������ǽΪ1����������Ϊ2����ӥ3��4��
void init_map(int *map_t_p,int tmp_t1,int tmp_t2) {
const int count = 4; //�ı��ͼ����ֵ
int i, j;
IMAGE ing_home, ing_wall_1, ing_wall_2;

loadimage(&ing_home, _T("home.jpg"), 50, 50);   //��ӥ
loadimage(&ing_wall_1, _T("wall1.jpg"), 25, 25); //����������ǽ
loadimage(&ing_wall_2, _T("wall2.jpg"), 25, 25); //��������ǽ

for (i = 0; i < tmp_t1; i++) {
for (j = 0; j < tmp_t2; j++) {
if (*(map_t_p + tmp_t1*i + j )  == 1) {
putimage(25 * j, 25 * i, &ing_wall_2);

}else if (*(map_t_p + tmp_t1*i + j ) == 2) {
putimage(25 * j, 25 * i, &ing_wall_1);

}else if (*(map_t_p + i + j) == 3) {
putimage(25 * j, 25 * i, &ing_home);
*(map_t_p + tmp_t1*i + j)            = count;      //����һ������
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
 * �з���̹��
 */
void enemy_catk(void) {
	tank_s enemy_tank[NEMY_NUM]; //�з�̹��
	bullet_s enemy_bullet[NEMY_NUM];//�з�̹�˷�����ӵ�

	IMAGE enemy_tank_img[4];
	//���صз�̹�˵�ͼƬ
	loadimage(&enemy_tank_img[UP], _T("enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[DOWN], _T("enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[LEFT], _T("enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[RIGHT], _T("enemy_tank_right.jpg"), 50, 50);

	//���õз�̹�˳�����λ��
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

	//ǰ3��̹�������ǳ�
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