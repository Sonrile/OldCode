//88 50 res for ipad
//100 61 res for pc
//https://www.cuemath.com/algebra/rotation-matrix/
#include <iostream>
#include <vector>
#include <cmath>
int xRes = 88; int yRes = 50;
int projector(std::vector<int> orig3DxList, std::vector<int> orig3DyList, std::vector<int> orig3DzList, std::vector<int> point1List, std::vector<int> point2List, int x, int y, int z, int xAngDif, int yAngDif);
std::vector<int> rotator(int px, int py, int pz, int camx, int camy, int camz, float cosXAngDif, float sinXAngDif, float cosYAngDif, float sinYAngDif);
int lineRenderer(std::vector<int> p1x, std::vector<int> p1y, std::vector<int> p2x, std::vector<int> p2y);
int boolToScreen(bool chars[999][999]);
int main()
{
	std::vector<int> x3DList(40, -10);
	std::vector<int> y3DList(40, -10);
	std::vector<int> z3DList(40, 10);
  
	//RECTANGULAR PRISM
	x3DList[0] = -10;
	x3DList[1] = 20;
	x3DList[2] = -10;
	x3DList[3] = 20;
	
	x3DList[4] = -10;
	x3DList[5] = 20;
	x3DList[6] = -10;
	x3DList[7] = 20;
	
	//—
	
	y3DList[0] = 20;
	y3DList[1] = 20;
	y3DList[2] = 10;
	y3DList[3] = 10;
	
	y3DList[4] = 20;
	y3DList[5] = 20;
	y3DList[6] = 10;
	y3DList[7] = 10;

	//—	
	
	z3DList[0] = 20;
	z3DList[1] = 20;
	z3DList[2] = 20;
	z3DList[3] = 20;
	
	z3DList[4] = 10;
	z3DList[5] = 10;
	z3DList[6] = 10;
	z3DList[7] = 10;
	
	//LEFTCUBE
	
	x3DList[8] = -20;
	x3DList[9] = -10;
	x3DList[10] = -20;
	x3DList[11] = -10;
	
	x3DList[12] = -20;
	x3DList[13] = -10;
	x3DList[14] = -20;
	x3DList[15] = -10;
	
	//—
	
	y3DList[8] = 10;
	y3DList[9] = 10;
	y3DList[10] = 0;
	y3DList[11] = 0;
	
	y3DList[12] = 10;
	y3DList[13] = 10;
	y3DList[14] = 0;
	y3DList[15] = 0;

	//—	
	
	z3DList[8] = 20;
	z3DList[9] = 20;
	z3DList[10] = 20;
	z3DList[11] = 20;
	
	z3DList[12] = 10;
	z3DList[13] = 10;
	z3DList[14] = 10;
	z3DList[15] = 10;
	
	//RIGHTCUBE
	
	x3DList[16] = 20;
	x3DList[17] = 30;
	x3DList[18] = 20;
	x3DList[19] = 30;
	
	x3DList[20] = 20;
	x3DList[21] = 30;
	x3DList[22] = 20;
	x3DList[23] = 30;
	
	//—
	
	y3DList[16] = 10;
	y3DList[17] = 10;
	y3DList[18] = 0;
	y3DList[19] = 0;
	
	y3DList[20] = 10;
	y3DList[21] = 10;
	y3DList[22] = 0;
	y3DList[23] = 0;

	//—	
	
	z3DList[16] = 20;
	z3DList[17] = 20;
	z3DList[18] = 20;
	z3DList[19] = 20;
	
	z3DList[20] = 10;
	z3DList[21] = 10;
	z3DList[22] = 10;
	z3DList[23] = 10;
	
	//LEFTTOPCUBE
	
	x3DList[24] = -10;
	x3DList[25] = 0;
	x3DList[26] = -10;
	x3DList[27] = 0;
	
	x3DList[28] = -10;
	x3DList[29] = 0;
	x3DList[30] = -10;
	x3DList[31] = 0;
	
	//—
	
	y3DList[24] = 0;
	y3DList[25] = 0;
	y3DList[26] = -10;
	y3DList[27] = -10;
	
	y3DList[28] = 0;
	y3DList[29] = 0;
	y3DList[30] = -10;
	y3DList[31] = -10;

	//—	
	
	z3DList[24] = 20;
	z3DList[25] = 20;
	z3DList[26] = 20;
	z3DList[27] = 20;
	
	z3DList[28] = 10;
	z3DList[29] = 10;
	z3DList[30] = 10;
	z3DList[31] = 10;
	
	//RIGHTCUBE
	
	x3DList[32] = 10;
	x3DList[33] = 20;
	x3DList[34] = 10;
	x3DList[35] = 20;
	
	x3DList[36] = 10;
	x3DList[37] = 20;
	x3DList[38] = 10;
	x3DList[39] = 20;
	
	//—
	
	y3DList[32] = 0;
	y3DList[33] = 0;
	y3DList[34] = -10;
	y3DList[35] = -10;
	
	y3DList[36] = 0;
	y3DList[37] = 0;
	y3DList[38] = -10;
	y3DList[39] = -10;

	//—	
	
	z3DList[32] = 20;
	z3DList[33] = 20;
	z3DList[34] = 20;
	z3DList[35] = 20;
	
	z3DList[36] = 10;
	z3DList[37] = 10;
	z3DList[38] = 10;
	z3DList[39] = 10;
	
	std::vector<int> point1List(60, 0);
	std::vector<int> point2List(60, 1);
	
	point1List[0] = 0;
	point2List[0] = 1;
	point1List[1] = 0;
	point2List[1] = 2;
	point1List[2] = 2;
	point2List[2] = 3;
	point1List[3] = 1;
	point2List[3] = 3;
	point1List[4] = 4;
	point2List[4] = 0;
	point1List[5] = 1;
	point2List[5] = 5;
	point1List[6] = 2;
	point2List[6] = 6;
	point1List[7] = 3;
	point2List[7] = 7;
	point1List[8] = 4;
	point2List[8] = 5;
	point1List[9] = 6;
	point2List[9] = 4;
	point1List[10] = 7;
	point2List[10] = 5;
	point1List[11] = 6;
	point2List[11] = 7;
	point1List[12] = 8;
	point2List[12] = 9;
	point1List[13] = 8;
	point2List[13] = 10;
	point1List[14] = 9;
	point2List[14] = 11;
	point1List[15] = 10;
	point2List[15] = 11;
	point1List[16] = 9;
	point2List[16] = 13;
	point1List[17] = 10;
	point2List[17] = 14;
	point1List[18] = 11;
	point2List[18] = 15;
	point1List[19] = 8;
	point2List[19] = 12;
	point1List[20] = 12;
	point2List[20] = 13;
	point1List[21] = 12;
	point2List[21] = 14;
	point1List[22] = 14;
	point2List[22] = 15;
	point1List[23] = 13;
	point2List[23] = 15;
	point1List[24] = 16;
	point2List[24] = 17;
	point1List[25] = 16;
	point2List[25] = 18;
	point1List[26] = 18;
	point2List[26] = 19;
	point1List[27] = 17;
	point2List[27] = 19;
	point1List[28] = 20;
	point2List[28] = 16;
	point1List[29] = 17;
	point2List[29] = 21;
	point1List[30] = 18;
	point2List[30] = 22;
	point1List[31] = 19;
	point2List[31] = 23;
	point1List[32] = 20;
	point2List[32] = 21;
	point1List[33] = 22;
	point2List[33] = 20;
	point1List[34] = 23;
	point2List[34] = 21;
	point1List[35] = 22;
	point2List[35] = 23;
	point1List[36] = 24;
	point2List[36] = 25;
	point1List[37] = 24;
	point2List[37] = 26;
	point1List[38] = 26;
	point2List[38] = 27;
	point1List[39] = 25;
	point2List[39] = 27;
	point1List[40] = 28;
	point2List[40] = 24;
	point1List[41] = 25;
	point2List[41] = 29;
	point1List[42] = 26;
	point2List[42] = 30;
	point1List[43] = 27;
	point2List[43] = 31;
	point1List[44] = 28;
	point2List[44] = 29;
	point1List[45] = 30;
	point2List[45] = 28;
	point1List[46] = 31;
	point2List[46] = 29;
	point1List[47] = 30;
	point2List[47] = 31;
	point1List[48] = 32;
	point2List[48] = 33;
	point1List[49] = 32;
	point2List[49] = 34;
	point1List[50] = 34;
	point2List[50] = 35;
	point1List[51] = 33;
	point2List[51] = 35;
	point1List[52] = 36;
	point2List[52] = 32;
	point1List[53] = 33;
	point2List[53] = 37;
	point1List[54] = 34;
	point2List[54] = 38;
	point1List[55] = 35;
	point2List[55] = 39;
	point1List[56] = 36;
	point2List[56] = 37;
	point1List[57] = 38;
	point2List[57] = 36;
	point1List[58] = 39;
	point2List[58] = 37;
	point1List[59] = 38;
	point2List[59] = 39;
	
	projector(x3DList, y3DList, z3DList, point1List, point2List, 0, 0, 0, 0, 0);
	return 0;
}

