#include <stdio.h>
#include <math.h>
struct Dot
{
	int x;
	int y;
	float angle;
};

int top = -1;
struct Dot point[100];
struct Dot stk[100];
void sort(int n);
void graham(int n);
float CalAngle(struct Dot a, struct Dot b);
void push(struct Dot a);
void pop();
int ccw(struct Dot a, struct Dot b, struct Dot c);
float CalDis(struct Dot a, struct Dot b);

void main()
{
	int n;
	float result = 8;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	int min = 999;
	int index;
	
	//find the leftmost point with minimum y-coordinate
	for (int i = 0; i < n; i++)
	{
		if (min > point[i].y)
		{
			min = point[i].y;
			index = i;
		}
		else if (min == point[i].y)
		{
			if (point[index].x > point[i].x)
				index = i;
		}
	}
	//Calculate angle the leftmost point with the minimum y-coordinate and another point 
	for (int i = 0; i < n; i++)
	{
		point[i].angle = CalAngle(point[index], point[i]);
	}

	sort(n);
	graham(n);

	//Calculate the total distance
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			result = result + CalDis(stk[i], stk[0]);
		else
			result = result + CalDis(stk[i], stk[i + 1]);
	}
	printf("%0.2f", result);
}
void sort(int n)
{
	
	struct Dot temp;
	//sorting ascendingorder by angle
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (point[j].angle > point[j + 1].angle)
			{
				temp = point[j];
				point[j] = point[j + 1];
				point[j + 1] = temp;
			}
		}
	}

}
//Find all porint the makes the shortes path
void graham(int n)
{
	push(point[0]);
	push(point[1]);
	push(point[2]);

	for (int i = 3; i < n; i++)
	{
		while (ccw(point[top - 1], point[top], point[i]) < 0)
			pop();
		push(point[i]);
	}

}
//Calculate angle
float CalAngle(struct Dot a, struct Dot b)
{
	int dx, dy;
	float angle;

	dx = b.x - a.x;
	dy = b.y - a.y;


	if (dx >= 0 && dy == 0)
		angle = 0;
	else
	{
		angle = abs(dy) / (abs(dx) + abs(dy));

		if (dx < 0 && dy >= 0)
			angle = 2 - angle;
		else if (dx <= 0 && dy < 0)
			angle = 2 + angle;
		else if (dx > 0 && dy < 0)
			angle = 4 - angle;
	}

	return angle * 90.0;

}
//push in array str
void push(struct Dot a)
{
	stk[++top] = a;

}
//pop top in array str
void pop()
{
	top--;
}
//check the counterclickwise
int ccw(struct Dot a, struct Dot b, struct Dot c)
{
	int result = (a.x * b.y) + (b.x * c.y) + (c.x * a.y);
	result = result - ((a.y * b.x) + (b.y * c.x) + (c.y * a.x));
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	else
		return 0;
}
//Calculate distance between a and b
float CalDis(struct Dot a, struct Dot b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}