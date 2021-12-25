/*
* 1. ���̵��
* - 2�� �ݺ����� ���� BFS�� �����Ͽ� ���� Ž��
* - BFS �Լ��� ȣ��� �� ���� Count�� �������� ���� ���� ���
* - BFS�� �����԰� ���ÿ� �湮�� ���� 0���� �ʱ�ȭ ���������ν� ���� �ʱ�ȭ �۾��� ������ �ʿ� ����
*
* 2. �ð� ���⵵
* - V = w * h(1 ~ 50)
* - E = 8V
* - O(V + E) = O(V + 8V) = O(9V) = O(22,500) < 2��
*
* 3. ��� ����
* - int : ������ �ʺ�� ����, ���� ����
* - int[][] : ������ ���¸� �����ϱ� ���� 2���� �迭
* - int[] : ��ǥ�󿡼� ��, ��, ��, ��, �밢������ �̵��ϱ� ���� 1���� �迭
* - queue : BFS�� �����ϱ� ����
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 50

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int w, h;
int map[MAX][MAX];
queue<pair<int, int>> que;

void input()
{
	cin >> w >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> map[i][j];
}

void BFS(int y, int x)
{
	que.push({ y, x });
	map[y][x] = 0;

	while (!que.empty())
	{
		int yy = que.front().first;
		int xx = que.front().second;
		que.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

			if (map[ny][nx] == 1)
			{
				map[ny][nx] = 0;
				que.push({ ny, nx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int cnt = 0;

		input();
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 1)
				{
					BFS(i, j);
					++cnt;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}