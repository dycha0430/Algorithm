#include <iostream>
using namespace std;

int N;

void recursive_func(int n) {
	if (n == -1) return;

	string under_bar = "";
	for (int i = 0; i < N - n; i++) under_bar += "____";

	cout << under_bar + "\"����Լ��� ������?\"" << endl;
	if (n == 0) cout << under_bar + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
	else {
		cout << under_bar + "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
		cout << under_bar + "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
		cout << under_bar + "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	}

	recursive_func(n - 1);
	cout << under_bar + "��� �亯�Ͽ���." << endl;
}

int main() {
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;

	recursive_func(N);

	return 0;
}