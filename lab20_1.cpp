#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect r1, Rect r2){
	double Area;
	if((r2.x > r1.x + r1.w || r1.x > r2.x + r2.w) || (r2.y < r1.y - r1.h || r1.y < r2.y - r2.h)) return 0;
	else{
		double ansr[2][2];
		ansr[0][0] = max(r1.x, r2.x);
		ansr[0][1] = min(r1.y, r2.y);
		ansr[1][0] = min(r1.x + r1.w, r2.x + r2.w);
		ansr[1][1] = max(r1.y - r1.h, r2.y - r2.h);

		Area = (ansr[1][0] - ansr[0][0]) * (ansr[0][1] - ansr[1][1]);
		return Area;
	}

}

int main(){
	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,1.2,2.5};	
	cout << overlap(R1,R2);	
	return 0;
}