int projector(std::vector<int> orig3DxList, std::vector<int> orig3DyList, std::vector<int> orig3DzList, std::vector<int> point1List, std::vector<int> point2List, int x, int y, int z, int xAngDif, int yAngDif)
{

	std::vector<int> x3DList(orig3DxList.size(), 1);
	std::vector<int> y3DList(orig3DxList.size(), 1);
	std::vector<int> z3DList(orig3DxList.size(), 1);
	
	float sinX = sin((float)xAngDif * 3.14159265359 / 180);
	float cosX = cos((float)xAngDif * 3.14159265359 / 180);
	float sinY = sin((float)yAngDif * 3.14159265359 / 180);
	float cosY = cos((float)yAngDif * 3.14159265359 / 180);

	for(int n = 0; n < x3DList.size(); ++n)
	{
		std::vector<int> result = rotator(orig3DxList[n], orig3DyList[n], orig3DzList[n], -x, -y, -z, sinX, cosX, sinY, cosY);
		x3DList[n] = result[0];
		y3DList[n] = result[1];
		z3DList[n] = result[2];
	}

	short unsigned const int DFS = 35;
	std::vector<int> p1x(x3DList.size() + point1List.size());
	std::vector<int> p1y(x3DList.size() + point1List.size());
	std::vector<int> p2x(x3DList.size() + point1List.size());
	std::vector<int> p2y(x3DList.size() + point1List.size());
	
	for(short unsigned int n = 0; n < x3DList.size(); ++n)
	{	
		if(z3DList[n] + z > 0)
		{
		p1x[n] = xRes / 2 + (int)(((float)DFS / (z3DList[n] + z)) * (x3DList[n] + x)); //we add yRes / 2 and xRes / 2 to make the center of the screen 0,0
		p1y[n] = yRes / 2 + (int)(((float)DFS / (z3DList[n] + z)) * (y3DList[n] + y));
		p2x[n] = xRes / 2 + (int)(((float)DFS / (z3DList[n] + z)) * (x3DList[n] + x));
		p2y[n] = yRes / 2 + (int)(((float)DFS / (z3DList[n] + z)) * (y3DList[n] + y));
		}
		else
		{
		p1x[n] = 1000;
		p1y[n] = 1000;
		p2x[n] = 1000;
		p2y[n] = 1000;
		}
	}
	
	for(short unsigned int n = x3DList.size(); n < point1List.size() + x3DList.size(); ++n)
	{
		if(z3DList[point1List[n - x3DList.size()]] + z > 0)
		{
		p1x[n] = xRes / 2 + (int)(((float)DFS / (z3DList[point1List[n - x3DList.size()]] + z)) * (x3DList[point1List[n - x3DList.size()]] + x));
		p1y[n] = yRes / 2 + (int)(((float)DFS / (z3DList[point1List[n - x3DList.size()]] + z)) * (y3DList[point1List[n - x3DList.size()]] + y));
		
		p2x[n] = xRes / 2 + (int)(((float)DFS / (z3DList[point2List[n - x3DList.size()]] + z)) * (x3DList[point2List[n - x3DList.size()]] + x));
		p2y[n] = yRes / 2 + (int)(((float)DFS / (z3DList[point2List[n - x3DList.size()]] + z)) * (y3DList[point2List[n - x3DList.size()]] + y));
		}
		else
		{
		p1x[n] = 1000;
		p1y[n] = 1000;
		p2x[n] = 1000;
		p2y[n] = 1000;
		}
	}
	
	lineRenderer(p1x, p1y, p2x, p2y);
	
	int x2 = x;
	int y2 = y;
	int z2 = z;
	int xAngDif2 = xAngDif;
	int yAngDif2 = yAngDif;
	
	char m;
	int num;
	std::cin >> m;
	std::cin >> num;
	switch(m)
	{
		case 'w': case 'W':
		z2 -= num; break;
		
		case 'a': case 'A':
		x2 += num; break;
		
		case 's': case 'S':
		z2 += num; break;
		
		case 'd': case 'D':
		x2 -= num; break;
		
		case 'q': case 'Q':
		y2 += num; break;
		
		case 'e': case 'E':
		y2 -= num; break;
		
		case 'i': case 'I':
		xAngDif2 -= num; break;
		
		case 'j': case 'J':
		yAngDif2 -= num; break;
		
		case 'k': case 'K':
		xAngDif2 += num; break;
		
		case 'l': case 'L':
		yAngDif2 += num; break;

		case 'x': case 'X':
		if(num > 999)
		{
			std::cout << "The x size limit is 999. X size set to 999."; xRes = 999; break;
		}
		else
		{
			xRes = num; break;
		}
		
		case 'y': case 'Y':
		if(num > 999)
		{
			std::cout << "The y size limit is 999. Y size set to 999."; yRes = 999; break;
		}
		else
		{
			yRes = num; break;
		}

		case 'o': case 'O':
		std::cout << "xAngDif(up-down):" << xAngDif << "\nyAngDif(left-right):" << yAngDif << "\ncamX:" << x << "\ncamY:" << y << "\ncamZ: " << z << std::endl; break;

		case 'r': case 'R':
		x2 = 0; y2 = 0; z2 = 0; xAngDif2 = 0; yAngDif2 = 0; break;
		
		default: return 0;
	}
	projector(orig3DxList, orig3DyList, orig3DzList, point1List, point2List, x2, y2, z2, xAngDif2, yAngDif2);
	return 0;
}

