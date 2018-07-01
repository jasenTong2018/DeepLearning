//#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 10;
struct node
{
	int x, y;
};
int t, m, n, num;
int matrix[maxn][maxn];
bool visit[maxn][maxn];
bool judge(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n)   return false;
	if (matrix[x][y] == 1 || visit[x][y] == true)    return false;
	return true;
}
int X[4] = { 0,0,1,-1 };
int Y[4] = { 1,-1,0,0 };
int dfs(int x, int y)
{
	if (x == m - 1 && y == n - 1)
	{
		num++;
	}
	if (judge(x, y) == true)
	{		visit[x][y]=true;
			for(int i=0;i<4;i++){
				dfs(x+X[i],y+Y[i]);
				visit[x+X[i]][y+Y[i]]=false;
			}
			visit[x][y]=false;
		
	}
	return num;
}
int main()
{
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &matrix[i][j]);
		num = 0;
		printf("%d\n", dfs(0, 0));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = 0;
			}
	}
	return 0;
}
