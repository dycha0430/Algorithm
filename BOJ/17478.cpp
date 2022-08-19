#include <iostream>
using namespace std;

int N;

void recursive_func(int n)
{
    if (n == 0)
        return;
    string under_bar = "";
    for (int i = 0; i < N - n; i++)
        under_bar += "____";
    cout << under_bar + "\"재귀함수가 뭔가요 ?\"" << endl;
    cout << under_bar + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
    cout << under_bar + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
    cout << under_bar + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
    recursive_func(n - 1);
    cout << under_bar + "라고 답변하였지." << endl;
}

int main() {
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;

    recursive_func(N);
    
    return 0;
}