std::vector<int> rotator(int px, int py, int pz, int camx, int camy, int camz, float sinXAngDif, float cosXAngDif, float sinYAngDif, float cosYAngDif)
{
    std::vector<int> result(3);
    float xDif = px - camx;
    float zDif = pz - camz;

    result[0] = camx + std::round(xDif * cosYAngDif - zDif * sinYAngDif);
    result[1] = py;
    result[2] = camz + std::round(xDif * sinYAngDif + zDif * cosYAngDif);
    
    float yDif = py - camy;
    zDif = result[2] - camz;
    
    result[1] = camy + std::round(yDif * cosXAngDif - zDif * sinXAngDif);
    result[2] = camz + std::round(yDif * sinXAngDif + zDif * cosXAngDif);
    
    return result;
}

int lineRenderer(std::vector<int> p1x, std::vector<int> p1y, std::vector<int> p2x, std::vector<int> p2y)
{
	bool bools[999] [999];
	for(short unsigned int y = 0; y < 999; ++y)
	{
		for(short unsigned int x = 0; x < 999; ++x)
		{
			bools[x][y] = 0;
		}
	}
	
	for( int n = 0; n < p1x.size(); ++n)
	{
		int xDif = (p1x[n] > p2x[n])? p1x[n] - p2x[n] : p2x[n] - p1x[n];
		int yDif = (p1y[n] > p2y[n])? p1y[n] - p2y[n] : p2y[n] - p1y[n];
		if(yDif > xDif)//yDif >
		{
			if(p1x[n] > p2x[n])
			{
				if(p1y[n] > p2y[n])
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < yDif; ++m)
				{
					int y = p2y[n] + m;
					int x = (int)(((float)(m)/yDif) * xDif) + p2x[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"one1";
				}
				}
				else
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < yDif; ++m)
				{
					int y = p1y[n] + m;
					int x = xDif - ((int)(((float)(m)/yDif) * xDif)) + p2x[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"one2";
				}
				}
			}
			else
			{
				if(p1y[n] > p2y[n])
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < yDif; ++m)
				{
					int y = p2y[n] + m;
					int x = xDif - ((int)(((float)(m)/yDif) * xDif)) + p1x[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"two1";
				}
				}
				else
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < yDif; ++m)
				{
					int y = p1y[n] + m;
					int x = (int)(((float)(m)/yDif) * xDif) + p1x[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"two2";
				}
				}
			}
		}
		else//Xdif >
		{
			if(p1y[n] > p2y[n])
			{
				if(p1x[n] > p2x[n])
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < xDif; ++m)
				{
					int x = p2x[n] + m;
					int y = (int)(((float)(m)/xDif) * yDif) + p2y[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"three1";
				}
				}
				else
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < xDif; ++m)
				{
					int x = p1x[n] + m;
					int y = yDif - (int)(((float)(m)/xDif) * yDif) + p2y[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"three2";
				}
				}
			}
			else
			{
				if(p1x[n] > p2x[n])
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < xDif; ++m)
				{
					int x = p2x[n] + m;
					int y = yDif - (int)(((float)(m)/xDif) * yDif) + p1y[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"four1";
				}
				}
				else
				{
				if(p1x[n] < xRes && p1x[n] > 0 && p1y[n] < yRes && p1y[n] > 0) bools[p1x[n]][p1y[n]] = 1;
				if(p2x[n] < xRes && p2x[n] > 0 && p2y[n] < yRes && p2y[n] > 0) bools[p2x[n]][p2y[n]] = 1;
				for(short unsigned int m = 0; m < xDif; ++m)
				{
					int x = p1x[n] + m;
					int y = (int)(((float)(m)/xDif) * yDif) + p1y[n];
					
					if(x < xRes && x > 0 && y < yRes && y > 0) bools[x][y]= 1;
					//std::cout <<"four2";
				}
				}
			}
		}
	}
	
	boolToScreen(bools);
	return 0;
}

int boolToScreen(bool bools[999][999])
{
	for(short unsigned int y = 0; y < yRes; ++y)
	{
		for(short unsigned int x = 0; x < xRes; ++x)
		{
			char c = ' ';
			if (bools[x][y]) c = '#';
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for(int n = 0; n < xRes * 2; ++n)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	return 0;
}
