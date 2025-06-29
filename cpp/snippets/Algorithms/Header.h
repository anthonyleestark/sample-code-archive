class point
{
	float x;
	float y;
public:
	point();
	point(float x, float y);
	void im();
	void ex();
	float getX() { return x; };
	float getY() { return y; };
	void setLocation(float a, float b);
	void translational(float tx, float ty);
	float computeDistance(point a);
	void rotateCenter_O(float a);
};

class triangle
{
	point A, B, C;
public:
	bool isTritangle();
	void setpoint(point a, point b, point c);
	void im();
	void ex();
	void translational(float tX, float tY);
	void rotateCenter_O(float a);
};


class CTimeSpan
{
	int h;
	int m;
	int s;
public:
	void im();
	void ex();
	void canChinh(); //căn chỉnh lại giờ cho đúng định dạng.

	CTimeSpan cong(CTimeSpan a);
	CTimeSpan tru(CTimeSpan a);
	bool bang(CTimeSpan a);
	bool khac(CTimeSpan a);
	bool lonHon(CTimeSpan a);
	bool lonHonHoacBang(CTimeSpan a);
	bool behon(CTimeSpan a);
	bool beHonHoacBang(CTimeSpan a);
};

class CDate
{
	DTools T;
	int day;
	int month;
	int year;
public:
	/*int getD() { return day; };
	int getM() { return month; };
	int getY() { return year; };
	void setD(int x) { day = x; };
	void setM(int x) { month = x; };
	void setY(int x) { year = x; };*/
	void im(); //ok
	void ex(); //ok
	CDate tru(CDate a);
	CDate tru(int DAY);
	CDate cong(int DAY);
	CDate truTru();
	CDate congCong();

};

class DTools // tools for date
{
	
public:

	bool isLeapYear(int y); //ok
	bool isDateValid(int d, int m, int y); //ok
	int findNumberDayOfMonth(int m, int y);//ok
	int findNumberDayToDateInYear(int d, int m, int y);//find number day from (dd/mm/yy)=(1/1/year_current) to date current
};
