#include <DxLib.h>
#include "Event.h"
#include "Object.h"

int Event::color = GetColor(102,255,255);

void Event::point(int x, int y, int diffX, int diffY){
	DrawBox(x + diffX*32, y + diffY*32, x + (diffX+1)*32, y + (diffY+1)*32, color, true);
}

void Event::spotReachTo(int x, int y, int n){
	for(int m = 0; m < n; m++){
		point(x, y, -n+m,   -m);
		point(x, y,    m, -n+m);
		point(x, y,  n-m,    m);
		point(x, y,   -m,  n-m);
	}
}

void Event::spotAround(int x, int y){
	spotReachTo(x, y, 1);
	point(x, y, -1, -1);
	point(x, y,  1, -1);
	point(x, y, -1,  1);
	point(x, y,  1,  1);
}

void Event::range(int x, int y, int n){
	for(; n > 0; n--){
		spotReachTo(x, y, n);
	}
}


void Event::rangeInField(int x, int y, int n){
	
	//���ɂ͂ݏo���Ȃ�(���g�̗���܂�)
	for(int sleftline = n; sleftline >= 0; sleftline--){
		int judge = (x-100)/32 - sleftline;
		if( judge >= 0){		//������0��ڈȏ�
				
			//��ɂ͂ݏo���Ȃ�(���̍s���܂�)
			for(int supline = n - sleftline; supline >= 0; supline--){
				int upperjudge = (y-100)/32 - supline;
				if( upperjudge >= 0){		//�ォ��0��ڈȏ�
					point(100, 100, judge, upperjudge);
				}
			}
			//���ɂ͂ݏo���Ȃ�(���̍s�͊܂܂Ȃ�)
			for(int sunderline = n - sleftline; sunderline > 0 ; sunderline--){
				int underjudge = (y-100)/32 + sunderline;
				if( underjudge <= 8){		//	�ォ��8��ڈȉ�
					point(100, 100, judge, underjudge);
				}
			}
			
		}
	}

	//�E�ɂ͂ݏo���Ȃ�(���g�̗���܂܂Ȃ�)
	for(int srightline = 1; srightline <= n; srightline++){
		int judge = (x-100)/32 + srightline;
		if( judge <= 8){		//	������8��ڈȉ�			
			//��ɂ͂ݏo���Ȃ�(���̍s���܂�)
			for(int supline = n - srightline; supline >= 0; supline--){
				int upperjudge = (y-100)/32 - supline;
				if( upperjudge >= 0){		//�ォ��0��ڈȏ�
					point(100, 100, judge, upperjudge);
				}
			}
			//���ɂ͂ݏo���Ȃ�(���̍s�͊܂܂Ȃ�)
			for(int sunderline = n - srightline; sunderline > 0 ; sunderline--){
				int underjudge = (y-100)/32 + sunderline;
				if( underjudge <= 8){		//	������8��ڈȉ�
					point(100, 100, judge, underjudge);
				}
			}
		}
	}
	
}

void Event::lineFour(int x, int y){
	for(int i = 0; i < 9; i++) {
		if(x == 100 + i*32)
			for(int j = -1; j < 8; j++)
				point(x -i+j, y, -i+j+1, 0);
		if(y == 100 + i*32)
			for(int j = -1; j < 8; j++)
				point(x, y -i+j, 0, -i+j+1);
	}
}


void Event::lineFourInField(int x, int y, int n){
	
	//���ɂ͂ݏo���Ȃ�
	for(int sleftline = n; sleftline > 0; sleftline--){
		int judge = (x-100)/32 - sleftline;
		if( judge >= 0){		//������0��ڈȏ�
			point(100, y, judge, 0);
			//	break;
		}
	}



	//��ɂ͂ݏo���Ȃ�
	for(int supline = n; supline > 0; supline--){
		int judge = (y-100)/32 - supline;
		if( judge >= 0){		//�ォ��0��ڈȏ�
			point(x, 100, 0, judge);
			//	break;
		}
	}
	
	//�E�ɂ͂ݏo���Ȃ�
	for(int srightline = 1; srightline <= n; srightline++){
		int judge = (x-100)/32 + srightline;
		if( judge <= 8){		//	������8��ڈȉ�
			point(100, y, judge, 0);
			//	break;
		}
	}

	//���ɂ͂ݏo���Ȃ�
	for(int sunderline = 1; sunderline <= n; sunderline++){
		int judge = (y-100)/32 + sunderline;
		if( judge <= 8){		//	������8��ڈȉ�
			point(x, 100, 0, judge);
			//	break;
		}
	}


}